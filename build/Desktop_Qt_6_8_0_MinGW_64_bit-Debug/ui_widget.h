/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPushButton *quitButton;
    QLineEdit *botolvEdit;
    QPushButton *okButton;
    QLabel *label_7;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *sendHexBox;
    QLineEdit *sendEdit;
    QCheckBox *recvHexBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *openButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *closeButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *sendButton;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *cleanButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *saveButton;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QComboBox *serianumBox;
    QComboBox *botolvBox;
    QComboBox *databitBox;
    QComboBox *stopbitBox;
    QComboBox *jiaoyanBox;
    QPlainTextEdit *recvTextEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 480);
        QIcon icon;
        icon.addFile(QString::fromUtf8("pic/favicon (1).ico"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        Widget->setWindowIcon(icon);
        Widget->setAutoFillBackground(false);
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(310, 140, 176, 91));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/true.jfif);\n"
""));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName("gridLayout_2");
        quitButton = new QPushButton(groupBox_2);
        quitButton->setObjectName("quitButton");

        gridLayout_2->addWidget(quitButton, 2, 1, 1, 1);

        botolvEdit = new QLineEdit(groupBox_2);
        botolvEdit->setObjectName("botolvEdit");
        botolvEdit->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/true.jfif);"));

        gridLayout_2->addWidget(botolvEdit, 1, 0, 1, 2);

        okButton = new QPushButton(groupBox_2);
        okButton->setObjectName("okButton");

        gridLayout_2->addWidget(okButton, 2, 0, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName("label_7");
        QFont font;
        font.setBold(true);
        label_7->setFont(font);
        label_7->setFocusPolicy(Qt::FocusPolicy::WheelFocus);
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label_7, 0, 0, 1, 2);

        gridLayout_3 = new QGridLayout(Widget);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName("groupBox");
        groupBox->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/bg.jpg);\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.1875 rgba(255, 255, 255, 255));"));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/images/dino.png);"));

        horizontalLayout_3->addWidget(pushButton);

        horizontalSpacer_7 = new QSpacerItem(139, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        QFont font1;
        font1.setPointSize(18);
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/bg.jpg);\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.1875 rgba(255, 255, 255, 255));"));

        horizontalLayout_3->addWidget(label_6);

        horizontalSpacer_6 = new QSpacerItem(139, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout_3->addWidget(groupBox);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        sendHexBox = new QCheckBox(Widget);
        sendHexBox->setObjectName("sendHexBox");
        sendHexBox->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/bg.jpg);\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.1875 rgba(255, 255, 255, 255));"));

        horizontalLayout_4->addWidget(sendHexBox);

        sendEdit = new QLineEdit(Widget);
        sendEdit->setObjectName("sendEdit");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221")});
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setItalic(false);
        sendEdit->setFont(font2);
        sendEdit->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/true.jfif);\n"
"font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
""));
        sendEdit->setCursorPosition(0);
        sendEdit->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);

        horizontalLayout_4->addWidget(sendEdit);

        recvHexBox = new QCheckBox(Widget);
        recvHexBox->setObjectName("recvHexBox");
        recvHexBox->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/bg.jpg);\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.1875 rgba(255, 255, 255, 255));"));

        horizontalLayout_4->addWidget(recvHexBox);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        openButton = new QPushButton(Widget);
        openButton->setObjectName("openButton");
        openButton->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/bg.jpg);\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.1875 rgba(255, 255, 255, 255));"));

        horizontalLayout_2->addWidget(openButton);

        horizontalSpacer = new QSpacerItem(28, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        closeButton = new QPushButton(Widget);
        closeButton->setObjectName("closeButton");
        closeButton->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/bg.jpg);\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.1875 rgba(255, 255, 255, 255));"));

        horizontalLayout_2->addWidget(closeButton);

        horizontalSpacer_2 = new QSpacerItem(28, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        sendButton = new QPushButton(Widget);
        sendButton->setObjectName("sendButton");
        sendButton->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/bg.jpg);\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.1875 rgba(255, 255, 255, 255));"));

        horizontalLayout_2->addWidget(sendButton);

        horizontalSpacer_3 = new QSpacerItem(28, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        cleanButton = new QPushButton(Widget);
        cleanButton->setObjectName("cleanButton");
        cleanButton->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/bg.jpg);\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.1875 rgba(255, 255, 255, 255));"));

        horizontalLayout_2->addWidget(cleanButton);

        horizontalSpacer_4 = new QSpacerItem(28, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        saveButton = new QPushButton(Widget);
        saveButton->setObjectName("saveButton");
        saveButton->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/bg.jpg);\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.1875 rgba(255, 255, 255, 255));"));

        horizontalLayout_2->addWidget(saveButton);


        verticalLayout_3->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_3, 2, 1, 1, 1);

        label_8 = new QLabel(Widget);
        label_8->setObjectName("label_8");
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setKerning(true);
        label_8->setFont(font3);
        label_8->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/bg.jpg);\n"
