// 2.cpp —— 浮点数输入输出与定点小数格式化
// 对应截图：images/2-P5706-drinks.png（Project1）
// 输入饮料总量(升)和人数，输出人均饮料量(保留3位小数)与每人2杯所需杯子总数
#include <iostream>
#include <iomanip>   // 补充：setprecision 声明在 <iomanip> 中（截图顶部未截到该行）

using namespace std;

int main() {
    double a = 0;
    int b = 0;
    cout << "有多少饮料" << endl;
    cin >> a;
    cout << "有多少人" << endl;
    cin >> b;
    cout << fixed << setprecision(3);
    cout << "每人有" << a / b << endl;
    cout << "一共有" << b * 2 << "杯" << endl;
    return 0;
}
