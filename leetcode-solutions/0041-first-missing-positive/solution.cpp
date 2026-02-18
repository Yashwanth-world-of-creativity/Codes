class Solution {
public:
    int firstMissingPositive(vector<int>& nums)  {
        
        int n = nums.size();
        bool con1=false;
        for(int i=0;i<n;i++){
            if(nums[i]==1)
            con1=true;
        
        if(nums[i]<=0||nums[i]>n){//[1,n)
            nums[i]=1;
        }
        }
       if(con1==false){
        return 1;
       }
        
       for(int i=0;i<n;i++){
        int num=abs(nums[i]);// for the index access we need +ve valur
        int idx=num-1;
        if(nums[idx]<0) continue;// if same number  repeats we should avoid repeating
        nums[idx]*=-1;
       }
       for(int i=0;i<n;i++){
        if(nums[i]>0){
            return i+1;
        }
       }
       return n+1;
    }
    
    };
// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
        
//         int n = nums.size();
        
//         // Step 1: Replace invalid numbers
//         for(int i = 0; i < n; i++) {
//             if(nums[i] <= 0 || nums[i] > n)
//                 nums[i] = n + 1;
//         }
        
//         // Step 2: Mark presence
//         for(int i = 0; i < n; i++) {
//             int val = abs(nums[i]);
//             if(val >= 1 && val <= n) {
//                 nums[val - 1] = -abs(nums[val - 1]);
//             }
//         }
        
//         // Step 3: Find first positive index
//         for(int i = 0; i < n; i++) {
//             if(nums[i] > 0)
//                 return i + 1;
//         }
        
//         return n + 1;
//     }
// };
