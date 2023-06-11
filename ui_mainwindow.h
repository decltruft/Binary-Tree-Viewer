/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *line_logs;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_insert;
    QLineEdit *line_insert;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *button_remove;
    QLineEdit *line_remove;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *button_search;
    QLineEdit *line_search;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *button_add_subtree;
    QLineEdit *line_subtree;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(372, 518);
        MainWindow->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"	background: url(:/i) no-repeat right bottom;\n"
" 	background-size: cover;\n"
"	background-attachment: fixed;\n"
"}"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        line_logs = new QLineEdit(centralWidget);
        line_logs->setObjectName(QStringLiteral("line_logs"));
        line_logs->setGeometry(QRect(40, 370, 291, 81));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 20, 291, 341));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        button_insert = new QPushButton(layoutWidget);
        button_insert->setObjectName(QStringLiteral("button_insert"));

        horizontalLayout->addWidget(button_insert);

        line_insert = new QLineEdit(layoutWidget);
        line_insert->setObjectName(QStringLiteral("line_insert"));

        horizontalLayout->addWidget(line_insert);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        button_remove = new QPushButton(layoutWidget);
        button_remove->setObjectName(QStringLiteral("button_remove"));

        horizontalLayout_2->addWidget(button_remove);

        line_remove = new QLineEdit(layoutWidget);
        line_remove->setObjectName(QStringLiteral("line_remove"));

        horizontalLayout_2->addWidget(line_remove);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        button_search = new QPushButton(layoutWidget);
        button_search->setObjectName(QStringLiteral("button_search"));

        horizontalLayout_3->addWidget(button_search);

        line_search = new QLineEdit(layoutWidget);
        line_search->setObjectName(QStringLiteral("line_search"));

        horizontalLayout_3->addWidget(line_search);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        button_add_subtree = new QPushButton(layoutWidget);
        button_add_subtree->setObjectName(QStringLiteral("button_add_subtree"));

        horizontalLayout_4->addWidget(button_add_subtree);

        line_subtree = new QLineEdit(layoutWidget);
        line_subtree->setObjectName(QStringLiteral("line_subtree"));

        horizontalLayout_4->addWidget(line_subtree);


        verticalLayout->addLayout(horizontalLayout_4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 372, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(button_insert, SIGNAL(clicked()), line_insert, SLOT(copy()));
        QObject::connect(button_remove, SIGNAL(clicked()), line_remove, SLOT(copy()));
        QObject::connect(button_search, SIGNAL(clicked()), line_search, SLOT(copy()));
        QObject::connect(button_add_subtree, SIGNAL(clicked()), line_subtree, SLOT(copy()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        button_insert->setText(QApplication::translate("MainWindow", "Insert", Q_NULLPTR));
        line_insert->setText(QString());
        button_remove->setText(QApplication::translate("MainWindow", "Remove", Q_NULLPTR));
        line_remove->setText(QString());
        button_search->setText(QApplication::translate("MainWindow", "Search", Q_NULLPTR));
        line_search->setText(QString());
        button_add_subtree->setText(QApplication::translate("MainWindow", "Add subtree", Q_NULLPTR));
        line_subtree->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
