class Solution {
public:
    int arrangeCoins(int n) {

        long long start = 0;
        long long end = n;

        while(start <= end) {

            long long mid = start + (end - start) / 2;
            long long k = mid * (mid + 1) / 2;

            if(k == n) {
                return mid;
            }
            else if(k > n) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return end;
    }
};
