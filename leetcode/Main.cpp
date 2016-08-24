#include<iostream>
#include<map>
#include<stdlib.h>
#include "Solution.h"
#include "solution_header.h"

map<int, void*> solution_table;

void _solution_table(int no, void* sptr){
	solution_table.insert(make_pair(no, sptr));
}

void _init(){
	_solution_table(1, new Solution1());
	_solution_table(3, new Solution3());
	_solution_table(39, new Solution39());
	_solution_table(40, new Solution40());
	_solution_table(215, new Solution215());
	_solution_table(300, new Solution300());
	_solution_table(338, new Solution338());
	_solution_table(342, new Solution342());
	_solution_table(343, new Solution343());
	_solution_table(344, new Solution344());
	_solution_table(347, new Solution347());
	_solution_table(377, new Solution377());
	//_solution_table(384, new Solution384());
}

int main(){
	_init();
	int no = 384;
	Solution* s = reinterpret_cast<Solution*>(solution_table[no]);
	s->run();
	
	system("pause");
	return 0;
}