class Solution {
public:
    int xorOperation(int n, int start) {
        int sum=0;
        while(n>0){
            sum=sum^start;
            start+=2;
            n--;
        }
        return sum;
    }
};