"color: rgb(255, 255, 0);"));
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_8, 0, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/bg.jpg);\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.1875 rgba(255, 255, 255, 255));"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/bg.jpg);\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.1875 rgba(255, 255, 255, 255));"));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/bg.jpg);\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.1875 rgba(255, 255, 255, 255));"));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(Widget);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/bg.jpg);\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.1875 rgba(255, 255, 255, 255));"));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(Widget);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/bg.jpg);\n"
"color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(0, 0, 0, 255), stop:0.1875 rgba(255, 255, 255, 255));"));
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        serianumBox = new QComboBox(Widget);
        serianumBox->setObjectName("serianumBox");
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(true);
        serianumBox->setFont(font4);
        serianumBox->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/true.jfif);"));

        verticalLayout_2->addWidget(serianumBox);

        botolvBox = new QComboBox(Widget);
        botolvBox->addItem(QString());
        botolvBox->addItem(QString());
        botolvBox->addItem(QString());
        botolvBox->addItem(QString());
        botolvBox->addItem(QString());
        botolvBox->setObjectName("botolvBox");
        botolvBox->setFont(font);
        botolvBox->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        botolvBox->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/true.jfif);"));
        botolvBox->setEditable(true);
        botolvBox->setFrame(true);

        verticalLayout_2->addWidget(botolvBox);

        databitBox = new QComboBox(Widget);
        databitBox->addItem(QString());
        databitBox->addItem(QString());
        databitBox->addItem(QString());
        databitBox->addItem(QString());
        databitBox->setObjectName("databitBox");
        databitBox->setFont(font);
        databitBox->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/true.jfif);"));

        verticalLayout_2->addWidget(databitBox);

        stopbitBox = new QComboBox(Widget);
        stopbitBox->addItem(QString());
        stopbitBox->addItem(QString());
        stopbitBox->addItem(QString());
        stopbitBox->setObjectName("stopbitBox");
        stopbitBox->setFont(font);
        stopbitBox->setAutoFillBackground(false);
        stopbitBox->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/true.jfif);"));
        stopbitBox->setFrame(true);

        verticalLayout_2->addWidget(stopbitBox);

        jiaoyanBox = new QComboBox(Widget);
        jiaoyanBox->addItem(QString());
        jiaoyanBox->addItem(QString());
        jiaoyanBox->addItem(QString());
        jiaoyanBox->setObjectName("jiaoyanBox");
        jiaoyanBox->setFont(font);
        jiaoyanBox->setStyleSheet(QString::fromUtf8("border-image: url(:/pic/true.jfif);"));

        verticalLayout_2->addWidget(jiaoyanBox);


        horizontalLayout->addLayout(verticalLayout_2);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        recvTextEdit = new QPlainTextEdit(Widget);
        recvTextEdit->setObjectName("recvTextEdit");
        recvTextEdit->setAutoFillBackground(false);
        recvTextEdit->setStyleSheet(QString::fromUtf8("background-image: url(:/pic/bg.jpg);"));
        recvTextEdit->setLineWidth(4);
        recvTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);
        recvTextEdit->setTabChangesFocus(false);
        recvTextEdit->setUndoRedoEnabled(false);
        recvTextEdit->setReadOnly(false);
        recvTextEdit->setCursorWidth(3);
        recvTextEdit->setMaximumBlockCount(0);
        recvTextEdit->setBackgroundVisible(false);

        gridLayout->addWidget(recvTextEdit, 1, 0, 1, 2);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        recvTextEdit->raise();
        label_8->raise();
        groupBox_2->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\345\260\217\346\226\260\347\232\204\344\270\262\345\217\243\345\212\251\346\211\213", nullptr));
        groupBox_2->setTitle(QString());
        quitButton->setText(QCoreApplication::translate("Widget", "quit", nullptr));
        okButton->setText(QCoreApplication::translate("Widget", "ok", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\346\263\242\347\211\271\347\216\207", nullptr));
        groupBox->setTitle(QString());
        pushButton->setText(QString());
        label_6->setText(QCoreApplication::translate("Widget", "\350\207\252\345\210\266\344\270\262\345\217\243\345\212\251\346\211\213", nullptr));
        sendHexBox->setText(QCoreApplication::translate("Widget", "Hex\345\217\221\351\200\201", nullptr));
        recvHexBox->setText(QCoreApplication::translate("Widget", "Hex\346\230\276\347\244\272", nullptr));
        openButton->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200", nullptr));
        closeButton->setText(QCoreApplication::translate("Widget", "\345\205\263\351\227\255", nullptr));
        sendButton->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        cleanButton->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272", nullptr));
        saveButton->setText(QCoreApplication::translate("Widget", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\344\270\262\345\217\243\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207 ", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\346\225\260\346\215\256\344\275\215", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242\344\275\215", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "\346\240\241\351\252\214\344\275\215", nullptr));
        botolvBox->setItemText(0, QCoreApplication::translate("Widget", "4800", nullptr));
        botolvBox->setItemText(1, QCoreApplication::translate("Widget", "9600", nullptr));
        botolvBox->setItemText(2, QCoreApplication::translate("Widget", "115200", nullptr));
        botolvBox->setItemText(3, QCoreApplication::translate("Widget", "2000000", nullptr));
        botolvBox->setItemText(4, QCoreApplication::translate("Widget", "Custom", nullptr));

        databitBox->setItemText(0, QCoreApplication::translate("Widget", "8", nullptr));
        databitBox->setItemText(1, QCoreApplication::translate("Widget", "5", nullptr));
        databitBox->setItemText(2, QCoreApplication::translate("Widget", "6", nullptr));
        databitBox->setItemText(3, QCoreApplication::translate("Widget", "7", nullptr));

        stopbitBox->setItemText(0, QCoreApplication::translate("Widget", "1", nullptr));
        stopbitBox->setItemText(1, QCoreApplication::translate("Widget", "1.5", nullptr));
        stopbitBox->setItemText(2, QCoreApplication::translate("Widget", "2", nullptr));

        jiaoyanBox->setItemText(0, QCoreApplication::translate("Widget", "0", nullptr));
        jiaoyanBox->setItemText(1, QCoreApplication::translate("Widget", "1", nullptr));
        jiaoyanBox->setItemText(2, QCoreApplication::translate("Widget", "2", nullptr));

        recvTextEdit->setPlainText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
