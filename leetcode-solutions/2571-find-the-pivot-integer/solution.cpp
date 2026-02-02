class Solution {
public:
    int pivotInteger(int n) {
        int totalsum=n*(n+1)/2;
        int lefts=0;
        for(int i=1;i<=n;i++){
            lefts+=i;
            int rights=totalsum-lefts+i;
            if(lefts==rights){
                return i;
            }
        }
           return -1;
    }
   
};
