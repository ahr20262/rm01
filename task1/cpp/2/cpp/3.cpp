// 3.cpp —— BMI 计算与多分支判断
// 对应截图：images/3-P5714-bmi.png（Project P5714）
// 输入体重 m(kg) 和身高 h(m)，按 BMI 输出 underweight / normal / BMI值+overweight
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double m;
    double h;
    cin >> m;
    cin >> h;
    double i = m / (h * h);
    if (i < 18.5)
    {
        cout << "underweight" << endl;
    }
    else if (i >= 18.5 && i < 24)
    {
        cout << "normal" << endl;
    }
    else
    {
        cout << i << endl;
        cout << "overweight" << endl;
    }
    return 0;
}
