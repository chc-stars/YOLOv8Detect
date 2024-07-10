/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_4;
    QWidget *widget_para;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_selectedFile;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_detType;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *comboBox_model;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_start;
    QPushButton *pushButton_end;
    QWidget *widget_show;
    QGridLayout *gridLayout_3;
    QLabel *label_pic;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/image/softIcon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_4 = new QGridLayout(centralwidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        widget_para = new QWidget(centralwidget);
        widget_para->setObjectName(QString::fromUtf8("widget_para"));
        gridLayout = new QGridLayout(widget_para);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(widget_para);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(false);

        horizontalLayout_2->addWidget(lineEdit);

        pushButton_selectedFile = new QPushButton(groupBox);
        pushButton_selectedFile->setObjectName(QString::fromUtf8("pushButton_selectedFile"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_selectedFile->sizePolicy().hasHeightForWidth());
        pushButton_selectedFile->setSizePolicy(sizePolicy);
        pushButton_selectedFile->setMinimumSize(QSize(5, 0));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resource/image/open.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_selectedFile->setIcon(icon1);

        horizontalLayout_2->addWidget(pushButton_selectedFile);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        comboBox_detType = new QComboBox(groupBox);
        comboBox_detType->addItem(QString());
        comboBox_detType->addItem(QString());
        comboBox_detType->addItem(QString());
        comboBox_detType->addItem(QString());
        comboBox_detType->setObjectName(QString::fromUtf8("comboBox_detType"));

        horizontalLayout->addWidget(comboBox_detType);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        comboBox_model = new QComboBox(groupBox);
        comboBox_model->addItem(QString());
        comboBox_model->addItem(QString());
        comboBox_model->addItem(QString());
        comboBox_model->setObjectName(QString::fromUtf8("comboBox_model"));

        horizontalLayout_3->addWidget(comboBox_model);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 2, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_start = new QPushButton(widget_para);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setMinimumSize(QSize(5, 0));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resource/image/play.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_start->setIcon(icon2);

        horizontalLayout_4->addWidget(pushButton_start);

        pushButton_end = new QPushButton(widget_para);
        pushButton_end->setObjectName(QString::fromUtf8("pushButton_end"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resource/image/stop.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_end->setIcon(icon3);

        horizontalLayout_4->addWidget(pushButton_end);


        gridLayout->addLayout(horizontalLayout_4, 0, 1, 1, 1);


        gridLayout_4->addWidget(widget_para, 0, 0, 1, 1);

        widget_show = new QWidget(centralwidget);
        widget_show->setObjectName(QString::fromUtf8("widget_show"));
        gridLayout_3 = new QGridLayout(widget_show);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_pic = new QLabel(widget_show);
        label_pic->setObjectName(QString::fromUtf8("label_pic"));
        label_pic->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label_pic->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_pic, 0, 0, 1, 1);

        textEdit = new QTextEdit(widget_show);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout_3->addWidget(textEdit, 0, 1, 1, 1);

        gridLayout_3->setColumnStretch(0, 7);
        gridLayout_3->setColumnStretch(1, 3);

        gridLayout_4->addWidget(widget_show, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\345\217\202\346\225\260", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\350\267\257\345\276\204\357\274\232", nullptr));
        pushButton_selectedFile->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\243\200\346\265\213\347\261\273\345\236\213\357\274\232", nullptr));
        comboBox_detType->setItemText(0, QCoreApplication::translate("MainWindow", "\345\233\276\347\211\207\357\274\210\345\215\225\345\274\240\357\274\211", nullptr));
        comboBox_detType->setItemText(1, QCoreApplication::translate("MainWindow", "\345\233\276\347\211\207\357\274\210\346\226\207\344\273\266\345\244\271\357\274\211", nullptr));
        comboBox_detType->setItemText(2, QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221\357\274\210\346\234\254\345\234\260\357\274\211", nullptr));
        comboBox_detType->setItemText(3, QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221\357\274\210\347\233\270\346\234\272\357\274\211", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "\346\250\241\345\236\213\357\274\232", nullptr));
        comboBox_model->setItemText(0, QCoreApplication::translate("MainWindow", "yolov8s", nullptr));
        comboBox_model->setItemText(1, QCoreApplication::translate("MainWindow", "yolov8m", nullptr));
        comboBox_model->setItemText(2, QCoreApplication::translate("MainWindow", "yolov8x", nullptr));

        pushButton_start->setText(QCoreApplication::translate("MainWindow", "\345\220\257\345\212\250", nullptr));
        pushButton_end->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
        label_pic->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
