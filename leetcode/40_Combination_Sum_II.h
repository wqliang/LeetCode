#ifndef _SOLUTION40_H_
#define _SOLUTION40_H_

#include <vector>
#include "Solution.h";
#include <typeinfo.h>
#include <algorithm>

class Solution40 : public Solution{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
		if (start < candidates.size()){
			if (candidates[start] > target)
				return ;
			for (int i = start; i < candidates.size(); i++){
				if (i != start && candidates[i] == candidates[i-1])
					continue;
				path.push_back(candidates[i]);
				dfs(candidates, i+1, target - candidates[i], path, result);
				path.pop_back();
			}
		}
	}
	void run();
};

void Solution40::run(){
	std::cout << typeid( *this ).name() << std::endl;
	int arr[5] = {1,3,5,7,9};
	vector<int> v;
	for (int i = 0; i < 5; i++)
		v.push_back(arr[i]);
	
	vector<vector<int>> res = combinationSum2(v, 6);
	for (int i = 0; i < res.size(); i++){
		for (int j = 0; j < res[i].size(); j++){
			std::cout << res[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

#endif