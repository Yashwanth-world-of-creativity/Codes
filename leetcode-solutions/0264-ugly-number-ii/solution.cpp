class Solution {
public:
    int nthUglyNumber(int n) {
       vector<int>dp(n+1);
       int i2,i3,i5;
       i2=i3=i5=1;
       dp[1]=1;
       for(int i=2;i<=n;i++){
        int i2ugly= dp[i2]*2;
        int i3ugly= dp[i3]*3;
        int i5ugly= dp[i5]*5;
        int minUg=min({i2ugly,i3ugly,i5ugly});
        dp[i]=minUg; //checking for minimum
        if(minUg==i2ugly) i2++;
        if(minUg==i3ugly) i3++;
        if(minUg==i5ugly) i5++;
       } 
       return dp[n];
    }
};
