class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        unordered_map<char,int> mp;

        for(char c : t)
            mp[c]++;

        int l = 0;
        int count = t.size();

        int start = 0;
        int minLen = INT_MAX;

        for(int r = 0; r < s.size(); r++){

            if(mp[s[r]] > 0)
                count--;

            mp[s[r]]--;

            while(count == 0){

                if(r - l + 1 < minLen){
                    minLen = r - l + 1;
                    start = l;
                }

                mp[s[l]]++;

                if(mp[s[l]] > 0)
                    count++;

                l++;
            }
        }

        if(minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};




// class Solution {
// public:
//     string minWindow(string s, string p){
//         int len1 = s.length();
//         int len2 = p.length();

//         if (len1 < len2)
//             return "";

//         vector<int> countP(256, 0);
//         vector<int> countS(256, 0);

//         // Store occurrence of characters of P
//         for (int i = 0; i < len2; i++)
//             countP[p[i]]++;

//         int start = 0, start_idx = -1, min_len = INT_MAX;

//         int count = 0;

//         for (int j = 0; j < len1; j++){
//             // Count occurrence of characters 
//             // of string S
//             countS[s[j]]++;

//             // If S's char matches with P's char,
//             // increment count
//             if (countP[s[j]] != 0 && countS[s[j]] <= countP[s[j]]){
//                 count++;
//             }

//             // If all characters are matched
//             if (count == len2){
//                 // Try to minimize the window
//                 while (countS[s[start]] > countP[s[start]] || 
//                     countP[s[start]] == 0){
//                     if (countS[s[start]] > countP[s[start]]){
//                         countS[s[start]]--;
//                     }
//                     start++;
//                 }

//                 // Update window size
//                 int len = j - start + 1;
//                 if (min_len > len){
//                     min_len = len;
//                     start_idx = start;
//                 }
//             }
//         }

//         if (start_idx == -1)
//             return "";

//         return s.substr(start_idx, min_len);
//     }

// };
