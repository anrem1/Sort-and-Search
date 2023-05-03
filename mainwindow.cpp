#include "mainwindow.h"
#include "ui_mainwindow.h"

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

}


void MainWindow::on_binsearch_clicked()
{

}


void MainWindow::on_gendata_clicked()
{

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

