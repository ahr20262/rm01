// 8.cpp —— 小鱼的数字游戏：读到 0 结束，倒序输出
// 对应截图：images/8-P1427-reverse.png
// 连续读入整数直到读到 0（0 不输出、也不入列），把之前的数倒序输出
#include <iostream>
using namespace std;

int main() {
	int a[1000];
	int b = 0;
	while (true) {
		cin >> a[b];
		if (a[b] == 0) {
			break;
		}
		b = b + 1;
	}
	for (int c = b - 1; c > 0; c = c - 1) {
		cout << a[c] << " ";
	}
	return 0;
}
