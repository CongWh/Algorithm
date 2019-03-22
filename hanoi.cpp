/*
 *	��ŵ�����������ӣ����Բ������С�����ۻ�����һ�����ӣ���
 *  ����Ų��ʱ��������Բ��������С��Բ�����档 
 *  Ҫ����������е�Բ���Ƶ����������ӵĲ����� 
 * 
*/
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// ������������ 
int count = 0;

/*
 *  ��ŵ������	A   B   C	
 *  method: ����һ�����͵ĵݹ����⡣��֪ A��B��C �������ӣ� N��Բ���� 
 *  �ɵݹ��˼�룬�����Ϊһ�������⣺1.���һ��Բ���϶��Ǵ� A-->C��
 *  2.ǰ�� n-1 ��Բ���϶��ǽ��� C �� A �Ƶ� B��2.�����һ��Բ���Ƶ� C
 *  ֮��n-1 ��Բ���϶������ A �Ƶ� C�� 
 *
 */
void Hanoi(int n, char from, char transit, char to){
	if (n == 0){
		return ;
	}
	Hanoi(n-1, from, to, transit);
	cout << "Step " << ++count << ": " << n << " from " << from << " to " << to << endl;
	Hanoi(n-1, transit, from, to);
}

int main(){
	 
	Hanoi(6,'A','B','C');
	return 0;
}

 
