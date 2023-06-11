#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "describtion.h"

using namespace Tree;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    tree(new BinaryTree)
{
    dialog = new Dialog(this, tree);
    ui->setupUi(this);

    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setFixedSize(QSize(width(), height()));


}

void MainWindow::show_Dialog()
{
    dialog->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_insert_clicked()
{
    if((ui->line_insert->text().isEmpty()))
        return;

    int insert = (ui->line_insert->text()).toInt();

    if((tree->Add(insert)))
    {
        ui->line_logs->clear();
        ui->line_logs->setText("Inserting was done successfully! Value: " + QString::number(insert));
        dialog->repaint(); // здесь пока что просто функция отрисовки узла чтобы проверить работоспособность. а оно не рисует(
    }
    else
    {
        ui->line_logs->clear();
        ui->line_logs->setText("Something was wrong =| ");
    }
}

void MainWindow::on_button_remove_clicked()
{
    if(ui->line_remove->text().isEmpty())
        return;
    int remove = (ui->line_remove->text()).toInt();

    if((tree->Remove(remove)))
    {
        ui->line_logs->clear();
        ui->line_logs->setText("Removing was done successfully! Value: " + QString::number(remove));
        dialog->repaint();
    }
    else
    {
        ui->line_logs->clear();
        ui->line_logs->setText("Error: this value was not found! Value: " + QString::number(remove));
    }
}

void MainWindow::on_button_search_clicked()
{
    if(ui->line_search->text().isEmpty())
        return;
    int search = (ui->line_search->text()).toInt();
    if(tree->Search(search))
    {
        ui->line_logs->clear();
        ui->line_logs->setText("This value was searched! Value: " + QString::number(search));
    }
    else
    {
        ui->line_logs->clear();
        ui->line_logs->setText("The value was not found! Value: " + QString::number(search));
    }
}

void MainWindow::on_button_add_subtree_clicked()
{
    if(ui->line_subtree->text().isEmpty())
        return;



    ui->line_logs->clear();
    ui->line_logs->setText("Was done successfully!");
}
