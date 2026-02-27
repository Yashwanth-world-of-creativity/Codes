class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    int childCount;
    
    TrieNode() {
        isEnd = false;
        childCount = 0;
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Solution {
public:
    
    void insert(TrieNode* root, string word) {
        TrieNode* node = root;
        
        for(char ch : word) {
            int index = ch - 'a';
            
            if(node->children[index] == NULL) {
                node->children[index] = new TrieNode();
                node->childCount++;
            }
            
            node = node->children[index];
        }
        
        node->isEnd = true;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.empty()) return "";
        
        TrieNode* root = new TrieNode();
        
        // Insert all words
        for(string word : strs) {
            insert(root, word);
        }
        
        // Traverse Trie
        string prefix = "";
        TrieNode* node = root;
        
        while(node->childCount == 1 && node->isEnd == false) {
            
            for(int i = 0; i < 26; i++) {
                if(node->children[i] != NULL) {
                    prefix += (char)(i + 'a');
                    node = node->children[i];
                    break;
                }
            }
        }
        
        return prefix;
    }
};




// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& s) {
//         string ans="";
//         sort(s.begin(),s.end());
//         int i=0;
//         while(i<s[0].size() && s[0][i]==s[s.size()-1][i]){// checking if my i is in the range and comparing first element and last element 
//             ans+=s[0][i];
//             i++;
//         }
//         return ans;
//     }
// };


// class Solution { 
// public:
//     string longestCommonPrefix(vector<string>& str) {
//         int n = str.size();
    
//     sort(str.begin(),str.end());
//     string first = str[0];
//     string last = str [n-1];
//     string ans ="";
//     for (int i= 0; i<first.size();i++)
//     { 
//         if (first[i]== last [i])
//         ans = ans + first[i];
//         else 
//         break;
        
//     }
//     return ans;
//     }
// };
