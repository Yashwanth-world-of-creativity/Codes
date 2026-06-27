// class Solution {
// public:
//     int maximumLength(vector<int>& nums) {
        
//     }
// };
//op
class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<long long, int> cnt;

        for (int x : nums) {
            cnt[x]++;
        }

        int ans = 1;

        if (cnt.count(1)) {
            int c = cnt[1];
            if (c % 2 == 0) c--;
            ans = max(ans, c);
        }

        for (auto &[x, f] : cnt) {

            if (x == 1) continue;

            long long cur = x;
            int len = 1;

            while (cnt[cur] >= 2) {

                if (cur > 1000000000LL / cur) break;

                long long nxt = cur * cur;

                if (!cnt.count(nxt))
                    break;

                len += 2;
                cur = nxt;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};
