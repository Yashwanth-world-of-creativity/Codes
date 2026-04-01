class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        // Create indices sorted by position
        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        stack<int> st; // stores index of robots moving RIGHT

        for (int i : indices) {
            if (directions[i] == 'R') {
                st.push(i);
            } else {
                // Current robot moves LEFT → potential collision
                while (!st.empty() && healths[i] > 0) {
                    int top = st.top();

                    if (healths[top] < healths[i]) {
                        // LEFT wins
                        healths[i]--;
                        healths[top] = 0;  // ✅ mark RIGHT as dead
                        st.pop();
                    } else if (healths[top] > healths[i]) {
                        // RIGHT wins
                        healths[top]--;
                        healths[i] = 0;    // ✅ mark LEFT as dead
                    } else {
                        // Equal → both die
                        healths[top] = 0;
                        healths[i] = 0;
                        st.pop();
                    }
                }
            }
        }

        // Collect survivors in ORIGINAL order
        vector<int> finalResult;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                finalResult.push_back(healths[i]);
            }
        }

        return finalResult;
    }
};
