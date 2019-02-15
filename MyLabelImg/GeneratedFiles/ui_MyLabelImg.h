/********************************************************************************
** Form generated from reading UI file 'MyLabelImg.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYLABELIMG_H
#define UI_MYLABELIMG_H

#include <MyQLabel.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyLabelImgClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *hLBrowse;
    QLabel *browseLabel;
    QPushButton *browseButton;
    QHBoxLayout *hLMain;
    QPushButton *prevButton;
    MyQLabel *imgLabel;
    QPushButton *nextButton;
    QHBoxLayout *hLSave;
    QLineEdit *saveLineEdit;
    QPushButton *saveButton;
    QVBoxLayout *vLLabel;
    QSpacerItem *verticalSpacer_2;
    QLabel *nameLabel;
    QLineEdit *nameLabelLineEdit;
    QPushButton *useLabelButton;
    QVBoxLayout *vLListLabel;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MyLabelImgClass)
    {
        if (MyLabelImgClass->objectName().isEmpty())
            MyLabelImgClass->setObjectName(QStringLiteral("MyLabelImgClass"));
        MyLabelImgClass->resize(1088, 699);
        centralWidget = new QWidget(MyLabelImgClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_6 = new QHBoxLayout(centralWidget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        hLBrowse = new QHBoxLayout();
        hLBrowse->setSpacing(6);
        hLBrowse->setObjectName(QStringLiteral("hLBrowse"));
        browseLabel = new QLabel(centralWidget);
        browseLabel->setObjectName(QStringLiteral("browseLabel"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        browseLabel->setFont(font);
        browseLabel->setMargin(10);

        hLBrowse->addWidget(browseLabel);

        browseButton = new QPushButton(centralWidget);
        browseButton->setObjectName(QStringLiteral("browseButton"));

        hLBrowse->addWidget(browseButton);

        hLBrowse->setStretch(0, 1);

        verticalLayout_3->addLayout(hLBrowse);

        hLMain = new QHBoxLayout();
        hLMain->setSpacing(6);
        hLMain->setObjectName(QStringLiteral("hLMain"));
        prevButton = new QPushButton(centralWidget);
        prevButton->setObjectName(QStringLiteral("prevButton"));

        hLMain->addWidget(prevButton);

        imgLabel = new MyQLabel(centralWidget);
        imgLabel->setObjectName(QStringLiteral("imgLabel"));
        imgLabel->setMouseTracking(true);

        hLMain->addWidget(imgLabel);

        nextButton = new QPushButton(centralWidget);
        nextButton->setObjectName(QStringLiteral("nextButton"));

        hLMain->addWidget(nextButton);

        hLMain->setStretch(0, 1);
        hLMain->setStretch(1, 5);
        hLMain->setStretch(2, 1);

        verticalLayout_3->addLayout(hLMain);

        hLSave = new QHBoxLayout();
        hLSave->setSpacing(6);
        hLSave->setObjectName(QStringLiteral("hLSave"));
        saveLineEdit = new QLineEdit(centralWidget);
        saveLineEdit->setObjectName(QStringLiteral("saveLineEdit"));

        hLSave->addWidget(saveLineEdit);

        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        hLSave->addWidget(saveButton);


        verticalLayout_3->addLayout(hLSave);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 10);
        verticalLayout_3->setStretch(2, 1);

        horizontalLayout_6->addLayout(verticalLayout_3);

        vLLabel = new QVBoxLayout();
        vLLabel->setSpacing(6);
        vLLabel->setObjectName(QStringLiteral("vLLabel"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vLLabel->addItem(verticalSpacer_2);

        nameLabel = new QLabel(centralWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setAlignment(Qt::AlignCenter);

        vLLabel->addWidget(nameLabel);

        nameLabelLineEdit = new QLineEdit(centralWidget);
        nameLabelLineEdit->setObjectName(QStringLiteral("nameLabelLineEdit"));
        nameLabelLineEdit->setClearButtonEnabled(false);

        vLLabel->addWidget(nameLabelLineEdit);

        useLabelButton = new QPushButton(centralWidget);
        useLabelButton->setObjectName(QStringLiteral("useLabelButton"));

        vLLabel->addWidget(useLabelButton);

        vLListLabel = new QVBoxLayout();
        vLListLabel->setSpacing(6);
        vLListLabel->setObjectName(QStringLiteral("vLListLabel"));

        vLLabel->addLayout(vLListLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vLLabel->addItem(verticalSpacer);


        horizontalLayout_6->addLayout(vLLabel);

        horizontalLayout_6->setStretch(0, 8);
        horizontalLayout_6->setStretch(1, 1);
        MyLabelImgClass->setCentralWidget(centralWidget);

        retranslateUi(MyLabelImgClass);

        QMetaObject::connectSlotsByName(MyLabelImgClass);
    } // setupUi

    void retranslateUi(QMainWindow *MyLabelImgClass)
    {
        MyLabelImgClass->setWindowTitle(QApplication::translate("MyLabelImgClass", "MyLabelImg", nullptr));
        browseLabel->setText(QApplication::translate("MyLabelImgClass", "Images from:", nullptr));
        browseButton->setText(QApplication::translate("MyLabelImgClass", "Browse", nullptr));
        prevButton->setText(QApplication::translate("MyLabelImgClass", "prev", nullptr));
#ifndef QT_NO_SHORTCUT
        prevButton->setShortcut(QApplication::translate("MyLabelImgClass", "Left", nullptr));
#endif // QT_NO_SHORTCUT
        imgLabel->setText(QString());
        nextButton->setText(QApplication::translate("MyLabelImgClass", "next", nullptr));
#ifndef QT_NO_SHORTCUT
        nextButton->setShortcut(QApplication::translate("MyLabelImgClass", "D", nullptr));
#endif // QT_NO_SHORTCUT
        saveButton->setText(QApplication::translate("MyLabelImgClass", "save", nullptr));
        nameLabel->setText(QApplication::translate("MyLabelImgClass", "actual label: none", nullptr));
        useLabelButton->setText(QApplication::translate("MyLabelImgClass", "use", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyLabelImgClass: public Ui_MyLabelImgClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYLABELIMG_H
