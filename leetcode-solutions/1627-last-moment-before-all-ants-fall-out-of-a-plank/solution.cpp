class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int result=0;
     for(int &x:left){
        result=max(result,x);
     }
     for(int &y:right){
        result=max(result,n-y);
     }
     return result;
    }
};
