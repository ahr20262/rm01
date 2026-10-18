// 7.cpp —— 校门外的树（标记数组 + 区间删除）
// 对应截图：images/7-P1047-trees.png
// 输入马路长度 L 和区间数 m，再输入 m 个区间 [u, v]；
// 输出未被任何区间覆盖的树的数量（0 ~ L 共 L+1 棵树）
#include <iostream>
using namespace std;

int main() {
    int L, m;
    cin >> L >> m;

    int flag[100000] = { 0 };

    for (int i = 0; i <= L; i++) {
        flag[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        for (int j = u; j <= v; j++) {
            flag[j] = 0;
        }
    }

    int ans = 0;
    for (int i = 0; i <= L; i++) {
        if (flag[i] == 1) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
