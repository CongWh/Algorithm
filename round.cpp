/*
 * 	32个队伍的循环赛：32个队伍依次和其他队伍比赛，请输出它们的赛程。 
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


/*  分治法 
 *  对于 NxN 矩阵的制造
 *  @param n: 此时为 n x n 的矩阵 
 *  method: 如上面的表，仔细分析，可以看出该 8x8 的表很有规律。8x8 可以分成四个 4x4，
 *  4x4 又可以分成四个 2x2。2x2 又可以分成四个 1x1。且可以发现，左上角和右下角一模一
 *  样。而左下角和右上角一模一样。右上角和左上角又有线性关系。所以可考虑分治法，先由
 *  左上角的 1 开始生成矩阵。 
 *   
 */

void round(int n){
	if (n == 1)
		res[0][0] = 1;
	else{
		int m = n/2;
		round(m);
		
		int i, j;
		// 填右上角
		for (i=0;i<m;i++)
			for (j=m;j<n;j++){
				res[i][j] = res[i][j-m] + m;
			}
		
		// 填左下角
		for (i=m;i<n;i++)
			for (j=0;j<m;j++){
				res[i][j] = res[i-m][j] + m;
			}

		// 填右下角
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

 
