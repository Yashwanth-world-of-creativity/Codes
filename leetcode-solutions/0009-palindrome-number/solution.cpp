class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long org=x;
        long long rem,rev=0;
        while(x>0){
            rem=x%10;
            rev=rev*10+rem;
            x/=10;

            
        }
        if(rev==org){
            return true;
        }
        return false;
    }
};
