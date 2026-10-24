// 5.cpp —— 培训：结构体作为函数参数与返回值（按值传递）
// 对应截图：images/5-P5744-training.png
// 输入 n 及 n 名学生（姓名 年龄 分数），每人年龄 +1、分数涨 20%（超过 600 按 600 算）后输出
#include <iostream>
#include <string>
using namespace std;

struct student
{
	string name;
	int age = 0;
	int f = 0;
};

student w(student s)
{
	s.age++;
	s.f = s.f * 1.2;
	if (s.f > 600) s.f = 600;
	return s;
}

int main() {
	int a = 0;
	cin >> a;
	for (int b = 0; b < a; b++)
	{
		student x;
		cin >> x.name >> x.age >> x.f;
		x = w(x);
		cout << x.name << " " << x.age << " " << x.f << endl;
	}
	return 0;
}
