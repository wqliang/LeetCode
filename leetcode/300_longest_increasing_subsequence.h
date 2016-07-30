#ifndef  __SOLUTION300_H__
#define  __SOLUTION300_H__
#include"Solution.h"

#include<vector>
using namespace std;

class Solution300 : public Solution {
public:
    int increasingTriplet(vector<int>& nums) {
		int len = nums.size();
		if (len <= 0 )
			return 0;
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
		return v.size();
    }

	void run();
};

void Solution300::run(){
	int a[] = {10,9,2,5,3,7,101,18};
	vector<int> v(a, a+8);
	cout << this->increasingTriplet(v);
}

#endif