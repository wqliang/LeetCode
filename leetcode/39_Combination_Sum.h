#ifndef _SOLUTION39_H_
#define _SOLUTION39_H_

#include <vector>
#include "Solution.h";
#include <typeinfo.h>
#include <algorithm>

class Solution39 : public Solution{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
		vector<int> path;
		dfs(candidates, 0, target, path, result);
		return result;
    }
	void dfs(const vector<int>& candidates, int start, int target, vector<int> path, vector<vector<int>> &result){
			if (0 == target){
				result.push_back(path);
				return ;
			}
			if (candidates[start] > target)
				return ;
			for (int i = start; i < candidates.size(); i++){
				path.push_back(candidates[i]);
				dfs(candidates, i, target - candidates[i], path, result);
				path.pop_back();
			}
	}
	void run();
};

void Solution39::run(){
	std::cout << typeid( *this ).name() << std::endl;
	int arr[5] = {1,3,5,7,9};
	vector<int> v;
	for (int i = 0; i < 5; i++)
		v.push_back(arr[i]);
	
	vector<vector<int>> res = combinationSum(v, 6);
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < res[i].size(); j++){
			std::cout << res[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

#endif