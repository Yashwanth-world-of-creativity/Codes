// class Solution {
// public:
//     int minimizedStringLength(string s) {
//         set<char>st;
//         for(char i:s){
//             st.insert(i);
//         }
//         return st.size();
//     }
// };

class Solution {
public:
    int minimizedStringLength(string s) {

        unordered_set<char> st;

        for (char ch : s) {

            st.insert(ch);
        }

        return st.size();
    }
};
