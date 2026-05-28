class Solution {
public:

    string getPattern(string &s) {

        string pattern = "";

        for (int i = 1; i < s.size(); i++) {

            pattern += to_string(s[i] - s[i - 1]) + ",";
        }

        return pattern;
    }

    string oddString(vector<string>& words) {

        unordered_map<string, int> mp;

        unordered_map<string, string> patternWord;

        for (string &word : words) {

            string pattern = getPattern(word);

            mp[pattern]++;

            patternWord[pattern] = word;
        }

        for (auto &it : mp) {

            if (it.second == 1) {

                return patternWord[it.first];
            }
        }

        return "";
    }
};
