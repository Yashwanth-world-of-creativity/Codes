class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>pre(n+1);
        for(auto& q:bookings){
            int l=q[0]-1;
            int r=q[1]-1;
            int k=q[2];
            pre[l]+=k;
            if(r<n-1)
            pre[r+1]-=k;
        }
        for(int  i=1;i<=n;++i)
        pre[i]+=pre[i-1];
        pre.resize(n);
        return pre;
    }
};
