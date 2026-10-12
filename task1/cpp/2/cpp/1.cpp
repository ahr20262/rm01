// 1.cpp —— 闰年判断（逻辑运算符 &&、!）
// 对应截图：images/1-P5711-leap-year.png（Project P5711.0）
// 输入年份，是闰年输出 1，否则输出 0
#include <iostream>

using namespace std;

int main() {
    int a;
    cout << "年份为" << endl;
    cin >> a;
    if (a % 4 == 0 && a % 100 != 0)
        cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}
