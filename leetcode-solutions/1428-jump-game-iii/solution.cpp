class Solution {
public:

    bool dfs(vector<int>& arr, int idx, vector<int>& vis) {

        int n = arr.size();

        if (idx < 0 || idx >= n || vis[idx])
            return false;

        if (arr[idx] == 0)
            return true;

        vis[idx] = 1;

        int forward = idx + arr[idx];
        int backward = idx - arr[idx];

        return dfs(arr, forward, vis) ||
               dfs(arr, backward, vis);
    }

    bool canReach(vector<int>& arr, int start) {

        int n = arr.size();

        vector<int> vis(n, 0);

        return dfs(arr, start, vis);
    }
};
