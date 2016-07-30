#ifndef _SOLUTION377_H_
#define _SOLUTION377_H_

#include <vector>
#include "Solution.h";

class Solution377 : public Solution{
public:
    int combinationSum4(vector<int>& nums, int target) {
        int *dp = new int[target+1];
		dp[0] = 1;
		for (int i = 1; i <= target; i++){
			int count = 0;
			for (int j = 0; j < nums.size(); ++j){
				if (i >= nums[j]){
					count += dp[i - nums[j]];
				}
			}
			dp[i] = count;
		}
		return dp[target];
    }
	void run();
};

void Solution377::run(){
	std::cout << "Solution377\n";
	int arr[5] = {1,3,5,7,9};
	vector<int> v;
	for (int i = 0; i < 5; i++)
		v.push_back(arr[i]);
	std::cout << combinationSum4(v, 10);
}

#endif