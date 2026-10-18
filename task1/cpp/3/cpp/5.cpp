// 5.cpp —— 小玉在游泳：速度每小时递减 2%，求游泳时间
// 对应截图：images/5-P1423-swim.png
// 输入目标距离 a，输出游到 a 米所需时间（每秒距离依次为 2, 2*0.98, 2*0.98^2 …）
#include <iostream>
using namespace std;

int main() {
	double a = 0;
	double s = 0;
	double b = 2;
	int c = 0;
	cin >> a;
	while (s <= a) {
		s = s + b;
		b = b * 0.98;
		c++;
	}
	cout << c << endl;
	return 0;
}
