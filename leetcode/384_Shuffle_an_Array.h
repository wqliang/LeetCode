#ifndef _S384_H_
#define _S384_H_

#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;
class Solution384 : public Solution{
public:
	Solution384(vector<int> nums){
        for (int i = 0; i < nums.size(); i++){
            v.push_back(nums[i]);
        }
    }
	Solution384(){
	}
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return v;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int size = v.size();
        vector<int> ret(v);
        while (size > 0){
            int index = rand() % size;
            size--;
            int tmp = ret[index];
            ret[index] = ret[size];
            ret[size] = tmp;
        }
		return ret;
    }

	void run();
private:
    vector<int> v;
};

void Solution384::run(){
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(7);
	Solution384* obj = new Solution384(nums);
	vector<int> param_1 = obj->reset();
	vector<int> param_2 = obj->shuffle();
}

#endif