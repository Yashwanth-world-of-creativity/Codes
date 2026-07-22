class Solution {
public:
    int scoreOfString(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n-1;i++){
            int mx=abs(s[i]-s[i+1]);
            ans+=mx;
        }
        return ans;
    }
};
