#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

/*
    Dynamic Programming:
        Determine if a string can be split into a space separated sequence of words, such that all words
        are contained in a given dictionary.
*/

class Solution{

public:
    bool containedInDict(std::string s, std::unordered_set<std::string>& dict){
        return dict.find(s) != dict.end();
    }

    std::unordered_set<std::string> createDictionary(std::vector<std::string>* wordDict){
        std::unordered_set<std::string> set;
        for (int i = 0; i < wordDict->size(); i++){
            set.insert((*wordDict)[i]);
        }
        return set;
    }

    bool findSplit(std::string s, size_t endIndex, std::unordered_set<std::string>&dict, bool* canSplitArray){
        
        // cannot make j type size_t, because loop will not exit since size_t is unsigned
        // unsigned j will wrap around to the largest positive value, loop condition may not trigger.
        int j = endIndex; 
        bool foundSplit = false;
        while (j >= 0 && !foundSplit){
            if (j == 0){
                foundSplit = containedInDict(s.substr(0, endIndex+1), dict);
            }
            else{
                foundSplit = containedInDict(s.substr(j, endIndex-j+1), dict) && canSplitArray[j-1];
            }
            j--;
        }
        return foundSplit;
    }

    bool wordBreak(std::string s, std::vector<std::string>& wordDict){
        size_t n = s.length();
        bool canSplitArray[n];
        std::unordered_set<std::string> dict = createDictionary(&wordDict);

        canSplitArray[0] = containedInDict(s.substr(0, 1), dict);
        for (size_t i = 1; i < n; i++){
            bool canSplit = findSplit(s, i, dict, canSplitArray);
            canSplitArray[i] = canSplit;
        }
        return canSplitArray[n-1];
    }

};

int main(){
    Solution sol;
    std::string s = "leetcode";
    std::vector<std::string> wordDict = {"leet", "code"};
    
    bool canSplit = sol.wordBreak(s, wordDict);

    std::cout << canSplit << std::endl;
}