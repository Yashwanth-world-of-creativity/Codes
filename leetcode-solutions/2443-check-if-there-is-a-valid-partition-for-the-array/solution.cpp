class Solution {
public:
int n;
int t[100001];
bool solve(vector<int>& nums,int i){
    int result=false;
    if(i>=n) return true;
    if(t[i]!=-1) return t[i];
    if(i+1<n && nums[i]==nums[i+1]) //rule 1 
    result|=solve(nums,i+2);
    if(i+2<n && nums[i]==nums[i+1]&&nums[i+1]==nums[i+2]) //rule 2
    result|=solve(nums,i+3);
     if(i+2<n && nums[i+1]-nums[i]==1 && nums[i+2]-nums[i+1]==1) //rule 3
    result|=solve(nums,i+3);
    return t[i]=result;

}
    bool validPartition(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        n=nums.size();
        return solve(nums,0);
    }
};
