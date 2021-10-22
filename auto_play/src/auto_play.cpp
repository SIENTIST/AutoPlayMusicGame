#include "auto_play.h"

#define START_BLUE_THRESOLD 200
#define FINISH_BLUE_THRESOLD 220

#define J_X 1233
#define J_Y 568

#define I_X 1398
#define I_Y 400

#define L_X 1570
#define L_Y 568

//CAutoPlay::CAutoPlay()
//{

//}

bool judge_J_startPress(const QImage* pInputImg)
{
    float blueAverage = 0;
    float redAverage = 0;
    int count = 0;

    int xStart = J_X, yStart = J_Y - 20;

    for(int x = xStart; x < xStart + 65; x++)    // x:620 ~ 685  y: 570
    {
        for(int y = yStart; y < yStart + 20; y++)
        {
            count ++;
            QColor pointColor;
            pointColor = QColor(pInputImg->pixel(x, y));
            blueAverage += pointColor.blue(); //读取单个像素点的色值
            redAverage += pointColor.red();
        }
    }

    blueAverage /= count;
    redAverage /= count;

    if(blueAverage > START_BLUE_THRESOLD && redAverage > 50 && redAverage < 200)
    {
        int xT = J_X; int yT = J_Y;

        if(QColor(pInputImg->pixel(xT,     yT)).blue() > START_BLUE_THRESOLD
        && QColor(pInputImg->pixel(xT + 2, yT)).blue() > START_BLUE_THRESOLD
        && QColor(pInputImg->pixel(xT + 4, yT)).blue() > START_BLUE_THRESOLD
        && QColor(pInputImg->pixel(xT + 6, yT)).blue() > START_BLUE_THRESOLD
        && QColor(pInputImg->pixel(xT + 8, yT)).blue() > START_BLUE_THRESOLD)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool judge_J_finishPress(const QImage* pInputImg)
{
    int xT = J_X; int yT = J_Y;

    if(QColor(pInputImg->pixel(xT,     yT)).blue() < FINISH_BLUE_THRESOLD
    && QColor(pInputImg->pixel(xT + 2, yT)).blue() < FINISH_BLUE_THRESOLD
    && QColor(pInputImg->pixel(xT + 4, yT)).blue() < FINISH_BLUE_THRESOLD
    && QColor(pInputImg->pixel(xT + 6, yT)).blue() < FINISH_BLUE_THRESOLD
    && QColor(pInputImg->pixel(xT + 8, yT)).blue() < FINISH_BLUE_THRESOLD)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void J_longPressControl(const QImage* pImg)
{
    static int pressFlag = 0;

    if(pressFlag == 0 && judge_J_startPress(pImg))
    {
        pressFlag = 1;
    }

    if(pressFlag == 1 && judge_J_finishPress(pImg))
    {
        pressFlag = 0;
    }

    if(pressFlag == 1)
    {
        keybd_event('J', 0, 0, 0); //按下键盘按键
    }
    else
    {
        keybd_event('J', 0, 2, 0); //弹起键盘按键
    }
}

//---------------------------I key------------------------------------------------------
bool judge_I_startPress(const QImage* pInputImg)
{
    float blueAverage = 0;
    float redAverage = 0;
    int count = 0;

    int xStart = I_X, yStart = I_Y - 20;

    for(int x = xStart; x < xStart + 65; x++)    // x:620 ~ 685  y: 570
    {
        for(int y = yStart; y < yStart + 20; y++)
        {
            count ++;
            QColor pointColor;
            pointColor = QColor(pInputImg->pixel(x, y));
            blueAverage += pointColor.blue(); //读取单个像素点的色值
            redAverage += pointColor.red();
        }
    }

    blueAverage /= count;
    redAverage /= count;

    if(blueAverage > START_BLUE_THRESOLD && redAverage > 50 && redAverage < 200)
    {
        int xT = I_X; int yT = I_Y;

        if(QColor(pInputImg->pixel(xT,     yT)).blue() > START_BLUE_THRESOLD
        && QColor(pInputImg->pixel(xT + 2, yT)).blue() > START_BLUE_THRESOLD
        && QColor(pInputImg->pixel(xT + 4, yT)).blue() > START_BLUE_THRESOLD
        && QColor(pInputImg->pixel(xT + 6, yT)).blue() > START_BLUE_THRESOLD
        && QColor(pInputImg->pixel(xT + 8, yT)).blue() > START_BLUE_THRESOLD)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool judge_I_finishPress(const QImage* pInputImg)
{
    int xT = I_X; int yT = I_Y;

    if(QColor(pInputImg->pixel(xT,     yT)).blue() < FINISH_BLUE_THRESOLD
    && QColor(pInputImg->pixel(xT + 2, yT)).blue() < FINISH_BLUE_THRESOLD
    && QColor(pInputImg->pixel(xT + 4, yT)).blue() < FINISH_BLUE_THRESOLD
    && QColor(pInputImg->pixel(xT + 6, yT)).blue() < FINISH_BLUE_THRESOLD
    && QColor(pInputImg->pixel(xT + 8, yT)).blue() < FINISH_BLUE_THRESOLD)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void I_longPressControl(const QImage* pImg)
{
    static int pressFlag = 0;

    if(pressFlag == 0 && judge_I_startPress(pImg))
    {
        pressFlag = 1;
    }

    if(pressFlag == 1 && judge_I_finishPress(pImg))
    {
        pressFlag = 0;
    }

    if(pressFlag == 1)
    {
        keybd_event('I', 0, 0, 0); //按下键盘按键
    }
    else
    {
        keybd_event('I', 0, 2, 0); //弹起键盘按键
    }
}

//---------------------------L key------------------------------------------------------
bool judge_L_startPress(const QImage* pInputImg)
{
    float blueAverage = 0;
    float redAverage = 0;
    int count = 0;

    int xStart = L_X, yStart = L_Y - 20;

    for(int x = xStart; x < xStart + 65; x++)    // x:620 ~ 685  y: 570
    {
        for(int y = yStart; y < yStart + 20; y++)
        {
            count ++;
            QColor pointColor;
            pointColor = QColor(pInputImg->pixel(x, y));
            blueAverage += pointColor.blue(); //读取单个像素点的色值
            redAverage += pointColor.red();
        }
    }

    blueAverage /= count;
    redAverage /= count;

    if(blueAverage > START_BLUE_THRESOLD && redAverage > 50 && redAverage < 200)
    {
        int xT = L_X; int yT = L_Y;

        if(QColor(pInputImg->pixel(xT,     yT)).blue() > START_BLUE_THRESOLD
        && QColor(pInputImg->pixel(xT + 2, yT)).blue() > START_BLUE_THRESOLD
        && QColor(pInputImg->pixel(xT + 4, yT)).blue() > START_BLUE_THRESOLD
        && QColor(pInputImg->pixel(xT + 6, yT)).blue() > START_BLUE_THRESOLD
        && QColor(pInputImg->pixel(xT + 8, yT)).blue() > START_BLUE_THRESOLD)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool judge_L_finishPress(const QImage* pInputImg)
{
    int xT = L_X; int yT = L_Y;

    if(QColor(pInputImg->pixel(xT,     yT)).blue() < FINISH_BLUE_THRESOLD
    && QColor(pInputImg->pixel(xT + 2, yT)).blue() < FINISH_BLUE_THRESOLD
    && QColor(pInputImg->pixel(xT + 4, yT)).blue() < FINISH_BLUE_THRESOLD
    && QColor(pInputImg->pixel(xT + 6, yT)).blue() < FINISH_BLUE_THRESOLD
    && QColor(pInputImg->pixel(xT + 8, yT)).blue() < FINISH_BLUE_THRESOLD)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void L_longPressControl(const QImage* pImg)
{
    static int pressFlag = 0;

    if(pressFlag == 0 && judge_L_startPress(pImg))
    {
        pressFlag = 1;
    }

    if(pressFlag == 1 && judge_L_finishPress(pImg))
    {
        pressFlag = 0;
    }

    if(pressFlag == 1)
    {
        keybd_event('L', 0, 0, 0); //按下键盘按键
    }
    else
    {
        keybd_event('L', 0, 2, 0); //弹起键盘按键
    }
}
