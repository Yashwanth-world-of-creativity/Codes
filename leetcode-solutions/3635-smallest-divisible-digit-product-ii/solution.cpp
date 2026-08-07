// class Solution {
// public:
//     string smallestNumber(string num, long long t) {
        

//     }
// };
class Solution {
public:
    // Divides `f` using digits 9..2 (most impactful first).
    // Since f only ever contains primes 2,3,5,7 (guaranteed once t is validated),
    // this always fully reduces f to 1.
    vector<int> extractDigits(long long f) {
        vector<int> digits;
        for (int d = 9; d >= 2; d--) {
            while (f % d == 0) {
                f /= d;
                digits.push_back(d);
            }
        }
        return digits; // f is now 1
    }

    // Builds the smallest suffix of exactly `freeSlots` digits that covers
    // the digits we extracted, padding leftover slots with '1' (no-op digit),
    // then reversing so the result is ascending (smallest arrangement).
    string freeSlotsFiller(vector<int>& digits, int freeSlots) {
        string built;
        for (int d : digits) built.push_back(char('0' + d));
        built.append(freeSlots - (int)digits.size(), '1');
        reverse(built.begin(), built.end());
        return built;
    }

    string smallestNumber(string num, long long t) {
        // Observation 1: t must only contain primes 2, 3, 5, 7
        long long check = t;
        for (int p : {2, 3, 5, 7}) while (check % p == 0) check /= p;
        if (check != 1) return "-1";

        int n = (int)num.size();

        // If t alone needs more digits than num has, answer must be longer.
        vector<int> minDigits = extractDigits(t);
        if ((int)minDigits.size() > n) {
            return freeSlotsFiller(minDigits, (int)minDigits.size());
        }

        // remainingFactor[i] = part of t still uncovered after fixing num[0..i-1]
        vector<long long> remainingFactor(n + 1);
        remainingFactor[0] = t;
        for (int i = 0; i < n; i++) {
            int d = num[i] - '0';
            long long g = (d == 0) ? remainingFactor[i] : __gcd(remainingFactor[i], (long long)d);
            remainingFactor[i + 1] = remainingFactor[i] / g;
        }

        int firstZeroIndex = n;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') { firstZeroIndex = i; break; }
        }

        // num itself already works
        if (firstZeroIndex == n && remainingFactor[n] == 1) {
            return num;
        }

        // Main greedy: scan right to left, bump the digit as late as possible
        for (int i = n - 1; i >= 0; i--) {
            if (i > firstZeroIndex) continue; // prefix would contain a zero digit

            long long need = remainingFactor[i];
            int freeSlots = n - 1 - i;

            for (int bd = num[i] - '0' + 1; bd <= 9; bd++) {
                long long g = __gcd(need, (long long)bd);
                long long need2 = need / g;

                vector<int> digits = extractDigits(need2);
                if ((int)digits.size() <= freeSlots) {
                    string suffix = freeSlotsFiller(digits, freeSlots);
                    return num.substr(0, i) + char('0' + bd) + suffix;
                }
            }
        }

        // No same-length answer -> smallest valid number of length n+1
        vector<int> digits = extractDigits(t);
        return freeSlotsFiller(digits, n + 1);
    }
};
