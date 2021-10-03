// LeetCode 139. Word Break
// Medium

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std; 

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        for (auto& str : wordDict) {
            // convert word in a set
            dict.insert(str); 
        }
        
        return _wordBreak(s); 
        
    }
    
private:
    unordered_map<string, bool> memo; 
    unordered_set<string> dict; 
    
    bool _wordBreak(const string& s) {
        
        if (dict.find(s) != dict.end()) {
            // the string is in the dictionary
            memo.insert(make_pair(s, true)); 
            return true; 
        }
        
        if (memo.find(s) != memo.end()) {
            // the string is already in the memo, so that no need to study it again
            return memo[s]; 
        }
        
        for (int k = 1; k < s.length(); ++k) {
            string leftSubstr = s.substr(0, k); // [0, k)
            string rightSubstr = s.substr(k);   // [k, end]
            
            // search one of the substring (either left sub string or right sub string)
            // and put the other string in the next iteration of the recursion
            bool cond1 = dict.find(leftSubstr) != dict.end();
            bool cond2 = _wordBreak(rightSubstr); 
            if (cond1 && cond2) {
                memo.insert(make_pair(s, true));
                return true; 
            }

        }
        
        // the string cannot be splitted such that the substrings can be 
        // found in the dictionary
        memo.insert(make_pair(s, false));
        return false; 

    }
};