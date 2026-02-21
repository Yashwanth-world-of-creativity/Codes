class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        multiset<int> st(nums1.begin(), nums1.end());
        vector<int> ans;
        
        for(int &i : nums2) {
            auto it = st.find(i);
            if(it != st.end()) {
                ans.push_back(i);
                st.erase(it);  // remove one occurrence
            }
        }
        
        return ans;
    }
};
// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
//         multiset<int> st(nums1.begin(), nums1.end());
//         multiset<int> same;
        
//         for(auto &i : nums2) {
//             if(auto it = st.find(i); it != st.end()) {
//                 same.insert(i);
//                 st.erase(it);
//             }
//         }
        
//         return vector<int>(same.begin(), same.end());
//     }
// };

//sort and two pointer approach
// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         sort(nums1.begin(),nums1.end());
//         sort(nums2.begin(),nums2.end());
//         int i = 0;
//         int j = 0;
//         vector<int> ans;
//         while(i<nums1.size() && j<nums2.size()){
//             if(nums1[i]<nums2[j]){
//                 i++;
//             }
//             else if(nums2[j]<nums1[i]){
//                 j++;
//             }
//             else{
//                 ans.push_back(nums1[i]);
//                 i++;
//                 j++;
//             }
//         }
//         return ans;
        
        
//     }
// };
