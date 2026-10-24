// 4.cpp —— 评等级：结构体 + 函数返回字符串
// 对应截图：images/4-P5742-grade.png
// 输入 n 及 n 名学生（学号 平时分 期末分），
// 平时分+期末分 > 140 且 平时分*7+期末分*3 ≥ 800 输出 Excellent，否则 Not excellent
#include <iostream>
#include <string>
using namespace std;

struct student
{
	int id = 0;
	int per = 0;
	int ex = 0;
};

string aa(student x)
{
	if (x.per + x.ex > 140 && x.per * 7 + x.ex * 3 >= 800)
	{
		return "Excellent";
	}
	else {
		return "Not excellent";
	}
}

int main() {
	int a = 0;
	cin >> a;
	for (int d = 0; d < a; d++) {
		student x;
		cin >> x.id >> x.per >> x.ex;
		cout << aa(x) << endl;
	}
	return 0;
}
