class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
       
       int startR=x;
       int endR=x+k-1;
       int startC=y;
       int endC=y+k-1;

       for(int i=startR;i<=endR;i++){
        for(int j=startC;j<=endC;j++){
            swap(grid[i][j],grid[endR][j]);
        }
        endR--;
       }
       return grid;
    }
};
