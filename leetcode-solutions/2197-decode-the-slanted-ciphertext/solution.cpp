class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(encodedText.empty()) return "";
        int cols = encodedText.size() / rows;
        string result = "";
        for(int j = 0; j < cols; j++){
            int r = 0, c = j;
            while(r < rows && c < cols){
                result += encodedText[r * cols + c];
                r++;
                c++;
            }
        }
        while(!result.empty() && result.back() == ' ')
            result.pop_back();
        return result;
    }
};
