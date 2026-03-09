class Solution {
public:
    bool isPalindrome(string s) {
        string pal="";
        for(int i=0;i<s.length();i++)
        if(isalnum(s[i])){
            pal+=tolower(s[i]);
        }
        string rev(pal.rbegin(),pal.rend());
        
        if(rev==pal){
            return true;
        }
        return false;
    }
};
