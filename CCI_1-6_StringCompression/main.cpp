#include <string>
#include <iostream>
#include <vector>
#include <cmath>
#include <memory>

/*
    Return the compressed version of a string using run length encoding.
    If the compression is longer than the original string, return the original string.

    Example: aaabcc -> a3b1c2
*/

struct CompressionData{
    std::vector<char> charArray;
    std::vector<int> countArray;
    size_t compressionLength;
    CompressionData(){}
    CompressionData(std::vector<char> &charArray, std::vector<int> &countArray, size_t compressionLength){
        charArray = charArray;
        countArray = countArray;
        compressionLength = compressionLength;
    }
};

CompressionData getCompressionData(const char* s, size_t length){
    std::vector<char> charArray;
    std::vector<int> countArray;
    size_t compressionLength = 0;

    int i = 0;
    while (i < length){
        char c = *(s + i);
        int j = i + 1;
        while (j < length && *(s + j) == c){
            j++;
        }
        int count = j - i;
        charArray.push_back(c);
        countArray.push_back(count);
        compressionLength += 1 + std::floor(std::log10(count) + 1);

        i = j;
    }

    CompressionData cData;
    cData.charArray = charArray;
    cData.countArray = countArray;
    cData.compressionLength = compressionLength;
    return cData;
}

std::unique_ptr<std::string> createCompression(CompressionData &cData){
    std::string s;
    for (int i = 0; i < cData.charArray.size(); i++){
        s += cData.charArray[i];
        s += std::to_string(cData.countArray[i]);
    }
    
    return std::make_unique<std::string>(s);
}

std::unique_ptr<std::string> compressString(const char* s, size_t length){
    CompressionData cData = getCompressionData(s, length);
    std::string sCompressed;
    if (cData.compressionLength >= length){
        return std::make_unique<std::string>(s, length);
    }
    else{
        return createCompression(cData);

    }
}

int main(){
    std::string s1 = "aaaabbc";
    std::string s2 = "ab";

    std::unique_ptr<std::string> s1Compressed = compressString(s1.data(), s1.length());
    std::unique_ptr<std::string> s2Compressed = compressString(s2.data(), s2.length());

    std::cout << "results" << std::endl;
    std::cout << *s1Compressed << std::endl; // a3b2c1
    std::cout << *s2Compressed << std::endl; // ab

    return 0;
}