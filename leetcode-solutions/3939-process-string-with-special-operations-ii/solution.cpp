// class Solution {
// public:
//     char processStr(string s, long long k) {
        
//     }
// };
class Solution {
public:
    char processStr(string s, long long k) {

        int n = s.size();

        vector<long long> len(n);

        long long cur = 0;

        for (int i = 0; i < n; i++) {

            char ch = s[i];

            if (islower(ch)) {
                cur++;
            }
            else if (ch == '*') {
                if (cur > 0) cur--;
            }
            else if (ch == '#') {
                cur *= 2;
            }
            else {
                // %
            }

            len[i] = cur;
        }

        if (k >= cur) {
            return '.';
        }

        for (int i = n - 1; i >= 0; i--) {

            char ch = s[i];

            if (islower(ch)) {

                if (k == len[i] - 1) {
                    return ch;
                }
            }
            else if (ch == '#') {

                long long oldLen = len[i] / 2;
                k %= oldLen;
            }
            else if (ch == '%') {

                k = len[i] - 1 - k;
            }
            else { // '*'

                long long oldLen = len[i] + 1;

                if (k == oldLen - 1) {
                    return '.';
                }
            }
        }

        return '.';
    }
};
