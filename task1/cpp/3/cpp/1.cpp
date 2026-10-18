// 1.cpp —— 求 n 个数中的最小值（循环 + 打擂台）
// 对应截图：images/1-P5718-min.png
// 输入 n，再输入 n 个整数，输出其中的最小值（题面数据范围 1~1000，故用 1001 作哨兵）
#include <iostream>
using namespace std;

int main() {

	int a;
	cin >> a;
	int b = 1001;
	for (int c = 0; c < a; c++) {
		int d;
		cin >> d;
		if (d < b) {
			b = d;
		}
	}

	cout << b << endl;
	return 0;
}
