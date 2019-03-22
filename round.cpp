/*
 * 	32�������ѭ������32���������κ����������������������ǵ����̡� 
 * 
 *  			1 2 3 4 5 6 7 8 
 *  			2 1 4 3 6 5 8 7
 *  			3 4 1 2 7 8 5 6
 *  			4 3 2 1 8 7 6 5
 *  			5 6 7 8 1 2 3 4
 *  			6 5 8 7 2 1 4 3
 *  			7 8 5 6 3 4 1 2
 *  			8 7 6 5 4 3 2 1 
 * 
*/
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

#define N 8

int res[N][N] = {0};


/*  ���η� 
 *  ���� NxN ���������
 *  @param n: ��ʱΪ n x n �ľ��� 
 *  method: ������ı���ϸ���������Կ����� 8x8 �ı���й��ɡ�8x8 ���Էֳ��ĸ� 4x4��
 *  4x4 �ֿ��Էֳ��ĸ� 2x2��2x2 �ֿ��Էֳ��ĸ� 1x1���ҿ��Է��֣����ϽǺ����½�һģһ
 *  ���������½Ǻ����Ͻ�һģһ�������ϽǺ����Ͻ��������Թ�ϵ�����Կɿ��Ƿ��η�������
 *  ���Ͻǵ� 1 ��ʼ���ɾ��� 
 *   
 */

void round(int n){
	if (n == 1)
		res[0][0] = 1;
	else{
		int m = n/2;
		round(m);
		
		int i, j;
		// �����Ͻ�
		for (i=0;i<m;i++)
			for (j=m;j<n;j++){
				res[i][j] = res[i][j-m] + m;
			}
		
		// �����½�
		for (i=m;i<n;i++)
			for (j=0;j<m;j++){
				res[i][j] = res[i-m][j] + m;
			}

		// �����½�
		for (i=m;i<n;i++)
			for (j=m;j<n;j++){
				res[i][j] = res[i-m][j-m];
			}	
			
	}
}


int main(){
	 
	round(N);
	
	for (int i=0;i<N;i++){
		for (int j=0;j<N;j++){
			cout << res[i][j] << " ";
		}	
		cout << endl;	
	}

	return 0;
}

 
