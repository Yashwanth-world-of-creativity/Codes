// class Solution {
// public:
//     bool checkInclusion(string s1, string s2) {

//         int n1 = s1.size();
//         int n2 = s2.size();

//         if(n1 > n2) return false;

//         vector<int> freq1(26,0), freq2(26,0);

//         for(int i = 0; i < n1; i++){
//             freq1[s1[i]-'a']++;
//             freq2[s2[i]-'a']++;
//         }

//         if(freq1 == freq2) return true;

//         for(int i = n1; i < n2; i++){

//             freq2[s2[i]-'a']++;           
//             freq2[s2[i-n1]-'a']--;        

//             if(freq1 == freq2)
//                 return true;
//         }

//         return false;
//     }
// };


class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        unordered_map<char,int> mp;

        for(char c : s1)
            mp[c]++;

        int l = 0;
        int count = s1.size();

        for(int r = 0; r < s2.size(); r++){

            if(mp[s2[r]] > 0)
                count--;

            mp[s2[r]]--;

            if(count == 0)
                return true;

            if(r - l + 1 == s1.size()){

                if(mp[s2[l]] >= 0)
                    count++;

                mp[s2[l]]++;
                l++;
            }
        }

        return false;
    }
};
