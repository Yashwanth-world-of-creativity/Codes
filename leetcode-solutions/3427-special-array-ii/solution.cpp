class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<int>cumsum(n,0);
        cumsum[0]=0;//starting index
        for(int i=1;i<n;i++){
            if(nums[i]%2==nums[i-1]%2){
                cumsum[i]=cumsum[i-1]+1; //if its violates
            }
            else{
                cumsum[i]=cumsum[i-1];
            }
        }

        vector<bool>result(m,false);
        int i=0;
        for(auto &q:queries){
            int start=q[0];
            int end=q[1];
            if(cumsum[end]-cumsum[start]==0){
                result[i]=true;
            }
            i++;
        }
        return result;
    }
};
