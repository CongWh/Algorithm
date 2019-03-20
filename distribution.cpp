/*
 *	泊淞分酒：三个酒杯：5L、8L、12L，相互倾倒，得到 7L 的酒水。 
 * 
*/
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// 需要的酒水量 
int res = 11;
// 三个杯子的容积 
int b1 = 12, b2 = 8, b3 = 5;
/*
 *  @param a1,a2,a3 分别为三个杯子中的酒水量
 *  method：首先，我们需要想出一个策略，即如何倒酒，倒酒的条件。
 *  由题意我们可以知道，第一个杯子最大，第二个次之，第三个最小。
 *  那么，我们优先将第二个杯子开始分析。1.当 b2 == 0 时，则考虑
 *  向其中注水；2.当 b2 >0 && b3 < a3 时，考虑向 b3 中注水；3.
 *  当 a3 == b3 时，考虑向 b1 中注水。 
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
