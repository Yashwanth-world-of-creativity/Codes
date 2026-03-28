class Solution {
public:

    vector<int> parent;

    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b){
        a = find(a);
        b = find(b);
        if(a != b) parent[a] = b;
    }

    string findTheString(vector<vector<int>>& lcp) {
        
        int n = lcp.size();
        parent.resize(n);

        for(int i = 0; i < n; i++) parent[i] = i;

        // 🔹 Step 1: union where lcp > 0
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(lcp[i][j] > 0){
                    unite(i, j);
                }
            }
        }

        // 🔹 Step 2: assign characters
        unordered_map<int, char> mp;
        char ch = 'a';

        string s(n, '?');

        for(int i = 0; i < n; i++){
            int p = find(i);

            if(mp.count(p) == 0){
                if(ch > 'z') return "";  // only 26 letters
                mp[p] = ch++;
            }

            s[i] = mp[p];
        }

        // 🔹 Step 3: validate LCP
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(s[i] == s[j]){
                    if(i+1 < n && j+1 < n)
                        dp[i][j] = 1 + dp[i+1][j+1];
                    else
                        dp[i][j] = 1;
                }
            }
        }

        // compare with given lcp
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dp[i][j] != lcp[i][j])
                    return "";
            }
        }

        return s;
    }
};
