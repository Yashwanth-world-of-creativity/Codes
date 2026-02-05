class Solution {
public:
    int mySqrt(int x) {

        int l=0;
        long long r=x,ans=0;
        while(l<=r){
            long long  mid=l+(r-l)/2;
            long long temp=mid*mid;
            if(temp == x)
            return mid;
            else if (temp<x){
                ans=mid;
                l=mid+1;
            }
            else
            r=mid-1;
              
        }
    return ans;
    }

};
