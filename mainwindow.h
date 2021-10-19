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

private:
    Ui::MainWindow *ui;
    QLabel* pPictureLabel;

};
#endif // MAINWINDOW_H
