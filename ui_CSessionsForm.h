/********************************************************************************
** Form generated from reading UI file 'CSessionsForm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSESSIONSFORM_H
#define UI_CSESSIONSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CSessionsForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_editar_Sessao;
    QPushButton *pushButton;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *CSessionsForm)
    {
        if (CSessionsForm->objectName().isEmpty())
            CSessionsForm->setObjectName(QStringLiteral("CSessionsForm"));
        CSessionsForm->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(CSessionsForm);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(CSessionsForm);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        comboBox = new QComboBox(CSessionsForm);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        comboBox->setMinimumSize(QSize(300, 0));

        verticalLayout->addWidget(comboBox, 0, Qt::AlignHCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        btn_editar_Sessao = new QPushButton(CSessionsForm);
        btn_editar_Sessao->setObjectName(QStringLiteral("btn_editar_Sessao"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_editar_Sessao->sizePolicy().hasHeightForWidth());
        btn_editar_Sessao->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(btn_editar_Sessao, 0, Qt::AlignRight);

        pushButton = new QPushButton(CSessionsForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton, 0, Qt::AlignRight);


        verticalLayout->addLayout(horizontalLayout);

        label_2 = new QLabel(CSessionsForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label_2->setFont(font1);

        verticalLayout->addWidget(label_2);

        pushButton_3 = new QPushButton(CSessionsForm);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3, 0, Qt::AlignLeft);

        pushButton_4 = new QPushButton(CSessionsForm);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4, 0, Qt::AlignRight);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(CSessionsForm);

        QMetaObject::connectSlotsByName(CSessionsForm);
    } // setupUi

    void retranslateUi(QWidget *CSessionsForm)
    {
        CSessionsForm->setWindowTitle(QApplication::translate("CSessionsForm", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("CSessionsForm", "Sess\303\265es", Q_NULLPTR));
        btn_editar_Sessao->setText(QApplication::translate("CSessionsForm", "Editar", Q_NULLPTR));
        pushButton->setText(QApplication::translate("CSessionsForm", "Excluir", Q_NULLPTR));
        label_2->setText(QApplication::translate("CSessionsForm", "Nova Sess\303\243o", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("CSessionsForm", "Criar Sess\303\243o", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("CSessionsForm", "Ok", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CSessionsForm: public Ui_CSessionsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSESSIONSFORM_H
