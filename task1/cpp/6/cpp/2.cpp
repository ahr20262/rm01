// 2.cpp —— 最厉害的学生：结构体 + 打擂台求总分最高者
// 对应截图：images/2-P5740-best-student.png
// 输入 n 及 n 名学生（姓名 语文 数学 英语），输出总分最高的那位（并列时取先出现者）
#include <iostream>
#include <string>
using namespace std;
struct student
{
	int cn = 0;
	int maths = 0;
	int eg = 0;
	int total = 0;
	string name;
};


int main() {
	int a = 0;
	cin >> a;
	student best;
	student best2;
	cin >> best.name >> best.cn >> best.maths >> best.eg;
	best.total = best.cn + best.maths + best.eg;
	for (int b = 1; b < a; b++) {
		cin >> best2.name >> best2.cn >> best2.maths >> best2.eg;
		best2.total = best2.cn + best2.maths + best2.eg;

		if (best.total < best2.total)
		{
			best = best2;
		}

	}
	cout << best.name << "  " << best.cn << "  " << best.maths << "  " << best.eg << endl;
	return 0;
}
