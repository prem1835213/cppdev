#include <cmath>
#include <string>
#include <iostream>

/*
    Check if two strings are exactly one edit distance away from each other.
    Edit can be insert, delete, or replace
*/

int findFirstNoncommonCharacter(const char* s1, const char* s2, int length1, int length2){
    int n;
    if (length1 < length2){
        n = length1;
    }
    else {
        n = length2;
    }

    const char* p1 = s1;
    const char* p2 = s2;
    for (int i = 0; i < n; i++){
        if (*p1 != *p2) return i;
        p1++;
        p2++;
    }
    return n;
}

bool checkReplacement(const char* s1, const char* s2, int length){
    int firstNoncommonIndex = findFirstNoncommonCharacter(s1, s2, length, length);
    
    if (firstNoncommonIndex == length - 1){
        return true;
    }

    for (int i = firstNoncommonIndex + 1; i < length; i++){
        if (*(s1 + i) != *(s2 + i)) return false;
    }
    return true;
}

bool checkDeletion(const char* s1, const char* s2, int length1, int length2){
    int firstNoncommonIndex = findFirstNoncommonCharacter(s1, s2, length1, length2);
    int n;
    const char* p1;
    const char* p2;
    
    if (length1 < length2){
        n = length1;
        p1 = s1 + firstNoncommonIndex;
        p2 = s2 + firstNoncommonIndex + 1;
    }
    else{
        n = length2;
        p1 = s1 + firstNoncommonIndex + 1;
        p2 = s2 + firstNoncommonIndex;
    }

    for (int i = firstNoncommonIndex; i < n; i++){
        if (*p1 != *p2) return false;
        p1++;
        p2++;
    }
    return true;
}

bool oneAway(const char* s1, const char* s2, int length1, int length2){
    int lengthDiff = std::abs(length1 - length2);
    if (lengthDiff > 1){
        return false;
    }
    else if (lengthDiff == 1){
        return checkDeletion(s1, s2, length1, length2);
    }
    else{
        return checkReplacement(s1, s2, length1);
    }
}

int main(){

    std::string s1 = "abcd";
    std::string s2 = "abd";

    std::string s3 = "abcd";
    std::string s4 = "abc";

    std::string s5 = "abcd";
    std::string s6 = "abjd";

    std::string s7 = "abkf";
    std::string s8 = "abcd";

    std::string s9 = "jbcd";
    std::string s10 = "abcd";

    std::cout << (oneAway(s1.data(), s2.data(), s1.length(), s2.length()) == true) << std::endl;
    std::cout << (oneAway(s3.data(), s4.data(), s3.length(), s4.length()) == true) << std::endl;
    std::cout << (oneAway(s5.data(), s6.data(), s5.length(), s6.length()) == true) << std::endl;
    std::cout << (oneAway(s7.data(), s8.data(), s7.length(), s8.length()) == false) << std::endl;
    std::cout << (oneAway(s9.data(), s10.data(), s9.length(), s10.length()) == true) << std::endl;

    return 0;
}