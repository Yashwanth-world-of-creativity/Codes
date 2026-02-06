class Solution {
public:
int modpow(int base, int power){
    base%=1337;
    int ans=1;
    for(int i=0;i<power;i++){
        ans=(ans*base)%1337;
    }
    return ans;
}
    int superPow(int a, vector<int>& b) {
        int ans=1;
        for(int i=0;i<b.size();i++){
            // ans=((ans^10)*(a^b[i]))%1337;
            ans=((modpow(ans,10))*(modpow(a,b[i])))%1337;
        }
        return ans;
    }
};

// class Solution {
// public:
//     int modpow(int base, int exp) {
//         int res = 1;
//         base %= 1337;
//         while (exp > 0) {
//             if (exp & 1) res = (res * base) % 1337;
//             base = (base * base) % 1337;
//             exp >>= 1;
//         }
//         return res;
//     }

//     int superPow(int a, vector<int>& b) {
//         int ans = 1;
//         for (int i = 0; i < b.size(); i++) {
//             ans = (modpow(ans, 10) * modpow(a, b[i])) % 1337;
//         }
//         return ans;
//     }
// };

