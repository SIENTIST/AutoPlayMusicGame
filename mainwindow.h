#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

#include <windows.h>
#pragma comment(lib, "user32.lib")

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_StartBtn_clicked();

    void on_keyboardBtn_clicked();

    void keyboardLongPress();

private:
    bool judge_A_startPress(const QImage* pInputImg);
    bool judge_A_finishPress(const QImage* pInputImg);

    bool judge_W_startPress(const QImage* pInputImg);
    bool judge_W_finishPress(const QImage* pInputImg);

    bool judge_D_startPress(const QImage* pInputImg);

    bool judge_J_startPress(const QImage* pInputImg);
    bool judge_I_startPress(const QImage* pInputImg);
    bool judge_L_startPress(const QImage* pInputImg);
    void getFullScreenImg(QImage *pOutImg);

    void A_longPressControl(const QImage* pImg);
    void W_longPressControl(const QImage* pImg);

private:
    Ui::MainWindow *ui;
    QLabel* pPictureLabel;

    QImage* m_pScreenImg;



};
#endif // MAINWINDOW_H
