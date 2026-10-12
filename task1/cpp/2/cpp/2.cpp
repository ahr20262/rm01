// 2.cpp —— 按条件输出 0 或 1（逻辑运算符 ||、!、&& 组合练习）
// 对应截图：images/2-P5710-conditions.png（Project P5710）
// 输入整数 a，依次按 4 组条件分别输出 0 / 1
#include <iostream>

using namespace std;

int main() {
    int a = 0;
    cin >> a;
    if (a % 2 == 0 && a > 4 && a <= 12)
        cout << 1 << endl;
    else cout << 0 << endl;
    if (a % 2 == 0 || a > 4 && a <= 12)
        cout << 1 << endl;
    else cout << 0 << endl;
    if ((a % 2 == 0 && !(a > 4 && a <= 12)) || (!(a % 2 == 0) && (a > 4) && (a <= 12)))
        cout << 1 << endl;
    else cout << 0 << endl;
    if (a % 2 == 0 && a > 4 && a <= 12)
        cout << 0 << endl;
    else cout << 1 << endl;
    return 0;
}
