class NumArray {
public:
vector<int>PS;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        PS.resize(n+1);
        PS[0]=0;
    for(int i=1;i<=n;i++){
        PS[i]=nums[i-1]+PS[i-1];
    }
    }
    
    int sumRange(int l, int r) {
        
            return PS[r+1]-PS[l];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
