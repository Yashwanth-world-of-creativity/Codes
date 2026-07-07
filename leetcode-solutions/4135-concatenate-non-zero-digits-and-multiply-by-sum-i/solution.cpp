class Solution {
public:
    long long sumAndMultiply(int n) {
       vector<int>digit;
       long long x=0;
       long long sum=0;
       while(n>0){
        int d=n%10;
        if(d!=0)
            digit.push_back(d);
            n=n/10;
        
       }
        reverse(digit.begin(),digit.end());
        for(int i=0;i<digit.size();i++){
            x=x*10+digit[i];
            sum+=digit[i];
        
       }
        return x*sum;
    }
};
