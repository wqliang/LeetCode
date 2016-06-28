#ifndef  __SOLUTION_H__
#define  __SOLUTION_H__
#include"Solution.h"
#endif
#include<string>

class Solution344 : public Solution {
public:
    string reverseString(string s) {
		if (s.empty())
			return s;
		int first = 0;
		int last = s.length() - 1;
		string str = s;
		while (first < last){
			char tmp = str[first];
			str[first] = str[last];
			str[last] = tmp;
			first++;
			last--;
		}
		return str;
    }

	void run();
};

void Solution344::run(){
	cout << this->reverseString("hello") << endl;
	cout << this->reverseString("1234567890") << endl;
	cout << this->reverseString("") << endl;
}