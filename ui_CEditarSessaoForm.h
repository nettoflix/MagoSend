/********************************************************************************
** Form generated from reading UI file 'CEditarSessaoForm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CEDITARSESSAOFORM_H
#define UI_CEDITARSESSAOFORM_H

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

class Ui_CEditarSessaoForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *cb_Sessoes;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *btn_excluirSessao;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QPushButton *btn_criarSessao;
    QPushButton *btn_ok;

    void setupUi(QWidget *CEditarSessaoForm)
    {
        if (CEditarSessaoForm->objectName().isEmpty())
            CEditarSessaoForm->setObjectName(QStringLiteral("CEditarSessaoForm"));
        CEditarSessaoForm->resize(370, 300);
        CEditarSessaoForm->setMinimumSize(QSize(0, 300));
        CEditarSessaoForm->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(CEditarSessaoForm);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(CEditarSessaoForm);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 0));
        label->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        cb_Sessoes = new QComboBox(CEditarSessaoForm);
        cb_Sessoes->setObjectName(QStringLiteral("cb_Sessoes"));
        cb_Sessoes->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cb_Sessoes->sizePolicy().hasHeightForWidth());
        cb_Sessoes->setSizePolicy(sizePolicy1);
        cb_Sessoes->setMinimumSize(QSize(350, 21));
        cb_Sessoes->setStyleSheet(QLatin1String("QComboBox\n"
"{\n"
"    margin-left: 20px;\n"
"	margin-right: 20px;\n"
"	\n"
"}"));

        verticalLayout->addWidget(cb_Sessoes, 0, Qt::AlignHCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        pushButton = new QPushButton(CEditarSessaoForm);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setMinimumSize(QSize(50, 0));

        horizontalLayout->addWidget(pushButton, 0, Qt::AlignRight);

        btn_excluirSessao = new QPushButton(CEditarSessaoForm);
        btn_excluirSessao->setObjectName(QStringLiteral("btn_excluirSessao"));
        btn_excluirSessao->setMinimumSize(QSize(50, 0));
        btn_excluirSessao->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	margin-right: 10px\n"
"}"));

        horizontalLayout->addWidget(btn_excluirSessao, 0, Qt::AlignRight);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(CEditarSessaoForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);
        label_2->setMaximumSize(QSize(16777215, 30));
        label_2->setFont(font);

        verticalLayout_3->addWidget(label_2);

        btn_criarSessao = new QPushButton(CEditarSessaoForm);
        btn_criarSessao->setObjectName(QStringLiteral("btn_criarSessao"));

        verticalLayout_3->addWidget(btn_criarSessao, 0, Qt::AlignLeft);

        btn_ok = new QPushButton(CEditarSessaoForm);
        btn_ok->setObjectName(QStringLiteral("btn_ok"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(btn_ok->sizePolicy().hasHeightForWidth());
        btn_ok->setSizePolicy(sizePolicy4);
        btn_ok->setMinimumSize(QSize(70, 0));
        btn_ok->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"    margin-bottom: 10px;\n"
"	margin-right: 10px\n"
"}"));

        verticalLayout_3->addWidget(btn_ok, 0, Qt::AlignRight);


        verticalLayout->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(CEditarSessaoForm);

        QMetaObject::connectSlotsByName(CEditarSessaoForm);
    } // setupUi

    void retranslateUi(QWidget *CEditarSessaoForm)
    {
        CEditarSessaoForm->setWindowTitle(QApplication::translate("CEditarSessaoForm", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("CEditarSessaoForm", "Sess\303\265es", Q_NULLPTR));
        pushButton->setText(QApplication::translate("CEditarSessaoForm", "Editar", Q_NULLPTR));
        btn_excluirSessao->setText(QApplication::translate("CEditarSessaoForm", "Excluir", Q_NULLPTR));
        label_2->setText(QApplication::translate("CEditarSessaoForm", "Nova Sess\303\243o", Q_NULLPTR));
        btn_criarSessao->setText(QApplication::translate("CEditarSessaoForm", "Criar Sess\303\243o", Q_NULLPTR));
        btn_ok->setText(QApplication::translate("CEditarSessaoForm", "Ok", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CEditarSessaoForm: public Ui_CEditarSessaoForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CEDITARSESSAOFORM_H
