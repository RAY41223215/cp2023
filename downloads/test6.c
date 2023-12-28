#include <stdio.h>
#include <math.h>

#define G 9.8 // 重力加速度
#define DT 0.1 // 時間步長

void generateMotionData(FILE *file) {
    double t, m1_pos, m2_pos, m1_vel, m2_vel;
    double m1_pos_0 = 1.0; // m1 起始位置
    double m2_pos_0 = -0.5; // m2 起始位置
    double m1_vel_0 = 0.0; // m1 起始速度
    double m2_vel_0 = 0.0; // m2 起始速度
    double m1_acc = 0.0; // m1 加速度（這裡設為 0，您可以根據需要更改）
    double m2_acc = 0.0; // m2 加速度

    for (t = 0.0; t <= 10.0; t += DT) {
        // 更新 m1 與 m2 的位置和速度
        m1_pos = m1_pos_0 + m1_vel_0 * t + 0.5 * m1_acc * pow(t, 2);
        m2_pos = m2_pos_0 + m2_vel_0 * t + 0.5 * m2_acc * pow(t, 2);
        m1_vel = m1_vel_0 + m1_acc * t;
        m2_vel = m2_vel_0 + m2_acc * t;

        // 將數據寫入文件
        fprintf(file, "%lf %lf %lf %lf %lf\n", t, m1_pos, m2_pos, m1_vel, m2_vel);
    }
}

int main() {
    FILE *motionDataFile = fopen("motion_data.txt", "w");

    if (motionDataFile == NULL) {
        printf("Error opening motion_data.txt for writing.\n");
        return 1;
    }

    // 生成模擬數據
    generateMotionData(motionDataFile);

    // 關閉文件
    fclose(motionDataFile);

    // 使用 Gnuplot 繪製圖表
    FILE *gnuplotPipe = popen("gnuplot", "w");

    if (gnuplotPipe) {
        fprintf(gnuplotPipe, "set terminal png\n");
        fprintf(gnuplotPipe, "set output 'motion_plot.png'\n");
        fprintf(gnuplotPipe, "set xlabel 'Time'\n");
        fprintf(gnuplotPipe, "set ylabel 'Position / Velocity'\n");
        fprintf(gnuplotPipe, "plot 'motion_data.txt' using 1:2 with lines title 'm1 position', 'motion_data.txt' using 1:3 with lines title 'm2 position', 'motion_data.txt' using 1:4 with lines title 'm1 velocity', 'motion_data.txt' using 1:5 with lines title 'm2 velocity'\n");
        fprintf(gnuplotPipe, "exit\n");
        fflush(gnuplotPipe);
        pclose(gnuplotPipe);
    } else {
        printf("Error opening pipe to Gnuplot.\n");
        return 1;
    }

    return 0;
}