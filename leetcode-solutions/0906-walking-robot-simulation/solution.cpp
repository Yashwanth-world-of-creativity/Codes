class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // Directions: North, East, South, West
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        // Hash obstacles for O(1) lookup
        auto encode = [](int x, int y) {
            return (long long)(x + 30001) * 60001 + (y + 30001);
        };
        
        unordered_set<long long> obs;
        for (auto& o : obstacles)
            obs.insert(encode(o[0], o[1]));
        
        int x = 0, y = 0, dir = 0, ans = 0;
        
        for (int cmd : commands) {
            if (cmd == -2)       // Turn left
                dir = (dir + 3) % 4;
            else if (cmd == -1)  // Turn right
                dir = (dir + 1) % 4;
            else {               // Move forward k steps
                for (int i = 0; i < cmd; i++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if (obs.count(encode(nx, ny))) break; // Blocked
                    x = nx;
                    y = ny;
                    ans = max(ans, x*x + y*y);
                }
            }
        }
        return ans;
    }
};
