class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        if (n == 1)
            return 0;

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {

            mp[arr[i]].push_back(i);
        }

        queue<int> q;

        vector<int> vis(n, 0);

        q.push(0);

        vis[0] = 1;

        int jumps = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                int idx = q.front();
                q.pop();

                if (idx == n - 1)
                    return jumps;

                if (idx - 1 >= 0 && !vis[idx - 1]) {

                    vis[idx - 1] = 1;
                    q.push(idx - 1);
                }

                if (idx + 1 < n && !vis[idx + 1]) {

                    vis[idx + 1] = 1;
                    q.push(idx + 1);
                }

                for (int next : mp[arr[idx]]) {

                    if (!vis[next]) {

                        vis[next] = 1;
                        q.push(next);
                    }
                }

                mp[arr[idx]].clear();
            }

            jumps++;
        }

        return -1;
    }
};
