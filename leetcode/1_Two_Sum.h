#ifndef _SOLUTION1_H_
#define _SOLUTION1_H_

#include <vector>
#include "Solution.h";
#include <typeinfo.h>
#include <map>

class Solution1 : public Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashm;
        for (int i = 0; i < nums.size(); i++){
            hashm.insert(make_pair(nums[i], i));
        }
        map<int, int>::iterator it;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++){
            int search = target - nums[i];
            it = hashm.find(search);
            if (it != hashm.end() && it->second != i){
				res.push_back(i);
                res.push_back(it->second);
                return res;
            }
        }
		return res;
    }
	void run();
};

void Solution1::run(){
	std::cout << typeid( *this ).name() << std::endl;

	int arr[5] = {1,3,5,7,9};
	vector<int> v;
	for (int i = 0; i < 5; i++)
		v.push_back(arr[i]);
	
	vector<int> res = twoSum(v, 6);
	for (int i = 0; i < res.size(); i++){
		std::cout << res[i] << " ";
	}
}

#endif