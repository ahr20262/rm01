// 4.cpp —— 级数求和：1 + 1/2 + 1/3 + … 加到大于 k 为止（浮点数循环）
// 对应截图：images/4-P1035-series.png
// 输入 k，输出使 Sn > k 的最小 n
#include <iostream>
using namespace std;

int main() {
	int n = 0;
	int k;
	cin >> k;
	double sn = 0;
	while (sn <= k) {
		n = n + 1;
		sn = sn + 1.0/n;
	}
	cout << n << endl;
		return 0;
}
