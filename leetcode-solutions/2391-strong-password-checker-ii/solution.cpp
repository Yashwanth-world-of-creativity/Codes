// class Solution {
// public:
//     bool strongPasswordCheckerII(string password) {

//         if(password.length() < 8)
//             return false;

//         bool lower=false, upper=false, digit=false, special=false;

//         for(int i=0;i<password.length();i++) {

//             char curr = password[i];

//             if(islower(curr)) lower = true;
//             if(isupper(curr)) upper = true;
//             if(isdigit(curr)) digit = true;

//             if(curr=='!'||curr=='@'||curr=='#'||curr=='$'||
//                curr=='%'||curr=='^'||curr=='&'||curr=='*'||
//                curr=='('||curr==')'||curr=='-'||curr=='+')
//                 special = true;

//             if(i>0 && password[i]==password[i-1])
//                 return false;
//         }

//         return lower && upper && digit && special;
//     }
// };

//simple and effective code
// class Solution {
// public:
//     bool strongPasswordCheckerII(string password) {
//         int n = password.size();
//         if(n < 8) return false;

//         bool a = false, b = false, c = false, d = false;
//         for(int i=0; i<n; i++) {
//             char ch = password[i];
//             if(i != 0) {
//                 if(ch == password[i-1]) return false;
//             }

//             if(ch >= 'a' && ch <= 'z') a = true;
//             else if(ch >= 'A' && ch <= 'Z') b = true;
//             else if(ch >= '0' && ch <= '9') c = true;
//             else if(ch >= '!' || ch >= '@' || ch >= '#' || ch >= '$' || ch >= '%' || ch >= '^' || ch >= '&' || ch >= '*' || ch >= '(' || ch >= ')' || ch >= '-' || ch >= '+') d = true;
//         }

//         cout << a << ' ' << b << ' ' << c << ' ' << d;

//         return a && b && c && d;
//     }
// };


class Solution {
public:
    bool strongPasswordCheckerII(string password) {

        int n = password.length();

        if(n < 8)
            return false;

        bool lower = false;
        bool upper = false;
        bool digit = false;
        bool special = false;

        string specialChars = "!@#$%^&*()-+";

        for(int i = 0; i < n; i++) {

            char curr = password[i];

            if(islower(curr))
                lower = true;

            if(isupper(curr))
                upper = true;

            if(isdigit(curr))
                digit = true;

            if(specialChars.find(curr) != -1)
                special = true;

            // check consecutive characters
            if(i > 0 && password[i] == password[i - 1])
                return false;
        }

        return lower && upper && digit && special;
    }
};
