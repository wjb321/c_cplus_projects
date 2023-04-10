#include <stdio.h>

// 卡尔曼滤波参数
float Q = 0.001;
float R = 0.1;
float x = 0;
float P = 1;
float K;

// 更新卡尔曼滤波参数
void kalman_filter(float measurement) {
	// 预测下一时刻状态向量
	float x_predict = x;
	float P_predict = P + Q;

	// 更新卡尔曼增益
	K = P_predict / (P_predict + R);

	// 更新状态向量和状态协方差
	x = x_predict + K * (measurement - x_predict);
	P = (1 - K) * P_predict;
}

int main() {
	// 模拟高频脉冲值
	float pulse[] = { 10.0, 12.0, 11.0, 14.0, 10.0, 9.0, 13.0, 11.0, 12.0, 15.0 };

	// 遍历高频脉冲值并进行卡尔曼滤波
	for (int i = 0; i < 10; i++) {
		kalman_filter(pulse[i]);
		printf("高频脉冲值：%f，卡尔曼滤波值：%f\n", pulse[i], x);
	}
	getchar();
	return 0;
}
