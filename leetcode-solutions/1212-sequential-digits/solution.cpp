
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        vector<int> ans;

        for(int start = 1; start <= 8; start++) { // so that it covers all digits 0-9 

            int num = start;

            for(int next = start + 1; next <= 9; next++) {

                num = num * 10 + next;

                if(num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};//brute force approach
// class Solution {
// public:
//     vector<int> sequentialDigits(int low, int high) {

//         vector<int> ans;

//         for(int i = low; i <= high; i++) {

//             int temp = i;

//             vector<int> digit;

//             while(temp > 0){

//                 digit.push_back(temp % 10);

//                 temp /= 10;
//             }

//             reverse(digit.begin(), digit.end());

//             bool ok = true;

//             for(int j = 1; j < digit.size(); j++){

//                 if(digit[j] != digit[j-1] + 1){

//                     ok = false;
//                     break;
//                 }
//             }

//             if(ok)
//                 ans.push_back(i);
//         }

//         return ans;
//     }
// };
