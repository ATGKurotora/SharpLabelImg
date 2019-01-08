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
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *browseLineEdit;
    QPushButton *browseButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *prevButton;
    MyQLabel *imgLabel;
    QPushButton *nextButton;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *saveLineEdit;
    QPushButton *saveButton;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *nameLabel;
    QLineEdit *nameLabelLineEdit;
    QPushButton *useLabelButton;
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
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        browseLineEdit = new QLineEdit(centralWidget);
        browseLineEdit->setObjectName(QStringLiteral("browseLineEdit"));

        horizontalLayout_5->addWidget(browseLineEdit);

        browseButton = new QPushButton(centralWidget);
        browseButton->setObjectName(QStringLiteral("browseButton"));

        horizontalLayout_5->addWidget(browseButton);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        prevButton = new QPushButton(centralWidget);
        prevButton->setObjectName(QStringLiteral("prevButton"));

        horizontalLayout->addWidget(prevButton);

        imgLabel = new MyQLabel(centralWidget);
        imgLabel->setObjectName(QStringLiteral("imgLabel"));
        imgLabel->setMouseTracking(true);

        horizontalLayout->addWidget(imgLabel);

        nextButton = new QPushButton(centralWidget);
        nextButton->setObjectName(QStringLiteral("nextButton"));

        horizontalLayout->addWidget(nextButton);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);
        horizontalLayout->setStretch(2, 1);

        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        saveLineEdit = new QLineEdit(centralWidget);
        saveLineEdit->setObjectName(QStringLiteral("saveLineEdit"));

        horizontalLayout_2->addWidget(saveLineEdit);

        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout_2->addWidget(saveButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout_6->addLayout(verticalLayout_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        nameLabel = new QLabel(centralWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        nameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(nameLabel);

        nameLabelLineEdit = new QLineEdit(centralWidget);
        nameLabelLineEdit->setObjectName(QStringLiteral("nameLabelLineEdit"));

        verticalLayout->addWidget(nameLabelLineEdit);

        useLabelButton = new QPushButton(centralWidget);
        useLabelButton->setObjectName(QStringLiteral("useLabelButton"));

        verticalLayout->addWidget(useLabelButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_6->addLayout(verticalLayout);

        horizontalLayout_6->setStretch(0, 8);
        horizontalLayout_6->setStretch(1, 1);
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
        nameLabel->setText(QApplication::translate("MyLabelImgClass", "label:", nullptr));
        useLabelButton->setText(QApplication::translate("MyLabelImgClass", "use", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyLabelImgClass: public Ui_MyLabelImgClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYLABELIMG_H
