/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include <image_processing.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_3;
    QPushButton *crop_button;
    image_processing *original_image;
    image_processing *image_canvas;
    QPushButton *redo_button;
    QPushButton *undo_button;
    QDial *dial;
    QSlider *zoom_slider;
    QPushButton *save_button;
    QPushButton *back_button;
    QPushButton *reset_button;
    image_processing *backup_image;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(829, 999);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(40, 120, 661, 471));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 645, 455));
        scrollArea->setWidget(scrollAreaWidgetContents_3);
        crop_button = new QPushButton(centralWidget);
        crop_button->setObjectName(QStringLiteral("crop_button"));
        crop_button->setGeometry(QRect(70, 900, 80, 25));
        original_image = new image_processing(centralWidget);
        original_image->setObjectName(QStringLiteral("original_image"));
        original_image->setEnabled(true);
        original_image->setGeometry(QRect(200, 590, 51, 41));
        original_image->setFrameShape(QFrame::Box);
        image_canvas = new image_processing(centralWidget);
        image_canvas->setObjectName(QStringLiteral("image_canvas"));
        image_canvas->setGeometry(QRect(310, 590, 51, 41));
        image_canvas->setFrameShape(QFrame::Box);
        redo_button = new QPushButton(centralWidget);
        redo_button->setObjectName(QStringLiteral("redo_button"));
        redo_button->setGeometry(QRect(0, 0, 80, 25));
        undo_button = new QPushButton(centralWidget);
        undo_button->setObjectName(QStringLiteral("undo_button"));
        undo_button->setGeometry(QRect(370, 920, 80, 25));
        dial = new QDial(centralWidget);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(450, 850, 100, 100));
        dial->setMaximum(360);
        dial->setSingleStep(10);
        dial->setPageStep(20);
        dial->setOrientation(Qt::Vertical);
        zoom_slider = new QSlider(centralWidget);
        zoom_slider->setObjectName(QStringLiteral("zoom_slider"));
        zoom_slider->setGeometry(QRect(60, 740, 541, 71));
        zoom_slider->setMinimum(20);
        zoom_slider->setMaximum(200);
        zoom_slider->setPageStep(30);
        zoom_slider->setValue(100);
        zoom_slider->setOrientation(Qt::Horizontal);
        save_button = new QPushButton(centralWidget);
        save_button->setObjectName(QStringLiteral("save_button"));
        save_button->setGeometry(QRect(580, 20, 161, 91));
        back_button = new QPushButton(centralWidget);
        back_button->setObjectName(QStringLiteral("back_button"));
        back_button->setGeometry(QRect(60, 20, 131, 61));
        reset_button = new QPushButton(centralWidget);
        reset_button->setObjectName(QStringLiteral("reset_button"));
        reset_button->setGeometry(QRect(190, 920, 89, 25));
        backup_image = new image_processing(centralWidget);
        backup_image->setObjectName(QStringLiteral("backup_image"));
        backup_image->setGeometry(QRect(380, 590, 51, 41));
        backup_image->setFrameShape(QFrame::Box);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        crop_button->setText(QApplication::translate("MainWindow", "crop", Q_NULLPTR));
        original_image->setText(QString());
        image_canvas->setText(QString());
        redo_button->setText(QApplication::translate("MainWindow", "Redo", Q_NULLPTR));
        undo_button->setText(QApplication::translate("MainWindow", "Undo", Q_NULLPTR));
        save_button->setText(QApplication::translate("MainWindow", "save", Q_NULLPTR));
        back_button->setText(QApplication::translate("MainWindow", "back", Q_NULLPTR));
        reset_button->setText(QApplication::translate("MainWindow", "reset", Q_NULLPTR));
        backup_image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
