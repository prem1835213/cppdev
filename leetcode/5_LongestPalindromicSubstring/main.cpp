#include <vector>
#include <string>
#include <iostream>
#include <cstring>

class Solution{
    public:
    std::string longestPalindrome(std::string s){
        int n = s.length();
        bool M[n][n];
        std::memset(&M, false, sizeof(M));

        // build DP matrix from bottom-up since recursion depends on lower rows and left columns
        for (int i = s.length() - 1; i >= 0; i--){
            for (int j = i; j < s.length(); j++){
                if (i == j){
                    M[i][j] = true;
                }
                else if (j - i == 1){
                    M[i][j] = s[i] == s[j];
                }
                else{
                    M[i][j] = (s[i] == s[j]) && M[i+1][j-1];
                }
            }
        }

        int maxLen = 0;
        int startIdx = 0;
        for (int i = 0; i < s.length(); i++){
            for (int j = i; j < s.length(); j++){
                if (M[i][j] && (j-i+1) > maxLen){
                    maxLen = j-i+1;
                    startIdx = i;
                }
            }
        }

        return s.substr(startIdx, maxLen);
    }
};

int main(){
    Solution sol;

    std::string return1 = sol.longestPalindrome("dabbac");
    std::cout << return1 << " should be " << "abba" << std::endl;
}