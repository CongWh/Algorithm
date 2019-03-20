/*
 *	�����־ƣ������Ʊ���5L��8L��12L���໥�㵹���õ� 7L �ľ�ˮ�� 
 * 
*/
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// ��Ҫ�ľ�ˮ�� 
int res = 11;
// �������ӵ��ݻ� 
int b1 = 12, b2 = 8, b3 = 5;
/*
 *  @param a1,a2,a3 �ֱ�Ϊ���������еľ�ˮ��
 *  method�����ȣ�������Ҫ���һ�����ԣ�����ε��ƣ����Ƶ�������
 *  ���������ǿ���֪������һ��������󣬵ڶ�����֮����������С��
 *  ��ô���������Ƚ��ڶ������ӿ�ʼ������1.�� b2 == 0 ʱ������
 *  ������עˮ��2.�� b2 >0 && b3 < a3 ʱ�������� b3 ��עˮ��3.
 *  �� a3 == b3 ʱ�������� b1 ��עˮ�� 
 */
void distribution(int a1, int a2, int a3){
	cout << "a1=" << a1 << " a2=" << a2 << " a3=" << a3 << endl;
	if (a1 == res || a2 == res || a3 == res){
		cout << "The method can be archived!" << endl;
		return;
	}
	if (a2 == 0){
		if (a1 + a2 <= b2)
			distribution(0, a1+a2, a3);
		else
			distribution(a1-(b2-a2), b2, a3);
	}
	else if (a3 < b3 && a2 > 0){
		if (a2 + a3 <= b3)
			distribution(a1, 0, a2+a3);
		else
			distribution(a1, a2-(b3-a3), b3);
	}
	else if (a3 == b3){
		if (a3 + a1 <= b1)
			distribution(a1+a3, a2, 0);
		else
			distribution(b1, b2, a3-(b1-a1));
	}
	
}


int main(){
	 
	distribution(12,0,0); 
	return 0;
}
