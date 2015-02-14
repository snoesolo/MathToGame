#include "mainwindow.h"
#include "ui_mainwindow.h"

int digit = 10;    //设定随机数的取值范围
int scores = 0;    //设置计分
//初始化和设置部件
void MainWindow::inters ()
{
  if (ui->lids->value () >= 30)
    digit = 100;
  else if (ui->lids->value () >= 250)
    digit = 500;
  else if (ui->lids->value () >= 800)
    digit = 1000;
  //设置一些参数
  ui->behind->setText (QString::number (rapidc (digit)));
  ui->front->setText (QString::number (ui->behind->text ().toInt () + rapidc (digit)));//避免结果为负
  if (ui->sign->text () == "+")
    ui->fruit->setText (QString::number (ui->front->text ().toInt ()+ui->behind->text ().toInt ()-rapidc (2)));
  else
    ui->fruit->setText (QString::number (ui->front->text ().toInt ()-ui->behind->text ().toInt ()+rapidc (2)));         //避免出现负数的结果
}

//生成随机数
int MainWindow::rapidc (int spans)
{
  QTime T = QTime::currentTime ();
  int i = (T.msec ()+T.second ()) * 13 % spans;   //随机数生成
  return i;
}

//随机生成+-符号
QString MainWindow::signs ()
{
  int i = rapidc (2);      //随机生成1或0
  if (i != 0)
    return "-";
  else
    return "+";
}

//计分
void MainWindow::score ()
{
  scores = scores + 1;
  ui->lids->display (scores);
}

//游戏失败
void MainWindow::gameover ()
{
  QString sss = "你的分值:";
  sss.append (QString::number (ui->lids->value ()));
  tm->stop ();
  QMessageBox abs;
  abs.setText (tr("<font color=red>游戏结束！</font><p>")+'\n'+sss);     //采用html语法
  abs.exec ();
  inters ();
  digit = 10;
  scores = 0;
  ui->lids->display (0);
}
