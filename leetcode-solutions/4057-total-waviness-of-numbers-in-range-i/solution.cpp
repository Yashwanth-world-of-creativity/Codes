class Solution {
public:
    int findwaves(int n){
        int count=0;
        string s = to_string(n);
        int l=s.length();
        if(l<3) return 0;
        for(int i=1;i<=l-2;i++){
            //peak
            if(s[i]>s[i-1]&&s[i]>s[i+1]) count++;
        
            //valley
            if(s[i]<s[i-1]&&s[i]<s[i+1]) count++;
        }
        return count;
    }
    int totalWaviness(int num1, int num2) {
        int count=0;
        for(int i=num1;i<=num2;i++){
            count+=findwaves(i);
        }
        return count;
    }
};
