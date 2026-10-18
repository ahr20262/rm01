// 2.cpp —— 纸张对折多少次后长度不足 1（while 循环 / 整数除法）
// 对应截图：images/2-P5720-fold.png
// 输入纸张长度，每次对折长度减半，输出折到长度 ≤ 1 所需天数
#include <iostream>

using namespace std;

int main()
{
	int a;
	cout << "长度为" << endl;
	cin >> a;
	int b = 1;
	while (a > 1) {
		a = a / 2;
		b = b + 1;
	}
	cout << "一共要" << b << "天" << endl;
	return 0;
}
