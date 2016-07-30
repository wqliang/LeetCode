#ifndef  __SOLUTION343_H__
#define  __SOLUTION343_H__
#include"Solution.h"


class Solution343 : public Solution {
private:
	int* dp;
	const int max_size;
public:
	Solution343():max_size(1000){
		dp = new int[max_size];
		dp[2] = 1;
		for (int i = 3; i < max_size; i++)
			dp[i] = 0;
	}
    int integerBreak(int n) {
        if (n == 2)
			return 1;
		if (n < max_size && dp[n] != 0)
			return dp[n];
		int bound = n / 2;
		int max = 0;
		for (int i = 1; i <= bound; i++){
			int tmp = integerBreak(n-i);
			if (tmp < n-i)
				tmp = n-i;
			tmp = tmp * i;
			if (tmp > max)
				max = tmp;
		}
		dp[n] = max;
		return max;
    }

	void run();
};

void Solution343::run(){
	cout << this->integerBreak(2) << endl;
	cout << this->integerBreak(10) << endl;
	cout << this->integerBreak(99) << endl;
}

#endif