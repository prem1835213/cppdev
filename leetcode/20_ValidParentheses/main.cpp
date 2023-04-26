#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	bool isValid(string s){
		if (s.length() == 0){
			return true;
		}

		vector<char> vec;
		for (int i = 0; i < s.length(); i++){
			if (s[i] == '('){
				vec.push_back(s[i]);
			}
			else{
				if (vec.back() == '('){
					vec.pop_back();
				}
				else{
					return false;
				}
			}
		}
		
		return vec.size() == 0;

	}
};

int main(){
	Solution sol;
	bool out1 = sol.isValid("(()");
	bool out2 = sol.isValid("");
	bool out3 = sol.isValid("()");
	bool out4 = sol.isValid("())");
	bool out5 = sol.isValid("(())");
	bool out6 = sol.isValid("()()");


	std::cout << out1 << " should be 0" << std::endl;
	std::cout << out2 << " should be 1" << std::endl;
	std::cout << out3 << " should be 1" << std::endl;
	std::cout << out4 << " should be 0" << std::endl;
	std::cout << out5 << " should be 1" << std::endl;
	std::cout << out6 << " should be 1" << std::endl;
	return 0;
}
