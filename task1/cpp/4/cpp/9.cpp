// 9.cpp —— 小鱼比可爱：统计每个数左边比它小的个数
// 对应截图：images/9-P1428-compare.png
// 输入 n 及 n 个数，对每个数输出它前面比它小的数的个数（结果连在一起输出，不加分隔符）
#include <iostream>
using namespace std;

int main() {
	int a = 0;
	cin >> a;
	int b[1000];
	for (int i = 0; i < a; i++) {
		cin >> b[i];
	}
	for (int c = 0; c < a; c++) {
		int d = 0;
		for (int e = 0; e < c; e++) {
			if (b[e] < b[c]) {
				d++;
			}
		}
		cout << d;
	}
	return 0;
}
