// 1.cpp —— 唱歌比赛：去掉一个最高分、一个最低分后的平均分（取最大）
// 对应截图：images/1-P5738-average.png
// 输入 n 名选手、m 位评委，逐人读 m 个分数，输出 n 人中「去掉最高最低后的平均分」的最大值
#include<iostream>
#include<string>
using namespace std;

int main() {
	int n = 0;
	int m = 0;
	double a = 0;
	double b = 0;
	double end = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		int maxs = 0;
		int mins = 1000;
		int score = 0;
		for (int j = 0; j < m; j++) {
			cin >> score;
			sum = sum + score;
			if (maxs < score) {
				maxs = score;
			}
			if (mins > score) {
				mins = score;
			}
		}
		double b = (sum - maxs - mins) / (m - 2);
		if (end < b) {
			end = b;
		}
	}
		cout << end << endl;
		return 0;
	}
