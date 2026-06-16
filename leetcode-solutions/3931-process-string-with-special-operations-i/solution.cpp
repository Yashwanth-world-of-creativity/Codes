// class Solution {
// public:
//     string processStr(string s) {
        
//     }
// };
class Solution {
public:
    string processStr(string s) {

        string ans = "";

        for (char ch : s) {

            if (islower(ch)) {

                ans.push_back(ch);
            }

            else if (ch == '*') {

                if (!ans.empty()) {
                    ans.pop_back();
                }
            }

            else if (ch == '#') {

                ans += ans;
            }

            else if (ch == '%') {

                reverse(ans.begin(), ans.end());
            }
        }

        return ans;
    }
};
