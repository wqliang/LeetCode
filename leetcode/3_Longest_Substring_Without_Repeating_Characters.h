#ifndef _SOLUTION3_H_
#define _SOLUTION3_H_

#include <string>
#include "Solution.h";
#include <typeinfo.h>

class Solution3 : public Solution{
public:
    int lengthOfLongestSubstring(string s) {
        int last_pos[200];	//�����¼ÿ���ַ����һ�γ��ֵ�λ��
		for (int i = 0; i < 200; i++)
			last_pos[i] = -1;
		//start��ǵ�ǰû���ظ��ַ����Ӵ��Ŀ�ʼλ��
		int start = 0;
		int longest = 0;
		//string subs;
		for (int i = 0; i < s.length(); i++){
			char currChar = s[i];
			//��һ�������жϵ�ǰ�ַ���֮ǰ�Ѿ����ֹ���
			//�ڶ���������ֹ��abba�����ַ�����last['a'] = 0,��������s[3]='a'ʱ��start=2��
			//�����start��Ϊlast['a']+1����ô�Ӵ�Ϊ"bba",�������ظ��ַ�
			if (last_pos[currChar] != -1 && last_pos[currChar] >= start){			
				//��start��i-1���Ӵ��ǲ��ظ��ģ���start��i���ظ��ģ�
				//[i]��[start, i-1]�е�ĳ��λ���ϵ��ַ�һ����
				//���ַ�[i]��һ�γ��ֵ�λ����last_pos[s[i]]��
				//���Դ�last_pos[]+1��i����ϵ��ַ��ǲ��ظ���
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