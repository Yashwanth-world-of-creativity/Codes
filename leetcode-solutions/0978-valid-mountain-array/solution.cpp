#include <vector>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return false;

        int i = 0;

        while(i + 1 < n && arr[i] < arr[i + 1]) {
            i++;
        }

        if(i == 0 || i == n - 1) return false;

        while(i + 1 < n && arr[i] > arr[i + 1]) {
            i++;
        }

        return i == n - 1;
    }
};



// class Solution {
// public:
//     bool validMountainArray(vector<int>& A) {
//         int n = A.size();
        
//         if(n < 3) return false;

//         // Find max
//         int maxVal = 0;
//         int index = 0;

//         for(int i = 0; i < n; i++){
//             if(A[i] > maxVal){
//                 maxVal = A[i];
//                 index = i;
//             }
//         }

//         // Check if peak is at start or end
//         if(index == 0 || index == n-1)
//             return false;

//         // Check strictly increasing
//         for(int i = 1; i <= index; i++){
//             if(A[i] > A[i-1])
//                 continue;
//             else
//                 return false;
//         }

//         // Check strictly decreasing
//         for(int i = index; i < n-1; i++){
//             if(A[i] > A[i+1])
//                 continue;
//             else
//                 return false;
//         }

//         return true;
//     }
// };
