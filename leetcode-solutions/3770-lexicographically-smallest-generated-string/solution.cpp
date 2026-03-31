class Solution {
public:
    string generateString(string str1, string str2) {
        
        int n = str1.size();
        int m = str2.size();

        string ans(n + m - 1, '?');

        // Step 1: enforce 'T'
        for(int i = 0; i < n; i++){
            if(str1[i] == 'T'){
                for(int j = 0; j < m; j++){
                    if(ans[i+j] == '?' || ans[i+j] == str2[j]){
                        ans[i+j] = str2[j];
                    } else {
                        return ""; // conflict
                    }
                }
            }
        }

        // Step 2: fill remaining positions
        for(int i = 0; i < ans.size(); i++){
            if(ans[i] == '?'){
                for(char c = 'a'; c <= 'z'; c++){
                    ans[i] = c;

                    bool ok = true;

                    // check all affected windows
                    for(int start = max(0, i - m + 1); start <= min(i, n-1); start++){
                        if(str1[start] == 'F'){
                            bool match = true;
                            for(int j = 0; j < m; j++){
                                if(ans[start + j] != str2[j]){
                                    match = false;
                                    break;
                                }
                            }
                            if(match){
                                ok = false;
                                break;
                            }
                        }
                    }

                    if(ok) break;
                }
            }
        }

        // Step 3: final validation
        for(int i = 0; i < n; i++){
            bool match = true;
            for(int j = 0; j < m; j++){
                if(ans[i+j] != str2[j]){
                    match = false;
                    break;
                }
            }

            if((str1[i] == 'T' && !match) || (str1[i] == 'F' && match)){
                return "";
            }
        }

        return ans;
    }
};
