// 3.cpp —— 旗鼓相当的对手：结构体数组 + 双重循环比较
// 对应截图：images/3-P5741-rivals.png
// 输入 n 及 n 名学生（姓名 语文 数学 英语），
// 若两人总分差 ≤10 且三科各自差 ≤5，则视为「旗鼓相当的对手」并输出两人的姓名
#include<iostream>
#include<string>
using namespace std;
struct student {
	string name;
	int cn = 0;
	int ma = 0;
	int eg = 0;
	int total = 0;

};
student x[1001];

int main() {
	int a = 0;
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> x[i].name >> x[i].cn >> x[i].ma >> x[i].eg;
		x[i].total = x[i].cn + x[i].ma + x[i].eg;
	}
	for (int i = 0; i < a; i++) {
		for (int b = i + 1; b < a; b++) {
			if (abs(x[i].total - x[b].total) <= 10 && abs(x[i].cn - x[b].cn) <= 5 && abs(x[i].ma - x[b].ma) <= 5 && abs(x[i].eg - x[b].eg) <= 5) {
				cout << x[i].name << "  " << x[b].name << endl;
			}
		}
	}
	return 0;
}
