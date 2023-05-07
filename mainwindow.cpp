#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>

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


void MainWindow::on_normsearch_clicked()
{
for(int i = 0; i<ui->inputsize->text().toInt(); i++) {
  //  if(ui->find->text().ToInt() == ui->list->item(i))
}
}


void MainWindow::on_binsearch_clicked()
{

}


void MainWindow::on_gendata_clicked()
{
 ui->list->clear();
 srand(time(0));
 for(int i = 0; i<ui->inputsize->text().toInt(); i++) {
    ui->list->addItem(QString::number(rand()));
 }
ui->datasize->setText("The Dataset size is: " + ui->inputsize->text());
}
void MainWindow::on_findit_clicked()
{

}


void MainWindow::on_sortmerge_clicked()
{

}


void MainWindow::on_sortstl_clicked()
{

}

