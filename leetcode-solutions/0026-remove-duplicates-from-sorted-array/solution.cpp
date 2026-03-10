// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int i=0;
//         int n=nums.size();
//         if(n==0) return 0;
//         for(int j=0;j<n;j++){
//             if(nums[i]!=nums[j])
//             i++;
//             nums[i]=nums[j];
            
//         }
//         return i+1 ;
//     }
    
// };

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();
        if(n == 0) return 0;

        int k = 1;

        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[i-1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};
