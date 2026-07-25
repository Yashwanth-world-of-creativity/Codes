// class Solution { //these was only for two consecutive number  
// public:
// int multiply(int r,int v){
//     return r*v;
// }
//     int maxProduct(int n) {
//         int rem=0;
//         int rev=0;
//         int ans=0;
//         while(n>0){
//             rem=n%10;
//             n=n/10;
//              rev= n%10;
//         ans=max(ans,multiply(rem,rev));
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int maxProduct(int n) {

        int first = 0;
        int second = 0;

        while (n > 0) {

            int digit = n % 10;

            if (digit >= first) {
                second = first;
                first = digit;
            }
            else if (digit > second) {
                second = digit;
            }

            n /= 10;
        }

        return first * second;
    }
};
