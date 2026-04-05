class Solution {
public:
    bool judgeCircle(string moves) {
        if(moves ==" ") return true;
        unordered_map<char,int>mp;
        for(int i=0;i<moves.length();i++){
            mp[moves[i]]++;
        }
        if(mp['U']==mp['D']&& mp['R']==mp['L']) return true;
        else return false;
    }
};
