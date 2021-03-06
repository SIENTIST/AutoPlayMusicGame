#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QScreen>
#include <QApplication>
#include <QDesktopWidget>
#include <QTabWidget>
#include <QPushButton>
#include <QPixmap>
#include <QImage>
#include <QMessageBox>
#include <QTimer>

#include <QDebug>

#include "auto_play.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_pScreenImg = new QImage;
}

MainWindow::~MainWindow()
{
    delete m_pScreenImg;
    delete ui;
}

bool MainWindow::judge_A_startPress(const QImage* pInputImg)
{
    float blueAverage = 0;
    float redAverage = 0;
    int count = 0;

    int xStart = 285, yStart = 568 - 20;
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

    //qDebug() << "blue: " << blueAverage;

    int blueThresold = 200;
    if(blueAverage > blueThresold && redAverage > 50 && redAverage < 200)
    {
        if(QColor(pInputImg->pixel(287, 568)).blue() > blueThresold
        && QColor(pInputImg->pixel(289, 568)).blue() > blueThresold
        && QColor(pInputImg->pixel(291, 568)).blue() > blueThresold
        && QColor(pInputImg->pixel(293, 568)).blue() > blueThresold
        && QColor(pInputImg->pixel(295, 568)).blue() > blueThresold)
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

bool MainWindow::judge_A_finishPress(const QImage* pInputImg)
{
    int thresold = 220;

    if(QColor(pInputImg->pixel(287, 568)).blue() < thresold
    && QColor(pInputImg->pixel(289, 568)).blue() < thresold
    && QColor(pInputImg->pixel(291, 568)).blue() < thresold
    && QColor(pInputImg->pixel(293, 568)).blue() < thresold
    && QColor(pInputImg->pixel(295, 568)).blue() < thresold)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void MainWindow::A_longPressControl(const QImage* pImg)
{
    static int A_pressFlag = 0;

    if(A_pressFlag == 0 && judge_A_startPress(pImg))
    {
        A_pressFlag = 1;
    }

    if(A_pressFlag == 1 && judge_A_finishPress(pImg))
    {
        A_pressFlag = 0;
    }

    if(A_pressFlag == 1)
    {
        //按下键盘按键
        keybd_event('A', 0, 0, 0);

//        static int s_count = 0;
//        qDebug() << "press W " <<s_count;
//        s_count ++;
    }
    else
    {
            //弹起键盘按键
            keybd_event('A', 0, 2, 0);
       //     qDebug() << "W finish  press";
    }
}

bool MainWindow::judge_W_startPress(const QImage* pInputImg)
{
    float blueAverage = 0;
    float redAverage = 0;
    int count = 0;

    int xStart = 455, yStart = 400 - 20;
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

    //qDebug() << "blue: " << blueAverage;

    int blueThresold = 200;
    if(blueAverage > blueThresold && redAverage > 50 && redAverage < 200)
    {
        int xT = 457; int yT = 400;

        if(QColor(pInputImg->pixel(xT,     yT)).blue() > blueThresold
        && QColor(pInputImg->pixel(xT + 2, yT)).blue() > blueThresold
        && QColor(pInputImg->pixel(xT + 4, yT)).blue() > blueThresold
        && QColor(pInputImg->pixel(xT + 6, yT)).blue() > blueThresold
        && QColor(pInputImg->pixel(xT + 8, yT)).blue() > blueThresold)
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
bool MainWindow::judge_W_finishPress(const QImage* pInputImg)
{
    int xT = 457; int yT = 400;

    int thresold = 220;
    if(QColor(pInputImg->pixel(xT,     yT)).blue() < thresold
    && QColor(pInputImg->pixel(xT + 2, yT)).blue() < thresold
    && QColor(pInputImg->pixel(xT + 4, yT)).blue() < thresold
    && QColor(pInputImg->pixel(xT + 6, yT)).blue() < thresold
    && QColor(pInputImg->pixel(xT + 8, yT)).blue() < thresold)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void MainWindow::W_longPressControl(const QImage* pImg)
{
    static int W_pressFlag = 0;

    if(W_pressFlag == 0 && judge_W_startPress(pImg))
    {
        W_pressFlag = 1;
    }

    if(W_pressFlag == 1 && judge_W_finishPress(pImg))
    {
        W_pressFlag = 0;
    }

    if(W_pressFlag == 1)
    {
        //按下键盘按键
        keybd_event('W', 0, 0, 0);  //W

//        static int s_count = 0;
//        qDebug() << "press W " <<s_count;
//        s_count ++;
    }
    else
    {
            //弹起键盘按键
            keybd_event('W', 0, 2, 0);  //W
       //     qDebug() << "W finish  press";
    }
}

bool MainWindow::judge_D_startPress(const QImage* pInputImg)
{
    float blueAverage = 0;
    float redAverage = 0;
    int count = 0;

    int xStart = 622, yStart = 568 - 20;
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

    //qDebug() << "blue: " << blueAverage;

    int blueThresold = 200;
    if(blueAverage > blueThresold && redAverage > 50 && redAverage < 200)
    {
        int xT = 622; int yT = 568;

        if(QColor(pInputImg->pixel(xT,     yT)).blue() > blueThresold
        && QColor(pInputImg->pixel(xT + 2, yT)).blue() > blueThresold
        && QColor(pInputImg->pixel(xT + 4, yT)).blue() > blueThresold
        && QColor(pInputImg->pixel(xT + 6, yT)).blue() > blueThresold
        && QColor(pInputImg->pixel(xT + 8, yT)).blue() > blueThresold)
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

bool MainWindow::judge_D_finishPress(const QImage* pInputImg)
{
    int thresold = 220;
    int xT = 622; int yT = 568;

    if(QColor(pInputImg->pixel(xT,     yT)).blue() < thresold
    && QColor(pInputImg->pixel(xT + 2, yT)).blue() < thresold
    && QColor(pInputImg->pixel(xT + 4, yT)).blue() < thresold
    && QColor(pInputImg->pixel(xT + 6, yT)).blue() < thresold
    && QColor(pInputImg->pixel(xT + 8, yT)).blue() < thresold)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void MainWindow::D_longPressControl(const QImage* pImg)
{
    static int pressFlag = 0;

    if(pressFlag == 0 && judge_D_startPress(pImg))
    {
        pressFlag = 1;
    }

    if(pressFlag == 1 && judge_D_finishPress(pImg))
    {
        pressFlag = 0;
    }

    if(pressFlag == 1)
    {
        //按下键盘按键
        keybd_event('D', 0, 0, 0);

//        static int s_count = 0;
//        qDebug() << "press W " <<s_count;
//        s_count ++;
    }
    else
    {
            //弹起键盘按键
        keybd_event('D', 0, 2, 0);
       //     qDebug() << "W finish  press";
    }
}

void MainWindow::keyboardLongPress()
{
    QImage* pScreenImg = new QImage;

    getFullScreenImg(pScreenImg);

    A_longPressControl(pScreenImg);
    W_longPressControl(pScreenImg);
    D_longPressControl(pScreenImg);

    J_longPressControl(pScreenImg);
    I_longPressControl(pScreenImg);
    L_longPressControl(pScreenImg);



    delete  pScreenImg;
}

void MainWindow::getFullScreenImg(QImage* pOutImg)
{
    //begin:get system desktop and save it as a QPixmap.
    QScreen* screen = QGuiApplication::primaryScreen();

    //return the desktop window(root window).
    QDesktopWidget* desktop = QApplication::desktop();
    //get the geometry size of desktop.
    QRect rect = desktop->screenGeometry();

    //QPixmap pixmap = QPixmap::grabWindow(desktop->winId(), 0, 0, rect.width(), rect.height());
    QPixmap pixmap = screen->grabWindow(desktop->winId(), 0, 0, rect.width(), rect.height());

    //pixmap.save("blog.png", "png");

    *pOutImg = pixmap.toImage();  //QPixmap转QImage，便于处理

}

void MainWindow::on_StartBtn_clicked()
{
//    if(!(m_pScreenImg->load("D:\\Project\\AutoPlayMusicGame\\program\\AutoPlayMusicGame\\picture_data/short_press_1.png"))) //加载图像
//    {
//        QMessageBox::information(this,
//                                 tr("打开图像失败"),
//                                 tr("打开图像失败!"));
//        return;
//    }

    //按下键盘按键
//    keybd_event('Q', 0, 0, 0);  //A

//    //弹起键盘按键
//    keybd_event('Q', 0, 2, 0);  //A

    QTimer *timer_Akey = new QTimer(this);
    connect(timer_Akey, SIGNAL(timeout()), this, SLOT(keyboardLongPress()));
    timer_Akey->start(40);  //单位：毫秒  设定每隔多少毫秒执行一次
}



//https://www.fearlazy.com/index.php/post/167.html
void MainWindow::on_keyboardBtn_clicked()
{
//    //按下键盘按键
//    keybd_event(VK_MENU, 0, 0, 0);  //alt
//    keybd_event('A', 0, 0, 0);  //A

//    //弹起键盘按键
//    keybd_event(VK_MENU, 0, 2, 0);  //alt
//    keybd_event('A', 0, 2, 0);  //A

    //按下键盘按键
    keybd_event('Q', 0, 0, 0);  //A

    //弹起键盘按键
    keybd_event('Q', 0, 2, 0);  //A
//    keybd_event('W', 0, 0, 0);  //A
}




