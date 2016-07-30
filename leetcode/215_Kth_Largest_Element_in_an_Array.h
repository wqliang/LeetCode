#ifndef _SOLUTION215_H_
#define _SOLUTION215_H_

#include <vector>
#include <queue>
#include "Solution.h";

class Solution215 : public Solution{
public:
    int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int> p_que;
		int count = 0;
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++){
			if (count < k){
				p_que.push(-(*it));
				++count;
			}
			else{
				if ((*it) > p_que.top() * (-1)){
					p_que.pop();
					p_que.push(-(*it));
				}
			}
		}
		return p_que.top()*(-1);
    }
	void run();
};

void Solution215::run(){
	std::cout << "Solution215\n";
	int arr[15] = {1,1,1,1,1,2,2,2,2,3,3,3,4,4,5};
	vector<int> v;
	for (int i = 0; i < 15; i++)
		v.push_back(arr[i]);
	std::cout << findKthLargest(v, 3);
}

#endif