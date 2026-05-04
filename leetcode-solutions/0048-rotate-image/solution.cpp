class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int m=matrix.size();
       for(int i=0;i<m;i++){ // Transpose
        for(int j=i;j<m;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
       }
       for(int i=0;i<m;i++){ // Reversing a row elements
        reverse(matrix[i].begin(), matrix[i].end());   
       } 

    }
};
