#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>
#include <QMessageBox>

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
// if it is possible to take a clicked function as a parameter, this can be used to find time instead of copying the 3 lines
int MainWindow::systime(bool x) {
    std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    // function
    std::chrono::steady_clock::time_point then = std::chrono::steady_clock::now();
    int stime = std::chrono::duration_cast<std::chrono::nanoseconds>(then-now).count();
    return stime;
}


bool MainWindow::on_normsearch_clicked()
{

for(int i = 0; i<ui->inputsize->text().toInt(); i++) {
    if(ui->find->text().toInt() == ui->list->item(i)->text().toInt()) {
        return 1;
    }
}
return 0;
}


bool MainWindow::on_binsearch_clicked()
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
ui->arrsort->setText("Unsorted Array");
}


void MainWindow::on_findit_clicked()
{
    // if they click on normal search
    if(on_normsearch_clicked()) {
        std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
        on_normsearch_clicked();
        std::chrono::steady_clock::time_point then = std::chrono::steady_clock::now();
        int time = std::chrono::duration_cast<std::chrono::nanoseconds>(then-now).count();
        // if they click on sort by stl + normal search
       if(on_sortstl_clicked())
       {
        std::chrono::steady_clock::time_point t = std::chrono::steady_clock::now();
        on_sortstl_clicked();
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
        int stltime = std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t).count();
        // display popup
        QMessageBox::information(this,"Normal Search", "This item exists.\nTime in ns taken to search: " + QString::number(time) + "\nTime in ns taken to sort: " + QString::number(stltime), QMessageBox::Ok);
        }
       else if(on_sortmerge_clicked()) {    // if they click on sort by merge + normal search
           std::chrono::steady_clock::time_point t = std::chrono::steady_clock::now();
           on_sortmerge_clicked();
           std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
           int mergtime = std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t).count();
           QMessageBox::information(this,"Normal Search", "This item exists.\nTime in ns taken to search: " + QString::number(time) + "\nTime in ns taken to sort: " + QString::number(mergtime), QMessageBox::Ok);
       }
    }

    // if they click on binary search
    else if(on_binsearch_clicked()) {
   std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
    on_binsearch_clicked();
    std::chrono::steady_clock::time_point then = std::chrono::steady_clock::now();
    int bintime = std::chrono::duration_cast<std::chrono::nanoseconds>(then-now).count();
    if(on_sortstl_clicked())    // if they click on stl sort + binary search
    {
     std::chrono::steady_clock::time_point t = std::chrono::steady_clock::now();
     on_sortstl_clicked();
     std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
     int stltime = std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t).count();
     QMessageBox::information(this,"Binary Search", "This item exists.\nTime in ns taken to search: " + QString::number(bintime) + "\nTime in ns taken to sort: " + QString::number(stltime), QMessageBox::Ok);
  }
    else if(on_sortmerge_clicked()) {   // if they click on sort by merge + binary search
        std::chrono::steady_clock::time_point t = std::chrono::steady_clock::now();
        on_sortmerge_clicked();
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
        int mergtime = std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t).count();
        QMessageBox::information(this,"Binary Search", "This item exists.\nTime in ns taken to search: " + QString::number(bintime) + "\nTime in ns taken to sort: " + QString::number(mergtime), QMessageBox::Ok);
    }
    }
    //  else item does not exist
    else {
         QMessageBox::information(this,"Search", "This item does not exist.", QMessageBox::Ok);
         }

}



bool MainWindow::on_sortmerge_clicked()
{
return 1;
}

bool MainWindow::on_sortstl_clicked()
{
    stlsort();
    return 1;
}

void MainWindow::stlsort() {
                               // still needs to be converted into vector or other form
    ui->list->sortItems();
    ui->arrsort->setText("Array is Sorted");
    ui->sortuse->setText("Sort using STL Sort");
}



