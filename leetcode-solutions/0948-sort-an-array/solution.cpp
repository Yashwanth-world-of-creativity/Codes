class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        mergeSort(nums, temp, 0, nums.size() - 1);
        return nums;
    }

private:
    void mergeSort(vector<int>& a, vector<int>& temp, int l, int r) {
        if (l >= r) return;
        int m = l + ((r - l) >> 1);
        mergeSort(a, temp, l, m);
        mergeSort(a, temp, m + 1, r);
        merge(a, temp, l, m, r);
    }

    void merge(vector<int>& a, vector<int>& temp, int l, int m, int r) {
        int i = l, j = m + 1, k = l;

        while (i <= m && j <= r) {
            if (a[i] <= a[j]) temp[k++] = a[i++];
            else temp[k++] = a[j++];
        }
        while (i <= m) temp[k++] = a[i++];
        while (j <= r) temp[k++] = a[j++];

        for (int p = l; p <= r; p++) {
            a[p] = temp[p];
        }
    }
};
