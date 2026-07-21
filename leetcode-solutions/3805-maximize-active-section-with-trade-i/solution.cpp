class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.length();
        //to count number of active ones 
        int activeBloacks= count(s.begin(),end(s),'1');
        vector<int>inactiveBlocks;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
               int  start=i;
                while(i<n && s[i]=='0') i++;
                inactiveBlocks.push_back(i-start);
            }
            else{
                i++;
            }
        }
            int maxActive=0; // maxPairsum
            for(int i=1;i<inactiveBlocks.size();i++){
                maxActive=max(maxActive,inactiveBlocks[i]+inactiveBlocks[i-1]); // like [1,3,3] we choose here 3+3=6
            }
        return maxActive+activeBloacks; 
    }
};
