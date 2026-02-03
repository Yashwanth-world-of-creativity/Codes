class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int count=0;
       int ans;
       for(int &i:nums){
        if(count == 0)
        ans =i;
        count += (i == ans)?1:-1;
        
       }
       return ans;

    }
};
