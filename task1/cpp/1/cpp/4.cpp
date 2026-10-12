// 4.cpp —— 整数输入与算术运算
// 对应截图：images/4-P5703-people.png（Project2）
// 输入人数，输出需要购买的饮料数（每人 10 瓶）
#include <iostream>

using namespace std;

int main() {
    int a = 0;
    cout << "有多少人" << endl;
    cin >> a;
    cout << "要买" << a * 10 << endl;
    return 0;
}
