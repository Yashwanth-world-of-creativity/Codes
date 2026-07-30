class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        if(word.size()<=8) return word.size();
        for(int i=0;i<word.size();i++){
            ans+=(i/8)+1;
        }
        return ans;
    }
};

