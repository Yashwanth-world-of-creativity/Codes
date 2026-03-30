class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.length();
        int even[26]={0};
        int odd[26]={0};

        for(int i=0;i<n;i++){
           if(i%2==0){
            even[s1[i]-'a']++;
            even[s2[i]-'a']--;
           }  else{
            odd[s1[i]-'a']++;
            odd[s2[i]-'a']--;
           }
        }
        for(int i=0;i<26;i++){
            if(even[i]!=0||odd[i]!=0){
                return false;
            }
        }
        return true;
    }
};



// class Solution {
// public:
//     bool checkStrings(string s1, string s2) {
        
//         int n = s1.size();

//         vector<int> even1(26, 0), odd1(26, 0);
//         vector<int> even2(26, 0), odd2(26, 0);

//         for(int i = 0; i < n; i++){
//             if(i % 2 == 0){
//                 even1[s1[i] - 'a']++;
//                 even2[s2[i] - 'a']++;
//             } else {
//                 odd1[s1[i] - 'a']++;
//                 odd2[s2[i] - 'a']++;
//             }
//         }

//         return (even1 == even2) && (odd1 == odd2);
//     }
// };

//op
// class Solution {
// public:
//     static bool checkStrings(string& s1, string& s2) {
//         array<array<int, 26>, 2> freq{};
//         constexpr array<array<int, 26>, 2> zero{};
//         const int n=s1.size();
//         for(int i=0; i<n; i++){
//             bool iOdd=i&1;
//             freq[iOdd][s1[i]-'a']++;
//             freq[iOdd][s2[i]-'a']--;
//         }
//         return freq==zero;
//     }
// };

// auto init = []() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     return 'c';
// }();
