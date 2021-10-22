#ifndef CAUTOPLAY_H
#define CAUTOPLAY_H

#include <QScreen>
#include <QApplication>
#include <QDesktopWidget>
#include <QTabWidget>
#include <QPushButton>
#include <QPixmap>
#include <QImage>

#include <windows.h>
#pragma comment(lib, "user32.lib")

//class CAutoPlay
//{
//public:
//    CAutoPlay();
//};

extern bool judge_J_startPress(const QImage* pInputImg);
extern bool judge_J_finishPress(const QImage* pInputImg);
extern void J_longPressControl(const QImage* pImg);

extern bool judge_I_startPress(const QImage* pInputImg);
extern bool judge_I_finishPress(const QImage* pInputImg);
extern void I_longPressControl(const QImage* pImg);

extern bool judge_L_startPress(const QImage* pInputImg);
extern bool judge_L_finishPress(const QImage* pInputImg);
extern void L_longPressControl(const QImage* pImg);
#endif // CAUTOPLAY_H
