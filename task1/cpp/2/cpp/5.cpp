// 5.cpp —— 整数除法（向下取整）
// 对应截图：images/5-P5709-eat-speed.png（Project P5709）
// 输入 苹果数 m、时间 s、速度 t，输出还能吃几个（s / t）
#include <iostream>

using namespace std;

int main() {
    int m, t, s;
    cout << "输入🍎，耗时，已过" << endl;

    cin >> m >> t >> s;
    int eat = s / t;
    cout << m - eat << endl;
    return 0;
}
