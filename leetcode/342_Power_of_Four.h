#ifndef  __SOLUTION342_H__
#define  __SOLUTION342_H__
#include"Solution.h"


/*思路解析：
对于4的幂，其二进制表示中，只有1个位为1，且是在奇数位置。
如：
十进制		二进制
1			00000001
4			00000100
16			00010000
64			01000000
判断就分为两部分，一是判断是否二进制表示中只有一个1；二是判断这个1是否是在奇数位置
1、判断是否只有一个1
对于2次幂的判断，当一个数n减去1之后，最右端的1变为0，之后的全变为1。如果n与n-1按位求与，
则结果是0。因为如果含有多个1，那左端的1按位与之后还是1，结果为非0；
综上，可以依据n&(n-1)是否为0判断是否只含一个1。
2、判断1是否在奇数位上
因为通过1的验证之后得到的数，是只有一个1的，如果这个数与一个奇数位为1偶数为为0的数按位求与，
若这个数的1在奇数位，则结果为非零，否则结果为0
*/
class Solution342 : public Solution{
public:
    bool isPowerOfFour(int num) {
        if (num & (num-1))
			return false;
		return num & 0x55555555;
    }
	void run();
};

void Solution342::run(){
	//Solution342 s;
	int num;
	cout << "EOF to exit...\n";
	while (cin >> num){
		if (this->isPowerOfFour(num))
			cout << num << " is power of four.\n";
		else
			cout << num << " is not power of four.\n";
	}
}

#endif