#ifndef  __SOLUTION_H__
#define  __SOLUTION_H__
#include"Solution.h"
#include<vector>
#endif

class Solution334 : public Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
		int len = nums.size();
		if (len <= 0 )
			return false;
		vector<int> v;
		v.push_back(nums[0]);
		for (int i = 1; i < len; i++){
			int j = v.size()-1;
			if (v[j] < nums[i])
				v.push_back(nums[i]);
			else{
				while (--j >= 0){
					if (v[j] < nums[i]){
						v[j+1] = nums[i];
						break;
					}
				}
				if (j < 0 && v[0] > nums[i])
					v[0] = nums[i];
			}
		}
		int result = v.size();
		if (result >= 3)
			return true;
		else
			return false;
    }

	void run();
};

void Solution334::run(){
	cout << "ToDo\n";
}