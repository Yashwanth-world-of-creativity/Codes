class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<long long>pre(n+1,0);
        for(auto& q:bookings){
            int l=q[0];
            int r=q[1];
            int k=q[2];
            pre[l]+=k;
            if(r<n)
            pre[r+1]-=k;
        }
        for(int  i=1;i<=n;++i)
        pre[i]+=pre[i-1];
        return  vector<int>(pre.begin()+1,pre.end());
    }
};
