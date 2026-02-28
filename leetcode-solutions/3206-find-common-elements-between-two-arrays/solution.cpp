#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;

        // Store frequency of nums1
        for(int i = 0; i < nums1.size(); i++) {
            mp1[nums1[i]]++;
        }

        // Store frequency of nums2
        for(int i = 0; i < nums2.size(); i++) {
            mp2[nums2[i]]++;
        }

        int count1 = 0;
        int count2 = 0;

        // Count elements of nums1 present in nums2
        for(int i = 0; i < nums1.size(); i++) {
            if(mp2.find(nums1[i]) != mp2.end())
                count1++;
        }

        // Count elements of nums2 present in nums1
        for(int i = 0; i < nums2.size(); i++) {
            if(mp1.find(nums2[i]) != mp1.end())
                count2++;
        }

        return {count1, count2};
    }
};



// class Solution {
// public:
//     vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {

//         unordered_set<int> set1(nums1.begin(), nums1.end());
//         unordered_set<int> set2(nums2.begin(), nums2.end());

//         int count1 = 0;
//         int count2 = 0;

//         // Count elements in nums1 present in nums2
//         for(int i = 0; i < nums1.size(); i++) {
//             if(set2.find(nums1[i]) != set2.end())
//                 count1++;
//         }

//         // Count elements in nums2 present in nums1
//         for(int i = 0; i < nums2.size(); i++) {
//             if(set1.find(nums2[i]) != set1.end())
//                 count2++;
//         }

//         return {count1, count2};
//     }
// };
