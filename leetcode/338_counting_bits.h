#ifndef  __SOLUTION338_H__
#define  __SOLUTION338_H__
#include"Solution.h"

#include<vector>

class Solution338 : public Solution{
public:
	vector<int> countBitws(int num);
	void run();
};

vector<int> Solution338::countBitws(int num){
	vector<int> v = vector<int>(num+1);
	v[0] = 0;
	for (int i = 1; i <= num; i++){
		v[i] = v[i/2]+(i%2);
	}
	return v;
}

void Solution338::run(){
	int num;
	cout << "EOF to end\n";
	while (cin >> num){
		vector<int> ans = this->countBitws(num);
		cout << "[";
		for (int i = 0; i < ans.size(); i++){
			if (i == ans.size()-1)
				cout << ans[i] << "]\n";
			else
				cout << ans[i] << ", ";
		}
	}
}

#endif