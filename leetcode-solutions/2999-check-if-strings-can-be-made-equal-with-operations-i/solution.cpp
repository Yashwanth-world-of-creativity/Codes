class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1.size() != s2.size()) return false;

        string a = "", b = "", c = "", d = "";

        // even indices
        a += s1[0]; a += s1[2];
        b += s2[0]; b += s2[2];

        // odd indices
        c += s1[1]; c += s1[3];
        d += s2[1]; d += s2[3];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        sort(d.begin(), d.end());

        return (a == b && c == d);
    }
};
