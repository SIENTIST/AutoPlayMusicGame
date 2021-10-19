#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QScreen>
#include <QApplication>
#include <QDesktopWidget>
#include <QTabWidget>
#include <QPushButton>
#include <QPixmap>
#include <QImage>

#include <QDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_StartBtn_clicked()
{
/*
    //begin:get system desktop and save it as a QPixmap.
        QScreen* screen = QGuiApplication::primaryScreen();
        //return the desktop window(root window).
        QDesktopWidget* desktop = QApplication::desktop();
        //get the geometry size of desktop.
        QRect rect = desktop->screenGeometry();

        //grab the contents of the given window resticted by Wid & QRect.
        QPixmap mFullScreen = screen->grabWindow(desktop->winId(), 0, 0, rect.width(), rect.height());
        pLabelFullScreen->setPixmap(mFullScreen);
        pLabelFullScreen->showFullScreen();
        //end:get system desktop and save it as a QPixmap.
*/

        //QPixmap pixmap = QPixmap::grabWindow(QApplication::desktop()->winId(),pos().x(),pos().y(),frameGeometry().width(),frameGeometry().height());


    //begin:get system desktop and save it as a QPixmap.
    QScreen* screen = QGuiApplication::primaryScreen();

    //return the desktop window(root window).
    QDesktopWidget* desktop = QApplication::desktop();
    //get the geometry size of desktop.
    QRect rect = desktop->screenGeometry();

    QPixmap pixmap = QPixmap::grabWindow(desktop->winId(), 0, 0, rect.width(), rect.height());
    //pixmap.save("blog.png", "png");

    pPictureLabel = new QLabel();

    pPictureLabel->setPixmap(pixmap);

    QImage image = pixmap.toImage();  //QPixmap转QImage，便于处理

    pPictureLabel->show();

    qDebug() << image.width() <<"  " << image.height() <<"  ";

    QColor PointColor;
    //PointColor = QColor(image.pixel(0, 0));
    PointColor = QColor(image.pixel(image.width() - 1, image.height() - 1)); //读取单个像素点的色值
    qDebug() << PointColor.red() <<"  " << PointColor.blue() <<"  " << PointColor.yellow() << "   black:" << PointColor.black();



}

//https://www.fearlazy.com/index.php/post/167.html
void MainWindow::on_keyboardBtn_clicked()
{
    keybd_event(VK_MENU, 0, 0, 0);  //alt
    keybd_event('A', 0, 0, 0);  //A

    keybd_event(VK_MENU, 0, 2, 0);  //alt
    keybd_event('A', 0, 2, 0);  //A
}
