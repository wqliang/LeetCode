#ifndef _SOLUTION347_H_
#define _SOLUTION347_H_

#include <vector>
#include <map>
#include <queue>
#include "Solution.h";

class Solution347 : public Solution{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> total;	//<number, count>
		map<int, int>::iterator mit;
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
			mit = total.find(*it);
			if (mit != total.end()){
				mit->second++;
			}
			else{
				total.insert(make_pair((*it), 1));
			}
		}
		priority_queue<pair<int, int> > priority_q;
		for (mit = total.begin(); mit != total.end(); mit++){
			priority_q.push(make_pair(mit->second, mit->first));
		}
		vector<int> result;
		for (int i = 0; i < k; i++){
			pair<int, int> obj = priority_q.top();
			priority_q.pop();
			result.push_back(obj.second);
		}
		return result;
    }
	void run();
};

void Solution347::run(){
	std::cout << "Solution347\n";
	int arr[15] = {1,1,1,1,1,2,2,2,2,3,3,3,4,4,5};
	vector<int> v;
	for (int i = 0; i < 15; i++)
		v.push_back(arr[i]);
	vector<int> result = topKFrequent(v, 3);
	for (int i = 0; i < result.size(); i++)
		std::cout << result[i] << endl;
}

#endif