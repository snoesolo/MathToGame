#include "mainwindow.h"
#include "ui_mainwindow.h"

int ias = 2000;
void MainWindow::times ()
{
  if (ias >= 0)
    {
      ias = ias - 1;
      rpb->setValue (ias / 10);
    }
  else
    {
      ias = 2000;
      gameover ();
    }
}

void MainWindow::tmsrst ()
{
  if (tm->isActive ())
    {
    ias = 2000;
    }
  else
    tm->start ();
}
