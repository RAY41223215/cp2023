#include <stdio.h>
#include <gd.h>

int main() {
    // 國旗尺寸
    int width = 1200;
    int height = 600;

    // 創建圖像
    gdImagePtr img = gdImageCreate(width, height);

    // 設置白色背景
    int white = gdImageColorAllocate(img, 255, 255, 255);
    gdImageFilledRectangle(img, 0, 0, width, height, white);

    // 計算中間紅點的直徑和位置
    int circleDiameter = height * 3 / 5;
    int circleRadius = circleDiameter / 2;
    int circleX = width / 2;
    int circleY = height / 2;

    // 設置紅色圓圈
    int red = gdImageColorAllocate(img, 255, 0, 0);
    gdImageFilledEllipse(img, circleX, circleY, circleDiameter, circleDiameter, red);

    // 儲存圖像
    FILE *output = fopen("japan_flag.png", "wb");
    if (output == NULL) {
        fprintf(stderr, "Error creating output file\n");
        return 1;
    }

    gdImagePng(img, output);
    fclose(output);

    // 釋放記憶體
    gdImageDestroy(img);

    return 0;
}