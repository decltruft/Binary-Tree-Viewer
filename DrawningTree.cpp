#include "DrawningTree.h"
#include "ui_DrawningTree.h"
#include "describtion.h"

Dialog::Dialog(QWidget *parent, const BinaryTree *bt) :
    QDialog(parent),
    ui(new Ui::Dialog),
    tree(bt)
{
    ui->setupUi(this);
}

void Dialog::paintEvent(QPaintEvent *e)
{
    int const rx = 40, ry = 40;
    QPainter painter(this);

    painter.setBrush(Qt::green);
    painter.setPen(Qt::black);

    int size_of_line = 200;
    int XDistance = 15;
    int YDistance = 5;

    painter.drawEllipse(600, 0, rx, ry);
    if(tree->get_Root() == nullptr)
    {
        painter.drawText(610,25, "NULL");
        return;
    }
    else
    {
        painter.drawText(610,25, QString::number(tree->get_Root()->information));
    }

    if(tree->get_Root()->left != nullptr)
    {
        painter.drawLine(625, 40, 625 - size_of_line, 75);
        drawning_node(&painter, tree->get_Root()->left,  400, 70, rx, ry, false, size_of_line - XDistance, XDistance + 3, YDistance + 2);
    }

    if(tree->get_Root()->right != nullptr)
    {
        painter.drawLine(625, 40, 625 + size_of_line, 75);
        drawning_node(&painter, tree->get_Root()->right, 800, 70, rx, ry, true, size_of_line - XDistance, XDistance + 3, YDistance + 2);
    }
}

void Dialog::drawning_node(QPainter *painter, const Node *node, int x, int y, const int rx, const int ry, bool LeftOfRight, int SizeOfLine, int XDistance, int YDistance)
{

    if(node == nullptr)
        return;

    painter->drawEllipse(x, y, rx, ry);
    painter->drawText(x+10,y+25, QString::number(node->information));

    if(node->left != nullptr)
    {
        painter->drawLine(x + 25, y + 40, x - SizeOfLine + XDistance+10, y + 75 - YDistance);
        drawning_node(painter, node->left, x - SizeOfLine + XDistance, y + 75 - YDistance, rx, ry, false, SizeOfLine - XDistance+10, XDistance  + 3, YDistance + 2);
    }

    if(node->right != nullptr)
    {
        painter->drawLine(x + 25, y + 40, x + SizeOfLine - XDistance, y + 75 - YDistance);
        drawning_node(painter, node->right, x + SizeOfLine - XDistance, y + 75 - YDistance, rx, ry, true, SizeOfLine - XDistance+10, XDistance + 3, YDistance + 2);
    }
}

Dialog::~Dialog()
{
    delete ui;
}
