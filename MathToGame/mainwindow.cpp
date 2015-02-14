#include "mainwindow.h"
#include "ui_mainwindow.h"

/*定义一下全局变量，避免下面代码过长*/
QString s;
int f,b,u;

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  //一些部件的初始化和设置
  inters ();

  //tm初始化
  tm = new QTimer(this);
  tm->setInterval (1);        //设置刷新为1毫秒
  //tm->start ();
  connect (tm,SIGNAL(timeout()),this,SLOT(times()));

  rpb = new QSlider(Qt::Horizontal,this);    //水平的滑动条
  rpb->setGeometry (5,10,400,22);       //设置滑动条的大小以及位置
  //设置滑动条的样式
  rpb->setStyleSheet ("QSlider::groove:horizontal {border: 1px solid #4acf91;height: 8px; background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #4acf91, stop:1 #4acf91);margin: 2px 0;}QSlider::handle:horizontal {background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #4acf91, stop:1 #5cffb3);border: 1px solid #4acf91;width: 18px;margin: -2px 0;border-radius: 3px;}QSlider::groove:vertical {background: red;position: absolute;left: 4px; right:4px;}");
  rpb->setMaximum (200);
  rpb->setValue (200);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_trbtn_clicked()
{
  fuzhi();
  if ((s == "+" && f+b==u) || (s == "-" && f-b==u))
    {
      score ();
      inters ();
    }
  else
    {
      gameover ();
    }
}
void MainWindow::on_flbtn_clicked()
{
  fuzhi ();
  if ((s == "+" && f+b!=u) || (s == "-" && f-b!=u))
    {
      score ();
      inters();
    }
  else
    {
      gameover ();
    }
}

void MainWindow::fuzhi ()
{
  f = ui->front->text ().toInt ();
  b = ui->behind->text ().toInt ();
  u = ui->fruit->text ().toInt ();
  s = ui->sign->text();
  tmsrst ();
}

//按键处理
void MainWindow::keypess (QKeyEvent *e)
{
  if (e->key () == Qt::Key_A)
    on_trbtn_clicked ();
  else if (e->key () == Qt::Key_D)
    on_flbtn_clicked ();
}
