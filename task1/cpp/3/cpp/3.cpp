// 3.cpp —— 数字直角三角形（嵌套循环 + 前导零补位）
// 对应截图：images/3-P5721-triangle.png
// 输入 n，输出 n 行：第 c 行有 n-c+1 个两位数，且每行末尾额外输出下一个待打印的数
#include <iostream>
using namespace std;

int main() {
	int a = 0;
	cin >> a;
	int b = 1;
	for (int c = 1; c <= a; c++)
	{
		for (int d = 1; d <= a - c + 1; d++)
		{
			if (b < 10) {
			cout << "0" << b;
		} else {
			cout << b;
		}
			b++;
		}
		cout << b << endl;
	}
	return 0;
}
