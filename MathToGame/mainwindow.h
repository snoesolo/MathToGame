#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QTime>
#include <QTimer>
#include <QString>
#include <QMessageBox>
#include <QLabel>
#include <QKeyEvent>
#include <QSlider>

#if QT_VERSION >= 0x050000
#include <QtWidgets/QMainWindow>
#else
//#include <QtGui/QMainWindow>
#include <QMainWindow>
#endif

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  void inters();
  int rapidc(int spans);//产生随机数
  QString signs();      //随机加减符号
  void fuzhi();         //给mainwindow全局变量赋值
  void gameover();      //游戏失败
  void tmsrst();        //计时函数
  void keypess(QKeyEvent *e);    //按键处理函数
  void score();

private slots:
  void on_trbtn_clicked();
  void on_flbtn_clicked();
  void times();
private:
  Ui::MainWindow *ui;
  QTimer *tm;       //新建计时器
  QSlider *rpb;     //新建一个滑动条用来显示剩余时间
};

#endif // MAINWINDOW_H
