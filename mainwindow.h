#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
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
    bool on_normsearch_clicked();

    bool on_binsearch_clicked();

    void on_gendata_clicked();

    void on_findit_clicked();

    void on_sortmerge_clicked();

    void on_sortstl_clicked();

    void stlsort();

    void genran();

    void mergeSort(std::vector<int>& arr, int left, int right);

    void merge(std::vector<int>& arr, int left, int mid, int right);

private:
    Ui::MainWindow *ui;
    std::vector<int> v;
    bool flagm = false;
    bool flagst = false;

};
#endif // MAINWINDOW_H
