class Solution {
public:
    bool sumGame(string num) {
        int leftsum=0;
        int rightsum=0;
        int n=num.size();
        int leftQmark=0;
        int rightQmark=0;
        for(int i=0;i<n;i++){
            if(num[i]=='?'){
                if(i<n/2) leftQmark++;
                else rightQmark++;
            }
            else{
                if(i<n/2) leftsum+=num[i]-'0';
                else  rightsum+=num[i]-'0';
            }
        }
        int total=leftQmark+rightQmark;
        if(total%2==1) return true; //last option is alice so obiuosly he will win 
        int LEFT= 2*leftsum+9*leftQmark; // max is 9 in here so bob will take k limit if alice take num x bob will take 9-x, finally u will get 4.5 multiple in order to keep it non deciomal multiply by 2 ;
        int Right=2*rightsum+ 9*rightQmark;
        if(LEFT==Right) return false;
        return true;
        
    }
};
