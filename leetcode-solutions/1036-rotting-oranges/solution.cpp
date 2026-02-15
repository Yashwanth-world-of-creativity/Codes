class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int fresh = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else {
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1) fresh++;
            }
        }

        int tm = 0;
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            tm = max(tm, t);

            for(int i = 0; i < 4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < n && 
                   ncol >= 0 && ncol < m &&
                   vis[nrow][ncol] != 2 &&
                   grid[nrow][ncol] == 1) {

                    q.push({{nrow,ncol}, t+1});
                    vis[nrow][ncol] = 2;
                    fresh--;
                }
            }
        }

        if(fresh > 0) return -1;

        return tm;
    }
};


// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n=grid.size();
//         int m=grid[0].size();
//         //{(r,c),t}
//         queue<pair<pair<int,int>,int>>q;
//         int  vis[n][m];
//         int cntfresh++;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]==2){
//                     q.push({{i,j},0});
//                     vis[i][j]=2;
//                 }
//                 esle{
//                     vis[i][j]=0;
//                 }
//                 if(grid[i][j]==1) cntfresh++;
//             }
//         }
//         int tm=0;
//         int drow[] ={-1,0,+1,0};
//         int dcol={0,1,0,-1};
//         while(!q.empty()){
//             int r=q.front().frist.first;
//             int c=q.front().frist.second;
//             int t=q.front().second;
//             q.pop();
//             for(int i=0;i<4;i++){
//                 int nrow=r+drow[i];
//                 int ncol=c+dcol[i];
//                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
//                 &&vis[nrow][ncol!=2&&grid[nrow][ncol]==1]
//                  q.push({{nrow,ncol},t+1});
//                  vis[nrow][ncol]=2;
//                  cnt++;
//             }

//         }

//         //no need for this loop 
//         // for(int i=0;i<n;i++){
//         //     for(int j=0;j<m;j++){
//         //         if(vis[i][j]!=2&& grid==1){
//         //             return -1;
//         //         }
//         //     }
//         // }
//         //from here its there
//         if(cnt!=cntfresh) return -1;
//         return tm;
//     }
// };


// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
        
//         queue<pair<int,int>> q;
//         int fresh = 0;
        
//         for(int i = 0; i < n; i++) {
//             for(int j = 0; j < m; j++) {
//                 if(grid[i][j] == 2)
//                     q.push({i,j});
//                 else if(grid[i][j] == 1)
//                     fresh++;
//             }
//         }
        
//         if(fresh == 0) return 0;
        
//         int minutes = 0;
//         vector<int> dx = {1,-1,0,0};
//         vector<int> dy = {0,0,1,-1};
        
//         while(!q.empty()) {
//             int size = q.size();
//             bool rotted = false;
            
//             for(int i = 0; i < size; i++) {
//                 auto [x,y] = q.front();
//                 q.pop();
                
//                 for(int d = 0; d < 4; d++) {
//                     int nx = x + dx[d];
//                     int ny = y + dy[d];
                    
//                     if(nx >= 0 && ny >= 0 && nx < n && ny < m 
//                        && grid[nx][ny] == 1) {
                        
//                         grid[nx][ny] = 2;
//                         q.push({nx,ny});
//                         fresh--;
//                         rotted = true;
//                     }
//                 }
//             }
            
//             if(rotted) minutes++;
//         }
        
//         return fresh == 0 ? minutes : -1;
//     }
// };
