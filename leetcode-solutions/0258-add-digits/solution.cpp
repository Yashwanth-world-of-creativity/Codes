class Solution {
public:
    int addDigits(int n) {
       int sum=0;
        if(n==0){
            return 0;
        }
        if(n%9==0){
            return 9;
        }
        else{
            sum=n%9;
        }
        return sum;
    }
};
