class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int res=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            mp[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            if(mp[nums2[i]]){
                res=min(res,nums2[i]);
            }
        }
        return res==INT_MAX?-1:res;
    }
};
