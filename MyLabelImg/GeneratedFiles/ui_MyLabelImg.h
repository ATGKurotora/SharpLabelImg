/********************************************************************************
** Form generated from reading UI file 'MyLabelImg.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYLABELIMG_H
#define UI_MYLABELIMG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyLabelImgClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *browseLayout;
    QLineEdit *browseLineEdit;
    QPushButton *browseButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *prevButton;
    QLabel *imgLabel;
    QPushButton *nextButton;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *saveLineEdit;
    QPushButton *saveButton;

    void setupUi(QMainWindow *MyLabelImgClass)
    {
        if (MyLabelImgClass->objectName().isEmpty())
            MyLabelImgClass->setObjectName(QStringLiteral("MyLabelImgClass"));
        MyLabelImgClass->resize(600, 400);
        centralWidget = new QWidget(MyLabelImgClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        browseLayout = new QHBoxLayout();
        browseLayout->setSpacing(6);
        browseLayout->setObjectName(QStringLiteral("browseLayout"));
        browseLineEdit = new QLineEdit(centralWidget);
        browseLineEdit->setObjectName(QStringLiteral("browseLineEdit"));

        browseLayout->addWidget(browseLineEdit);

        browseButton = new QPushButton(centralWidget);
        browseButton->setObjectName(QStringLiteral("browseButton"));

        browseLayout->addWidget(browseButton);


        verticalLayout->addLayout(browseLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        prevButton = new QPushButton(centralWidget);
        prevButton->setObjectName(QStringLiteral("prevButton"));

        horizontalLayout->addWidget(prevButton);

        imgLabel = new QLabel(centralWidget);
        imgLabel->setObjectName(QStringLiteral("imgLabel"));

        horizontalLayout->addWidget(imgLabel);

        nextButton = new QPushButton(centralWidget);
        nextButton->setObjectName(QStringLiteral("nextButton"));

        horizontalLayout->addWidget(nextButton);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        saveLineEdit = new QLineEdit(centralWidget);
        saveLineEdit->setObjectName(QStringLiteral("saveLineEdit"));

        horizontalLayout_2->addWidget(saveLineEdit);

        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout_2->addWidget(saveButton);


        verticalLayout->addLayout(horizontalLayout_2);

        MyLabelImgClass->setCentralWidget(centralWidget);

        retranslateUi(MyLabelImgClass);

        QMetaObject::connectSlotsByName(MyLabelImgClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyLabelImgClass)
    {
        MyLabelImgClass->setWindowTitle(QApplication::translate("MyLabelImgClass", "MyLabelImg", nullptr));
        browseButton->setText(QApplication::translate("MyLabelImgClass", "Browse", nullptr));
        prevButton->setText(QApplication::translate("MyLabelImgClass", "prev", nullptr));
#ifndef QT_NO_SHORTCUT
        prevButton->setShortcut(QApplication::translate("MyLabelImgClass", "Left", nullptr));
#endif // QT_NO_SHORTCUT
        imgLabel->setText(QString());
        nextButton->setText(QApplication::translate("MyLabelImgClass", "next", nullptr));
#ifndef QT_NO_SHORTCUT
        nextButton->setShortcut(QApplication::translate("MyLabelImgClass", "Right", nullptr));
#endif // QT_NO_SHORTCUT
        saveButton->setText(QApplication::translate("MyLabelImgClass", "save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyLabelImgClass: public Ui_MyLabelImgClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYLABELIMG_H
