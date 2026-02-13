class Solution {
public:
    vector<int> frequencySort(vector<int>& arr) {
   
        unordered_map<int,int>freq;
        // Step 1: Count frequency
        for (int x : arr) {
            freq[x]++;
        }

        // Step 2: Sort using BOTH conditions
        sort(arr.begin(), arr.end(), [&](int a, int b) {

            // Condition 1: sort by frequency (ascending)
            if (freq[a] != freq[b]) {
                return freq[a] < freq[b];
            }

            // Condition 2: if frequency same, sort by value (ascending)
            return a > b;
        });

        return arr;
    }
};

 
