/********************************************************************************
** Form generated from reading UI file 'CCadastrarLoginForm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCADASTRARLOGINFORM_H
#define UI_CCADASTRARLOGINFORM_H

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

class Ui_CCadastrarLoginForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *le_user;
    QLineEdit *le_password;
    QLineEdit *le_repeatepassword;
    QPushButton *btn_registrar;

    void setupUi(QWidget *CCadastrarLoginForm)
    {
        if (CCadastrarLoginForm->objectName().isEmpty())
            CCadastrarLoginForm->setObjectName(QStringLiteral("CCadastrarLoginForm"));
        CCadastrarLoginForm->resize(540, 174);
        CCadastrarLoginForm->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(CCadastrarLoginForm);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(CCadastrarLoginForm);
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
        label = new QLabel(CCadastrarLoginForm);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(40, 20));
        label->setMaximumSize(QSize(16777215, 25));
        label->setStyleSheet(QLatin1String("QLabel{\n"
"margin-top: 2px;	\n"
"image: url(:/images/mago.png);\n"
"}"));

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(CCadastrarLoginForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(16777215, 23));
        label_2->setStyleSheet(QLatin1String("QLabel{\n"
"margin-top:5px;\n"
"image: url(:/images/cadeado.png);\n"
"}"));

        verticalLayout_3->addWidget(label_2);

        label_4 = new QLabel(CCadastrarLoginForm);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_3->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        le_user = new QLineEdit(CCadastrarLoginForm);
        le_user->setObjectName(QStringLiteral("le_user"));
        le_user->setMinimumSize(QSize(0, 25));

        verticalLayout_4->addWidget(le_user);

        le_password = new QLineEdit(CCadastrarLoginForm);
        le_password->setObjectName(QStringLiteral("le_password"));
        le_password->setMinimumSize(QSize(0, 25));
        le_password->setEchoMode(QLineEdit::Password);

        verticalLayout_4->addWidget(le_password);

        le_repeatepassword = new QLineEdit(CCadastrarLoginForm);
        le_repeatepassword->setObjectName(QStringLiteral("le_repeatepassword"));
        le_repeatepassword->setMinimumSize(QSize(0, 25));
        le_repeatepassword->setEchoMode(QLineEdit::Password);

        verticalLayout_4->addWidget(le_repeatepassword);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout->addLayout(horizontalLayout);

        btn_registrar = new QPushButton(CCadastrarLoginForm);
        btn_registrar->setObjectName(QStringLiteral("btn_registrar"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_registrar->sizePolicy().hasHeightForWidth());
        btn_registrar->setSizePolicy(sizePolicy1);
        btn_registrar->setMinimumSize(QSize(0, 18));
        btn_registrar->setMaximumSize(QSize(16777215, 30));

        verticalLayout->addWidget(btn_registrar);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(CCadastrarLoginForm);

        QMetaObject::connectSlotsByName(CCadastrarLoginForm);
    } // setupUi

    void retranslateUi(QWidget *CCadastrarLoginForm)
    {
        CCadastrarLoginForm->setWindowTitle(QApplication::translate("CCadastrarLoginForm", "Form", Q_NULLPTR));
        label_3->setText(QApplication::translate("CCadastrarLoginForm", "Cadastro do usu\303\241rio", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QString());
        label_4->setText(QString());
#ifndef QT_NO_TOOLTIP
        le_user->setToolTip(QApplication::translate("CCadastrarLoginForm", "Digite o nome do usu\303\241rio", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        le_user->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_ACCESSIBILITY
        le_user->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        le_user->setPlaceholderText(QApplication::translate("CCadastrarLoginForm", "usu\303\241rio", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        le_password->setToolTip(QApplication::translate("CCadastrarLoginForm", "Escolha uma senha", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        le_password->setPlaceholderText(QApplication::translate("CCadastrarLoginForm", "senha", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        le_repeatepassword->setToolTip(QApplication::translate("CCadastrarLoginForm", "Confirme sua senha", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        le_repeatepassword->setPlaceholderText(QApplication::translate("CCadastrarLoginForm", "confirme a senha", Q_NULLPTR));
        btn_registrar->setText(QApplication::translate("CCadastrarLoginForm", "Registrar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CCadastrarLoginForm: public Ui_CCadastrarLoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCADASTRARLOGINFORM_H
