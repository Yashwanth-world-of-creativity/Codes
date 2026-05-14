class Solution {
public:
    string makeGood(string s) {

        string res = "";

        for (char &i : s) {

            if (!res.empty() &&
                (res.back() - 32 == i ||
                 res.back() + 32 == i)) {

                res.pop_back();
            }
            else {

                res.push_back(i);
            }
        }

        return res;
    }
};
