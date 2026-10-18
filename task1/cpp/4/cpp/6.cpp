// 6.cpp —— 陶陶摘苹果（数组 + 计数）
// 对应截图：images/6-P1046-apples.png
// 先输入 10 个苹果高度，再输入陶陶身高；能摘到的苹果 = 高度 ≤ 身高+30（手伸直的长度）的个数
#include <iostream>
using namespace std;

int main() {
	cout << "🍎高度" << endl;
	int a[10];
	for (int i = 0; i < 10; i++) {
		cin >> a[i];
	}
	cout << "陶陶身高为" << endl;
	int b = 0;
	cin >> b;
	int c = 0;
	c = b + 30;
	int d = 0;
	for (int j = 0; j < 10; j++) {
		if (a[j] <= c)
		{
			d++;
		}
	}
	cout << d << endl;
	return 0;
}
