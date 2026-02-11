class Solution {
public:
    bool isValid(string s) {
        if(s[0]==')'||s[0]==']'||s[0]=='}')
        return false;
        stack<char> st;
        for(char &c:s){
            if(c=='('||c=='['||c=='{')
            st.push(c);
            else{
                if(st.empty()) return false;
                char temp=st.top();
                if(c==')'&&temp=='('||c=='}'&&temp=='{'||c==']'&&temp=='[')
                st.pop();
                else
                return false;
            }
        }
        return st.empty();

//         int count1 = 0, count2 = 0, count3 = 0;

//         for(char ch : s){
            
//             // round brackets
//             if(ch == '(') count1++;
//             else if(ch == ')') count1--;
            
//             // square brackets
//             else if(ch == '[') count2++;
//             else if(ch == ']') count2--;
            
//             // curly brackets
//             else if(ch == '{') count3++;
//             else if(ch == '}') count3--;
            
//             // if any count becomes negative → invalid
//             if(count1 < 0 || count2 < 0 || count3 < 0)
//                 return false;
//         }

//         // all counts must be zero at end
//         return (count1 == 0 && count2 == 0 && count3 == 0);
    }
};
