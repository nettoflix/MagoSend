/********************************************************************************
** Form generated from reading UI file 'CLoginForm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLOGINFORM_H
#define UI_CLOGINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CLoginForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *le_user;
    QLineEdit *le_password;
    QPushButton *btn_entrar;
    QPushButton *btn_cadastrar;

    void setupUi(QWidget *CLoginForm)
    {
        if (CLoginForm->objectName().isEmpty())
            CLoginForm->setObjectName(QStringLiteral("CLoginForm"));
        CLoginForm->resize(553, 284);
        verticalLayout_2 = new QVBoxLayout(CLoginForm);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(CLoginForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(label_3, 0, Qt::AlignHCenter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(CLoginForm);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(16777215, 30));

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(CLoginForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMaximumSize(QSize(16777215, 30));

        verticalLayout_3->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        le_user = new QLineEdit(CLoginForm);
        le_user->setObjectName(QStringLiteral("le_user"));

        verticalLayout_4->addWidget(le_user);

        le_password = new QLineEdit(CLoginForm);
        le_password->setObjectName(QStringLiteral("le_password"));
        le_password->setEchoMode(QLineEdit::Password);

        verticalLayout_4->addWidget(le_password);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout->addLayout(horizontalLayout);

        btn_entrar = new QPushButton(CLoginForm);
        btn_entrar->setObjectName(QStringLiteral("btn_entrar"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_entrar->sizePolicy().hasHeightForWidth());
        btn_entrar->setSizePolicy(sizePolicy1);
        btn_entrar->setMinimumSize(QSize(0, 18));
        btn_entrar->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(btn_entrar);

        btn_cadastrar = new QPushButton(CLoginForm);
        btn_cadastrar->setObjectName(QStringLiteral("btn_cadastrar"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btn_cadastrar->sizePolicy().hasHeightForWidth());
        btn_cadastrar->setSizePolicy(sizePolicy2);
        btn_cadastrar->setMinimumSize(QSize(0, 80));
        btn_cadastrar->setMaximumSize(QSize(16777215, 100));
        btn_cadastrar->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"margin-top: 40px;\n"
"margin-bottom: 10px;\n"
"margin-left: 5px;\n"
"padding-left: 6px;\n"
"padding-right: 6px\n"
"}"));

        verticalLayout->addWidget(btn_cadastrar, 0, Qt::AlignLeft);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(CLoginForm);

        QMetaObject::connectSlotsByName(CLoginForm);
    } // setupUi

    void retranslateUi(QWidget *CLoginForm)
    {
        CLoginForm->setWindowTitle(QApplication::translate("CLoginForm", "Form", Q_NULLPTR));
        label_3->setText(QApplication::translate("CLoginForm", "Login", Q_NULLPTR));
        label->setText(QApplication::translate("CLoginForm", "Usu\303\241rio", Q_NULLPTR));
        label_2->setText(QApplication::translate("CLoginForm", "Senha", Q_NULLPTR));
        btn_entrar->setText(QApplication::translate("CLoginForm", "Entrar", Q_NULLPTR));
        btn_cadastrar->setText(QApplication::translate("CLoginForm", "Cadastrar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CLoginForm: public Ui_CLoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLOGINFORM_H
