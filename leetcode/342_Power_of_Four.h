#ifndef  __SOLUTION342_H__
#define  __SOLUTION342_H__
#include"Solution.h"


/*˼·������
����4���ݣ�������Ʊ�ʾ�У�ֻ��1��λΪ1������������λ�á�
�磺
ʮ����		������
1			00000001
4			00000100
16			00010000
64			01000000
�жϾͷ�Ϊ�����֣�һ���ж��Ƿ�����Ʊ�ʾ��ֻ��һ��1�������ж����1�Ƿ���������λ��
1���ж��Ƿ�ֻ��һ��1
����2���ݵ��жϣ���һ����n��ȥ1֮�����Ҷ˵�1��Ϊ0��֮���ȫ��Ϊ1�����n��n-1��λ���룬
������0����Ϊ������ж��1������˵�1��λ��֮����1�����Ϊ��0��
���ϣ���������n&(n-1)�Ƿ�Ϊ0�ж��Ƿ�ֻ��һ��1��
2���ж�1�Ƿ�������λ��
��Ϊͨ��1����֤֮��õ���������ֻ��һ��1�ģ�����������һ������λΪ1ż��ΪΪ0������λ���룬
���������1������λ������Ϊ���㣬������Ϊ0
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