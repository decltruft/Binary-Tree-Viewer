#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "describtion.h"
#include "DrawningTree.h"

using namespace Tree;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void show_Dialog();

private slots:
    void on_button_insert_clicked();

    void on_button_remove_clicked();

    void on_button_search_clicked();

    void on_button_add_subtree_clicked();

private:
    Ui::MainWindow *ui;
    BinaryTree     *tree;
    Dialog         *dialog;

};

#endif // MAINWINDOW_H
