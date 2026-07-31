class Solution {
public:
    int minimumPushes(string word) {
        vector<int>mp(26,0);
        for(char &ch:word){
            mp[ch-'a']++;
        }
        sort(mp.begin(),mp.end(),greater<int>());
        int result=0;
        for(int i=0;i<mp.size();i++){
            int freq=mp[i];
            int pre=(i/8)+1;
            result +=pre*freq;
        }
        return result;
    }
};
