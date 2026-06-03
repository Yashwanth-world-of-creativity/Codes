class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {

        unordered_set<char> st(allowed.begin(), allowed.end());

        int count = 0;

        for (string &word : words) {

            bool ok = true;

            for (char ch : word) {

                if (!st.count(ch)) {

                    ok = false;
                    break;
                }
            }

            if (ok) {
                count++;
            }
        }

        return count;
    }
};
