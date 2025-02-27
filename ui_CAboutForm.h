/********************************************************************************
** Form generated from reading UI file 'CAboutForm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CABOUTFORM_H
#define UI_CABOUTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CAboutForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLabel *label;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_3;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_3;
    QFrame *line_3;

    void setupUi(QWidget *CAboutForm)
    {
        if (CAboutForm->objectName().isEmpty())
            CAboutForm->setObjectName(QStringLiteral("CAboutForm"));
        CAboutForm->setWindowModality(Qt::ApplicationModal);
        CAboutForm->resize(500, 395);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CAboutForm->sizePolicy().hasHeightForWidth());
        CAboutForm->setSizePolicy(sizePolicy);
        CAboutForm->setMinimumSize(QSize(339, 300));
        CAboutForm->setMaximumSize(QSize(500, 395));
        CAboutForm->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(CAboutForm);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(CAboutForm);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(77, 0));
        label_4->setMaximumSize(QSize(50, 75));
        label_4->setSizeIncrement(QSize(170, 0));
        label_4->setPixmap(QPixmap(QString::fromUtf8(":/images/icon.png")));
        label_4->setScaledContents(true);

        horizontalLayout->addWidget(label_4);

        label = new QLabel(CAboutForm);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("QWidget {\n"
"	background: lightgray;\n"
"}\n"
"\n"
"QLabel {\n"
"	border: 1px solid black;\n"
"	border-radius: 6px;\n"
"}"));

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(CAboutForm);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(CAboutForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QLatin1String("\n"
"QLabel {\n"
"	border: 1px solid black;\n"
"	border-radius: 6px;\n"
"}"));
        label_3->setOpenExternalLinks(true);

        horizontalLayout_3->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));

        verticalLayout->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        line_2 = new QFrame(CAboutForm);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(CAboutForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(40, 30));

        horizontalLayout_6->addWidget(pushButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_6);

        line_3 = new QFrame(CAboutForm);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);


        retranslateUi(CAboutForm);

        QMetaObject::connectSlotsByName(CAboutForm);
    } // setupUi

    void retranslateUi(QWidget *CAboutForm)
    {
        CAboutForm->setWindowTitle(QApplication::translate("CAboutForm", "Sobre o MagoSend", Q_NULLPTR));
        label_4->setText(QString());
        label->setText(QApplication::translate("CAboutForm", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#000000;\">4S - MagoSend</span></p><p align=\"center\"><span style=\" font-weight:600; color:#000000;\">Distribui\303\247\303\243o local de v\303\255deos</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("CAboutForm", "<html><head/><body><p align=\"center\"><br/><span style=\" font-size:9pt; font-weight:600; color:#3daee9;\">Vers\303\243o</span><span style=\" font-size:9pt; font-weight:600;\">:</span><span style=\" color:#ffcd8b; background-color:#404040;\">#version</span></p><p align=\"center\"><span style=\" font-size:9pt; font-weight:600; color:#3daee9;\">Copyright</span><span style=\" font-size:9pt; font-weight:600;\">:</span><span style=\" font-size:9pt;\"> 4S Inform\303\241tica Ind\303\272stria e Com\303\251rcio Ltda </span></p><p align=\"center\"><span style=\" font-size:9pt; font-weight:600; color:#3daee9;\">Fone</span><span style=\" font-size:9pt; font-weight:600;\">:</span><span style=\" font-size:9pt;\"> +55 48 3234-0445</span></p><p align=\"center\"><span style=\" font-size:9pt; font-weight:600; color:#3daee9;\">WhatsApp:</span><span style=\" font-size:9pt;\"> +55 48 9987-3940</span></p><p align=\"center\"><span style=\" font-size:9pt; font-weight:600; color:#3daee9;\">Site</span><span style=\" font-size:9pt; fon"
                        "t-weight:600;\">: </span><a href=\"http://mago.tv.br/\"><span style=\" font-size:9pt; text-decoration: underline; color:#007af4;\">http://mago.tv.br/</span></a></p><p align=\"center\"><br/><span style=\" font-family:'Arial,Tahoma,Calibri,Verdana,Geneva,sans-serif'; font-size:11px; color:#333333; background-color:#a3aeb6;\">Copyright \302\2512018-2023, 4S Informatica Ltd. </span><br/></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("CAboutForm", "OK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CAboutForm: public Ui_CAboutForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CABOUTFORM_H
