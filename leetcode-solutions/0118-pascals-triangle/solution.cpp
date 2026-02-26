class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        
        for(int i=0;i<numRows;i++){
            result[i]=vector<int>(i+1,1);// intiailising all ones for the each rows
            if(numRows==0) return result;
            if(numRows==1) return result;
            for(int j=1;j<i;j++){
                result[i][j]=result[i-1][j]+result[i-1][j-1];
            }
        }
        return result;
    }
};

// class Solution {
// public:
//     vector<int> generateRow(int n)
//     {
//         vector<int> row;
//         int val = 1;
//         row.push_back(val);
//         for(int i = 1;i<n;i++)
//         {
//             val = val*(n-i)/i;
//             row.push_back(val);
//         }
//         return row;
//     }
//     vector<vector<int>> generate(int numRows) {
//         vector<vector<int>> triangle;
//         for(int i = 1;i<=numRows;i++)
//         {
//             triangle.push_back(generateRow(i));
//         }
//         return triangle;
//     }
// }




// class Solution {
// public:
//     vector<vector<int>> generate(int n) {
//         vector<vector<int>> ans;
//         ans.push_back({1});
//         if(n==1)
//         return ans;
//         ans.push_back({1,1});
//         if(n==2)
//          return ans;
//         for(int i=3;i<=n;i++)
//         {
//             vector<int>temp;
//             for(int j=0;j<i;j++)
//             {
//                 if(j==0 || j==i-1)
//                 {
//                     temp.push_back(1);
//                 }
//                 else{
//                     temp.push_back(ans[i-2][j-1]+ans[i-2][j]);
//                 }
//             }
//             ans.push_back(temp);
//         } 
//         return ans;
//     }
// };
