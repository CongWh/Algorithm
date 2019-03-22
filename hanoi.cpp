/*
 *	汉诺塔：三个柱子，多个圆环（从小到大累积到第一个柱子），
 *  规则：挪动时不允许大的圆环放置在小的圆环上面。 
 *  要求：求出将所有的圆环移到第三个柱子的步数。 
 * 
*/
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// 计数：步骤数 
int count = 0;

/*
 *  求汉诺塔问题	A   B   C	
 *  method: 这是一个典型的递归问题。已知 A、B、C 三根柱子， N个圆环。 
 *  由递归的思想，将其简化为一个子问题：1.最后一个圆环肯定是从 A-->C；
 *  2.前面 n-1 个圆环肯定是借助 C 从 A 移到 B；2.当最后一个圆盘移到 C
 *  之后，n-1 个圆环肯定会借助 A 移到 C。 
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

 
