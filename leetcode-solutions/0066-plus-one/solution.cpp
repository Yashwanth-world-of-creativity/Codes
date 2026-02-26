class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        for(int i = n - 1; i >= 0; i--) {
            if(digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        
        // If all digits were 9
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
// class Solution {
// public:
//     vector<int> plusOne(vector<int>& digits) {
        
//         int n = digits.size();
//         long long num = 0;
        
//         // Convert vector to number
//         for(int i = 0; i < n; i++) {
//             num = num * 10 + digits[i];
//         }
        
//         // Add one
//         num = num + 1;
        
//         // Convert number back to vector
//         vector<int> result;
        
//         if(num == 0) {
//             result.push_back(0);
//             return result;
//         }
        
//         while(num > 0) {
//             result.push_back(num % 10);
//             num /= 10;
//         }
        
//         reverse(result.begin(), result.end());
        
//         return result;
//     }
// };
