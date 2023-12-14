// 包含標準輸出入程式庫的標頭文件
#include <stdio.h>

// 主函式
int main() {
    // 打開一個文件以寫入位移和速度數據
    FILE *outputFile = fopen("motion_data.txt", "w");
    if (!outputFile) {
        fprintf(stderr, "Failed to create data file.\n");
        return 1;
    }

    // 模擬運動10秒並計算位移和速度，同時將數據寫入文件
    double x = 0.2; // 初始位移
    double v = 0.0; // 初始速度
    double dt = 0.01; // 時間步長
    double t = 0.0; // 時間

    while (t <= 10.0) {
        double acceleration = (-10.0 * x - 0.5 * v) / 1.0; // 修改系統參數
        v += acceleration * dt;
        x += v * dt;

        fprintf(outputFile, "%lf %lf %lf\n", t, x, v);

        t += dt;
    }

    // 關閉數據文件
    fclose(outputFile);

    // 啟動Gnuplot進程
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (!gnuplotPipe) {
        fprintf(stderr, "Failed to start Gnuplot.\n");
        return 1;
    }

    // 使用Gnuplot繪圖命令，指定字體並輸出為PNG
    fprintf(gnuplotPipe, "set terminal pngcairo enhanced font 'default,10' size 800,400\n");
    fprintf(gnuplotPipe, "set output './../images/motion_plot.png'\n");
    fprintf(gnuplotPipe, "set title 'Displacement and Velocity vs. Time'\n");
    fprintf(gnuplotPipe, "set xlabel 'Time (s)'\n");
    fprintf(gnuplotPipe, "set ylabel 'Displacement (m)'\n");
    fprintf(gnuplotPipe, "plot 'motion_data.txt' using 1:2 with lines lw 2 title 'Displacement', \
    'motion_data.txt' using 1:3 with lines lw 2 title 'Velocity'\n");

    // 關閉Gnuplot進程
    fprintf(gnuplotPipe, "exit\n");
    pclose(gnuplotPipe);

    return 0;
}