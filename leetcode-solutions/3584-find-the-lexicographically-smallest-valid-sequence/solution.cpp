class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        int i=n-1;
        int j=m-1;
        int rightside=0;
        vector<int> rightHandside(n,0);
        while(i>=0){
            if(j>=0 && word1[i]==word2[j]) {
                rightside++;
                j--;
            }
            rightHandside[i]=rightside;
            i--;
        }
        vector<int>seq;
        i=0;
        j=0;
        bool changepower=true;
        while(i<n&& j<m){
            if(word1[i]==word2[j]){
                seq.push_back(i);
                j++;
            }else if(changepower && i+1<n&& rightHandside[i+1]>=m-j-1){
                seq.push_back(i);
                j++;
                changepower=false;
            }
            i++;
        }
        return j==m?seq:vector<int>();

    }
};
