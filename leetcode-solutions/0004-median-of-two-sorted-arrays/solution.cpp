class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size();
        int n = nums2.size();

        vector<int> merged(m+n);

        int i = 0, j = 0, k = 0;

        while(i < m && j < n){
            if(nums1[i] < nums2[j])
                merged[k++] = nums1[i++];
            else
                merged[k++] = nums2[j++];
        }

        while(i < m)
            merged[k++] = nums1[i++];

        while(j < n)
            merged[k++] = nums2[j++];

        int g = merged.size();

        if(g % 2 == 1)
            return merged[g/2];

        return (merged[g/2] + merged[g/2 - 1]) / 2.0;
    }
};


// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size();
//         int n = nums2.size();

//         nums1.resize(m + n);

//         int i = m - 1;
//         int j = n - 1;
//         int k = m + n - 1;

//         while(i >= 0 && j >= 0){
//             if(nums1[i] > nums2[j]){
//                 nums1[k--] = nums1[i--];
//             }
//             else{
//                 nums1[k--] = nums2[j--];
//             }
//         }

//         while(j >= 0){
//             nums1[k--] = nums2[j--];
//         }

//         vector<int> merged(nums1.begin(), nums1.end());

//         int g = merged.size();

//         if(g % 2 == 1) 
//             return merged[g/2];

//         return (merged[g/2] + merged[g/2 - 1]) / 2.0;
//     }
// };

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

//         vector<int> temp;
//         int i = 0, j = 0;

//         while(i < m && j < n){
//             if(nums1[i] < nums2[j])
//                 temp.push_back(nums1[i++]);
//             else
//                 temp.push_back(nums2[j++]);
//         }

//         while(i < m) temp.push_back(nums1[i++]);
//         while(j < n) temp.push_back(nums2[j++]);

//         for(int k = 0; k < m+n; k++)
//             nums1[k] = temp[k];
//     }
// };
