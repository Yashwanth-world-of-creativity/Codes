class Solution {
public:
    bool buddyStrings(string s, string goal) {

        if (s.size() != goal.size())
            return false;

        vector<int> diff;

        unordered_set<char> st;
        bool duplicate = false;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] != goal[i])
                diff.push_back(i);

            if (st.count(s[i]))
                duplicate = true;

            st.insert(s[i]);
        }

        if (diff.empty())
            return duplicate;

        if (diff.size() != 2)
            return false;

        return s[diff[0]] == goal[diff[1]] &&
               s[diff[1]] == goal[diff[0]];
    }
};
