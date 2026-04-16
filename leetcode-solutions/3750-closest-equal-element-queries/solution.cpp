class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        vector<int>result;
        for(int q:queries){
            int element = nums[q];
            vector<int>&vec=mp[element];
            int sz=vec.size();

            //no more elements
            if(sz==1){
                result.push_back(-1);
                continue;
            }

            int pos=lower_bound(vec.begin(),vec.end(),q)-begin(vec);
            int res=INT_MAX;

            int right=vec[(pos+1)%sz];
            int d=abs(q-right);
            int Cd=n-d;
            res=min({res,d,Cd});

            //left side

            int left=vec[(pos-1+sz)%sz];
             d=abs(q-left);
             Cd=n-d;
            res=min({res,d,Cd});

            result.push_back(res);
        }
      return result;   
    }
};
