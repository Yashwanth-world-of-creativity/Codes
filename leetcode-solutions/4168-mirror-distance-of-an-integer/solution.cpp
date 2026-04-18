class Solution {
public:
int reverse(int n){
    int rev=0;
    while(n>0){
        int rem=0;
        rem=n%10;
        rev=rev*10+rem;
        n/=10;
    }
    return rev;
}
    int mirrorDistance(int n) {
        if(n==1) return 0;
        int ans=0;
        ans= abs(n-reverse(n));
        return ans;
    }
};
