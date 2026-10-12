// 1.cpp —— 字符输入输出与 ASCII 码运算
// 对应截图：images/1-P5704-char-out.png（Project3）
// 输入一个小写字母，输出其对应的大写字母（ASCII 码减 32）
#include <iostream>

using namespace std;

int main() {
    char a;
    cin >> a;
    a = a - 32;
    cout << a << endl;
    return 0;
}
