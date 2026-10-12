// 5.cpp —— 数学函数(cmath)与海伦公式求三角形面积
// 对应截图：images/5-P5708-triangle.png（Project5）
// 输入三角形三边长 a、b、c，输出面积(保留1位小数)
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double a;
    double b;
    double c;
    cout << "a, b, c为" << endl;
    cin >> a >> b >> c;
    cout << fixed << setprecision(1);
    double p = (a + b + c) / 2;
    double s = sqrt(p * (p - a) * (p - b) * (p - c));
    cout << "面积为" << s << endl;
    return 0;
}
