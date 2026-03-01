class Solution {
public:

    int sumOfSquares(int n) {
        int sum = 0;
        while(n) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        if(n==0)
        return false;
        int slow = n;
        int fast = sumOfSquares(n);
        if(slow==1||fast==1)
        return true;

        while(slow != fast) {
            slow = sumOfSquares(slow);
            fast = sumOfSquares(sumOfSquares(fast));
          if(slow==1||fast==1)
        return true;
        }

    return false;
    }
};

// class Solution {
// public:

//     int sumOfSquares(int n) {
//         int sum = 0;
//         while(n > 0) {
//             int digit = n % 10;
//             sum += digit * digit;
//             n /= 10;
//         }
//         return sum;
//     }

//     bool isHappy(int n) {
//         if(n==0)
//         return false;
//         unordered_set<int> seen;

//         while( seen.find(n) == seen.end()) {
//             seen.insert(n);
//             n = sumOfSquares(n);
//             if(n==1)
//             return true;
//         }

//         return false;
//     }
// };
