class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        int first = -1, second = -1;

        for (int i = 0; i < s1.size(); i++) {

            if (s1[i] != s2[i]) {

                if (first == -1)
                    first = i;
                else if (second == -1)
                    second = i;
                else
                    return false;
            }
        }

        if (first == -1)
            return true;

        if (second == -1)
            return false;

        swap(s1[first], s1[second]);

        return s1 == s2;
    }
};
