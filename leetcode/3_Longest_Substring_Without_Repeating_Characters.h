#ifndef _SOLUTION3_H_
#define _SOLUTION3_H_

#include <string>
#include "Solution.h";
#include <typeinfo.h>

class Solution3 : public Solution{
public:
    int lengthOfLongestSubstring(string s) {
        int last_pos[200];	//打表，记录每个字符最近一次出现的位置
		for (int i = 0; i < 200; i++)
			last_pos[i] = -1;
		//start标记当前没有重复字符的子串的开始位置
		int start = 0;
		int longest = 0;
		//string subs;
		for (int i = 0; i < s.length(); i++){
			char currChar = s[i];
			//第一个条件判断当前字符在之前已经出现过了
			//第二个条件防止像“abba”的字符串，last['a'] = 0,当遍历到s[3]='a'时，start=2，
			//如果把start设为last['a']+1，那么子串为"bba",还是有重复字符
			if (last_pos[currChar] != -1 && last_pos[currChar] >= start){			
				//从start到i-1的子串是不重复的，但start到i是重复的，
				//[i]和[start, i-1]中的某个位置上的字符一样，
				//而字符[i]上一次出现的位置是last_pos[s[i]]，
				//所以从last_pos[]+1到i这段上的字符是不重复的
				start = last_pos[currChar] + 1;
				
			}
			int currLen = i - start + 1;
			if (longest < currLen){
				longest = currLen;
				//subs = s.substr(start, currLen);
			}
			last_pos[currChar] = i;
		}
		//cout << "subs: " << subs;
		return longest;
    }
	void run();
};

void Solution3::run(){
	std::cout << typeid( *this ).name() << std::endl;

	string case1 = "pwawkew";
	string case2 = "abcedfghijklmn";
	string case3 = "a";
	string case4 = "abba";
	string case5 = "abcabcbb";
	std::cout << lengthOfLongestSubstring(case1) << std::endl;
	std::cout << lengthOfLongestSubstring(case2) << std::endl;
	std::cout << lengthOfLongestSubstring(case3) << std::endl;
	std::cout << lengthOfLongestSubstring(case4) << std::endl;
	std::cout << lengthOfLongestSubstring(case5) << std::endl;
}

#endif