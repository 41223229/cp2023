#include <stdio.h>
#include <math.h>

#define TIME_STEP 0.01 // 時間步長
#define SIMULATION_TIME 10.0 // 模擬時間

// 物體參數
#define m1 2.0
#define m2 3.0
#define k1 0.5
#define k2 1.0
#define k3 1.5
#define c1 0.25
#define c2 0.33
#define c3 0.5
#define X1_initial 1.0
#define X2_initial -0.5
#define V0 0.0

// 計算阻尼力
double dampingForce(double c, double v) {
    return -c * v;
}

// 模擬物體運動
void simulateMotion() {
  double X1 = X1_initial;
  double X2 = X2_initial;
  double V1 = V0;
  double V2 = V0;

  FILE *fp;
  fp = fopen("motion_data.txt", "w");

  for (double t = 0; t <= SIMULATION_TIME; t += TIME_STEP) {
  double F1 = -k1 * (X1 - 0) - c1 * (V1 - 0); // 第一個物體受到的合力
  double F2 = -k2 * (X2 - X1) - c2 * (V2 - V1); // 第二個物體受到的合力
  double F3 = -k3 * (X2 - 0) - c3 * (V2 - 0); // 第二個物體受到的合力

  double a1 = F1 / m1; // 第一個物體的加速度
  double a2 = F2 / m2; // 第二個物體的加速度

// 更新速度和位置
   V1 += a1 * TIME_STEP;
   V2 += a2 * TIME_STEP;

  X1 += V1 * TIME_STEP;
  X2 += V2 * TIME_STEP;

// 在文件寫入時紀錄 m1 和 m2 的位置和速度數據
  fprintf(fp, "%lf %lf %lf %lf %lf\n", t, X1, X2, V1, V2);
    }


  fclose(fp);
}

int main() {
    simulateMotion();
    return 0;
}
