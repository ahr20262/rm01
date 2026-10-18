// 10.cpp —— 珠心算测验：统计有多少个数能由集合中另外两个不同数相加得到
// 对应截图：images/10-P2141-count.png
// 输入 n 及 n 个数，输出「能表示为另外两个数之和」的数的个数
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[105];
    bool exists[20005] = { false };

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        exists[a[i]] = true;
    }

    bool isSum[20005] = { false };

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int s = a[i] + a[j];
            if (s <= 20000) {
                isSum[s] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (isSum[a[i]]) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
