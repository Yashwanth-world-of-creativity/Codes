class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        int n = arr.size();
        int zeros = 0;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0)
                zeros++;
        }
        
        int i = n - 1;
        int j = n + zeros - 1;
        
        while(i >= 0) {
            
            if(j < n)
                arr[j] = arr[i];
            
            if(arr[i] == 0) {
                j--;
                if(j < n)
                    arr[j] = 0;
            }
            
            i--;
            j--;
        }
    }
};
// Brute Froce
// class Solution {
// public:
//     void duplicateZeros(vector<int>& arr) {
        
//         int n = arr.size();
        
//         for(int i = 0; i < n - 1; i++) {
            
//             if(arr[i] == 0) {
                
//                 // shift elements to the right
//                 for(int j = n - 1; j > i; j--) {
//                     arr[j] = arr[j - 1];
//                 }
                
//                 i++; // skip the duplicated zero
//             }
//         }
//     }
// };



