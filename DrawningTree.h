#ifndef DRAWNINGTREE_H
#define DRAWNINGTREE_H

#include <QDialog>
#include "describtion.h"
#include <QPainter>

using namespace Tree;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0, const BinaryTree *bt = nullptr);
    ~Dialog();

protected:
    void paintEvent(QPaintEvent *e);

private:
    const BinaryTree *tree;
    Ui::Dialog *ui;

    void drawning_node(QPainter *painter, const Node *node, int x, int y, const int rx, const int ry, bool LeftOfRight, int SizeOfLine, int XDistance, int YDistance); // if TRUE then RIGHT else if FALSE then LEFT

};

#endif // DRAWNINGTREE_H
