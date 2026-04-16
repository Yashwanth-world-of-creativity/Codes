class Solution {
public:
    int countBinarySubstrings(string s) {
        int n=s.length();
        int result=0;
        int prevC=0;
        int currC=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                currC++;
            }
            else{
                result+= min(prevC,currC);
                prevC=currC;
                currC=1;
            }
        }
        return result+min(prevC,currC);
    }
};
