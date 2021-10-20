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

    qDebug() << "blue: " << blueAverage;

    if(blueAverage > 250 && redAverage > 50 && redAverage < 200)
    {
        if(QColor(pInputImg->pixel(287, 568)).blue() > 250
        && QColor(pInputImg->pixel(289, 568)).blue() > 250
        && QColor(pInputImg->pixel(291, 568)).blue() > 250
        && QColor(pInputImg->pixel(293, 568)).blue() > 250
        && QColor(pInputImg->pixel(295, 568)).blue() > 250)
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
    qDebug() << "update";

    if(QColor(pInputImg->pixel(287, 568)).blue() < 250
    && QColor(pInputImg->pixel(289, 568)).blue() < 250
    && QColor(pInputImg->pixel(291, 568)).blue() < 250
    && QColor(pInputImg->pixel(293, 568)).blue() < 250
    && QColor(pInputImg->pixel(295, 568)).blue() < 250)
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
        keybd_event('A', 0, 0, 0);  //A
        A_pressFlag = 1;
    }

    if(A_pressFlag == 1 && judge_A_finishPress(pImg))
    {
        keybd_event('A', 0, 2, 0);  //A
        A_pressFlag = 0;
    }

    if(A_pressFlag == 1)
    {
        static int s_count = 0;
        qDebug() << "press A " <<s_count;
        s_count ++;
    }
}

void MainWindow::keyboardLongPress()
{

    QImage* pScreenImg = new QImage;

    getFullScreenImg(pScreenImg);

    A_longPressControl(pScreenImg);

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

    QTimer *timer_Akey = new QTimer(this);
    connect(timer_Akey, SIGNAL(timeout()), this, SLOT(keyboardLongPress()));
    timer_Akey->start(10);  //单位：毫秒  设定每隔多少毫秒执行一次


/*
    float redAverage = 0;
    float yellowAverage = 0;
    float blueAverage = 0;
    int count = 0;

    int xD = 622, yD = 380;
    for(int x = xD; x < xD + 65; x++)    // x:620 ~ 685  y: 570
    {
        for(int y = yD; y < yD + 20; y++)
        {
            count ++;

            PointColor = QColor(pLongPressImg->pixel(x, y)); //读取单个像素点的色值
            redAverage += PointColor.red();
            yellowAverage += PointColor.yellow();
            blueAverage += PointColor.blue();

            pLongPressImg->setPixel(x, y, qRgb(0, 0, 0)); //red  yellow  blue
        }
    }
*/
//    qDebug() << "redAverage:    " << redAverage / count;
//    qDebug() << "yellowAverage: " << yellowAverage / count;
//    qDebug() << "blueAverage:   " << blueAverage / count;

}

//https://www.fearlazy.com/index.php/post/167.html
void MainWindow::on_keyboardBtn_clicked()
{
    //按下键盘按键
    keybd_event(VK_MENU, 0, 0, 0);  //alt
    keybd_event('A', 0, 0, 0);  //A

    //弹起键盘按键
    keybd_event(VK_MENU, 0, 2, 0);  //alt
    keybd_event('A', 0, 2, 0);  //A
}


