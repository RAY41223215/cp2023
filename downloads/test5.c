#include <stdio.h>
#include <gd.h>
#include <math.h>
//程式使用工具
#define WIDTH 900
#define HEIGHT 600
#define FILENAME "south_korea_flag.png"
//定義 寬高
int main() {
    gdImagePtr im;
    FILE *pngout;
    int white, black, red, blue;

    im = gdImageCreate(WIDTH, HEIGHT);

    white = gdImageColorAllocate(im, 255, 255, 255);
    black = gdImageColorAllocate(im, 0, 0, 0);
    red = gdImageColorAllocate(im, 205, 0, 0);
    blue = gdImageColorAllocate(im, 0, 56, 168);
//這段在調色
    // Background (white)
    gdImageFilledRectangle(im, 0, 0, WIDTH, HEIGHT , white);
//gdImageFilledRectangle瑱充顏色
    // Blue Circle (Yin-Yang Symbol)
    gdImageFilledArc(im, WIDTH / 2, HEIGHT / 2, WIDTH / 3, HEIGHT / 2, 210, 30, red, gdArc);

    // Red Circle (Yin-Yang Symbol)
    gdImageFilledArc(im, WIDTH / 2, HEIGHT / 2, WIDTH / 3, HEIGHT / 2, 30, 210, blue, gdArc);
//gdImageFilledArc(im, WIDTH / 2, HEIGHT / 2, WIDTH / 3, HEIGHT / 2, 210, 30, red, gdArc);

  //im: GD 圖像指標。
  //WIDTH / 2 和 HEIGHT / 2: 圓心的 X 和 Y 座標，分別設定為圖像寬度和高度的一半，即圖像中心。
  //WIDTH / 3: 圓的寬度，設定為圖像寬度的三分之一，確保圓不會超出圖像範圍。
  //HEIGHT / 2: 圓的高度，設定為圖像高度的一半。
  //210 和 30: 起始和結束的角度（以度為單位），這樣設定形成了圓弧。
  //red: 圓弧的顏色，這裡是紅色。
  //gdArc: 繪製圓弧，而不是整個圓。
  //gdImageFilledArc(im, WIDTH / 2, HEIGHT / 2, WIDTH / 3, HEIGHT / 2, 30, 210, blue, gdArc);

  //這行與前一行類似，唯一的區別在於起始和結束的角度以及使用的顏色。這裡的起始角度為30度，結束角度為210度，並且使用的顏色是藍色
  int circleX = 385;    // 圓心的 X 座標
  int circleY = 262.5;   // 圓心的 Y 座標
  int circleRadius = 75;    

  // 繪製圓形
  gdImageFilledEllipse(im, circleX, circleY, circleRadius * 2, circleRadius * 2, red);

  int circleX2 = 515;    // 圓心的 X 座標

 int circleY2 = 337.5;

  // 繪製圓形
  gdImageFilledEllipse(im, circleX2, circleY2, circleRadius * 2, circleRadius * 2, blue);

  {


  // 起點和終點位置

  int startX = 340;   
  // 線的起點 X 座標

  int startY = 90;  
  // 線的起點 Y 座標

  int endX = 200;    
  // 線的終點 X 座標

  int endY = 260;    
  // 線的終點 Y 座標

  int lineWidth = 23;  // 線的寬度

  // 繪製線段
  gdImageSetThickness(im, lineWidth);
  gdImageLine(im, startX, startY, endX, endY, black);
  // 繪製線段
  gdImageSetThickness(im, lineWidth);
  gdImageLine(im, startX -35, startY -10, endX -35, endY -10, black);

  // 繪製線段
  gdImageSetThickness(im, lineWidth);
  gdImageLine(im, startX -70, startY -20, endX -70, endY -20, black);

  int startX2 = 213;   
  // 線的起點 X 座標

  int startY2 = 270;  
  // 線的起點 Y 座標

  int endX2 = 133;    
  // 線的終點 X 座標

  int endY2 = 210;    
  // 線的終點 Y 座標

  int lineWidth2 = 25;  // 線的寬度

  // 繪製線段
  gdImageSetThickness(im, lineWidth);
  gdImageLine(im, startX2 +3, startY2, endX2 +3, endY2, white);

  gdImageSetThickness(im, lineWidth +10);
gdImageLine(im, startX2 -17, startY2 +9 , endX2 -17, endY2 +9 , white);

  gdImageSetThickness(im, lineWidth );
gdImageLine(im, startX2 +115, startY2 -145, endX2 +115, endY2 -145, white);

  gdImageSetThickness(im, lineWidth);
gdImageLine(im, startX2 +120, startY2 -155, endX2 +120, endY2 -155, white);

  gdImageSetThickness(im, lineWidth +12);
gdImageLine(im, startX2 +145, startY2 -155, endX2 +145, endY2 -155, white);
}
  {
    // 起點和終點位置

  int startX = 330;   
  // 線的起點 X 座標

  int startY = 520;  
  // 線的起點 Y 座標

  int endX = 190;    
  // 線的終點 X 座標

  int endY = 350;    
  // 線的終點 Y 座標

  int lineWidth = 23;  // 線的寬度

  // 繪製線段
  gdImageSetThickness(im, lineWidth);
  gdImageLine(im, startX, startY, endX, endY, black);
  // 繪製線段
  gdImageSetThickness(im, lineWidth);
  gdImageLine(im, startX -35, startY +10, endX -35, endY +10, black);

  // 繪製線段
  gdImageSetThickness(im, lineWidth);
  gdImageLine(im, startX -70, startY +20, endX -70, endY +20, black);

  int startX2 = 213;   
  // 線的起點 X 座標

  int startY2 = 330;  
  // 線的起點 Y 座標

  int endX2 = 133;    
  // 線的終點 X 座標

  int endY2 = 390;    
  // 線的終點 Y 座標

  int lineWidth2 = 25;  // 線的寬度

  // 繪製線段
  gdImageSetThickness(im, lineWidth +8);
  gdImageLine(im, startX2 -11, startY2, endX2 -11, endY2, white);

  gdImageSetThickness(im, lineWidth +10);
gdImageLine(im, startX2 -30, startY2 -9 , endX2 -30, endY2 -9 , white);

  gdImageSetThickness(im, lineWidth );
gdImageLine(im, startX2 +100, startY2 +150, endX2 +100, endY2 +150, white);

  gdImageSetThickness(im, lineWidth);
gdImageLine(im, startX2 +120, startY2 +155, endX2 +120, endY2 +155, white);

  gdImageSetThickness(im, lineWidth +14);
gdImageLine(im, startX2 +145, startY2 +157, endX2 +145, endY2 +157, white);

    gdImageSetThickness(im, lineWidth -10);
gdImageLine(im, 232, 426, 206, 448, white);

  }

  {
    // 起點和終點位置

  int startX = 564;   
  // 線的起點 X 座標

  int startY = 520;  
  // 線的起點 Y 座標

  int endX = 704;    
  // 線的終點 X 座標

  int endY = 350;    
  // 線的終點 Y 座標

  int lineWidth = 23;  // 線的寬度

  // 繪製線段
  gdImageSetThickness(im, lineWidth);
  gdImageLine(im, startX +70, startY +20, endX +70, endY +20, black);

    // 繪製線段
  gdImageSetThickness(im, lineWidth);
  gdImageLine(im, startX, startY, endX, endY, black);

    // 繪製線段
  gdImageSetThickness(im, lineWidth);
  gdImageLine(im, startX +35, startY +10, endX +35, endY +10, black);

gdImageSetThickness(im, lineWidth -10);
gdImageLine(im, 624, 400, 734, 490, white);

  int startX2 = 553;   
  // 線的起點 X 座標

  int startY2 = 330;  
  // 線的起點 Y 座標

  int endX2 = 633;    
  // 線的終點 X 座標

  int endY2 = 390;    
  // 線的終點 Y 座標

  int lineWidth2 = 25;  // 線的寬度

  // 繪製線段
  gdImageSetThickness(im, lineWidth +8);
  gdImageLine(im, startX2 +139, startY2, endX2 +139, endY2, white);

  gdImageSetThickness(im, lineWidth +10);
gdImageLine(im, startX2 +157, startY2 -9 , endX2 +157, endY2 -9 , white);

  gdImageSetThickness(im, lineWidth);
gdImageLine(im, startX2 +25, startY2 +155, endX2 +25, endY2 +155, white);

  gdImageSetThickness(im, lineWidth +30);
gdImageLine(im, startX2 -3, startY2 +170, endX2 , endY2 +170, white);
  }
    //gdImageSetThickness(im, lineWidth +8);

  //設定線段的寬度，這裡是將原本的 lineWidth 加上 8。
  //gdImageLine(im, startX2 +139, startY2, endX2 +139, endY2, white);

  //繪製一條線段，起點座標為 (startX2 + 139, startY2)，終點座標為 (endX2 + 139, endY2)，線段的顏色是白色。
  //gdImageSetThickness(im, lineWidth +10);

  //設定另一條線段的寬度，這裡是將原本的 lineWidth 加上 10。
  //gdImageLine(im, startX2 +157, startY2 -9 , endX2 +157, endY2 -9 , white);

  //繪製另一條線段，起點座標為 (startX2 + 157, startY2 - 9)，終點座標為 (endX2 + 157, endY2 - 9)，線段的顏色是白色。
  //gdImageSetThickness(im, lineWidth);

  //設定另一條線段的寬度，這裡是使用原本的 lineWidth。
  //gdImageLine(im, startX2 +25, startY2 +155, endX2 +25, endY2 +155, white);

  //繪製另一條線段，起點座標為 (startX2 + 25, startY2 + 155)，終點座標為 (endX2 + 25, endY2 + 155)，線段的顏色是白色。
  //gdImageSetThickness(im, lineWidth +30);

  //設定最後一條線段的寬度，這裡是將原本的 lineWidth 加上 30。
  //gdImageLine(im, startX2 -3, startY2 +170, endX2 , endY2 +170, white);

  //繪製最後一條線段，起點座標為 (startX2 - 3, startY2 + 170)，終點座標為 (endX2, endY2 + 170)，線段的顏色是白色。
  {
    // 起點和終點位置

  int startX = 330;   
  // 線的起點 X 座標

  int startY = 520;  
  // 線的起點 Y 座標

  int endX = 190;    
  // 線的終點 X 座標

  int endY = 350;    
  // 線的終點 Y 座標

  int lineWidth = 23;  // 線的寬度

  // 繪製線段
  gdImageSetThickness(im, lineWidth);
  gdImageLine(im, startX, startY, endX, endY, black);
  // 繪製線段
  gdImageSetThickness(im, lineWidth);
  gdImageLine(im, startX -35, startY +10, endX -35, endY +10, black);

  // 繪製線段
  gdImageSetThickness(im, lineWidth);
  gdImageLine(im, startX -70, startY +20, endX -70, endY +20, black);

  int startX2 = 213;   
  // 線的起點 X 座標

  int startY2 = 330;  
  // 線的起點 Y 座標

  int endX2 = 133;    
  // 線的終點 X 座標

  int endY2 = 390;    
  // 線的終點 Y 座標

  int lineWidth2 = 25;  // 線的寬度

  // 繪製線段
  gdImageSetThickness(im, lineWidth +8);
  gdImageLine(im, startX2 -11, startY2, endX2 -11, endY2, white);

  gdImageSetThickness(im, lineWidth +10);
gdImageLine(im, startX2 -30, startY2 -9 , endX2 -30, endY2 -9 , white);

  gdImageSetThickness(im, lineWidth );
gdImageLine(im, startX2 +100, startY2 +150, endX2 +100, endY2 +150, white);

  gdImageSetThickness(im, lineWidth);
gdImageLine(im, startX2 +120, startY2 +155, endX2 +120, endY2 +155, white);

  gdImageSetThickness(im, lineWidth +14);
gdImageLine(im, startX2 +145, startY2 +157, endX2 +145, endY2 +157, white);

    gdImageSetThickness(im, lineWidth -10);
gdImageLine(im, 232, 426, 206, 448, white);

  }
  {
    // 起點和終點位置

  int startX = 564;   
  // 線的起點 X 座標

  int startY = 97;  
  // 線的起點 Y 座標

  int endX = 704;    
  // 線的終點 X 座標

  int endY = 267;    
  // 線的終點 Y 座標

  int lineWidth = 23;  // 線的寬度

  // 繪製線段
  gdImageSetThickness(im, lineWidth);
  gdImageLine(im, startX +70, startY -20, endX +70, endY -20, black);

    // 繪製線段
  gdImageSetThickness(im, lineWidth);
  gdImageLine(im, startX, startY, endX, endY, black);

    gdImageSetThickness(im, lineWidth -10);
gdImageLine(im, 624, 212, 734, 118, white);

    // 繪製線段
  gdImageSetThickness(im, lineWidth);
  gdImageLine(im, startX +35, startY -10, endX +35, endY -10, black);

  int startX2 = 553;   
  // 線的起點 X 座標

  int startY2 = 277;  
  // 線的起點 Y 座標

  int endX2 = 633;    
  // 線的終點 X 座標

  int endY2 = 217;    
  // 線的終點 Y 座標

  int lineWidth2 = 25;  // 線的寬度

  // 繪製線段
  gdImageSetThickness(im, lineWidth +8);
  gdImageLine(im, startX2 +134, startY2, endX2 +134, endY2, white);

  gdImageSetThickness(im, lineWidth +10);
gdImageLine(im, startX2 +157, startY2 +9 , endX2 +157, endY2 +9 , white);

  gdImageSetThickness(im, lineWidth);
gdImageLine(im, startX2 +25, startY2 -155, endX2 +25, endY2 -155, white);

    gdImageSetThickness(im, lineWidth +30);
gdImageLine(im, startX2 -5, startY2 -155, endX2 -5, endY2 -155, white);

  }

    // Save image
FILE *outputFile = fopen("./../images/korea_flag.png", "wb");
if (outputFile == NULL) {
    fprintf(stderr, "Error opening the output file.\n");
    return 1;
}
  gdImagePngEx(im, outputFile, 9);
      fclose(outputFile);
      gdImageDestroy(im);
      return 0;
  }