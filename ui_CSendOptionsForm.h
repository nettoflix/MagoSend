/********************************************************************************
** Form generated from reading UI file 'CSendOptionsForm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSENDOPTIONSFORM_H
#define UI_CSENDOPTIONSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CSendOptionsForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBox_arquivo;
    QCheckBox *checkBox_id;

    void setupUi(QDialog *CSendOptionsForm)
    {
        if (CSendOptionsForm->objectName().isEmpty())
            CSendOptionsForm->setObjectName(QStringLiteral("CSendOptionsForm"));
        CSendOptionsForm->resize(485, 74);
        CSendOptionsForm->setStyleSheet(QLatin1String("QCheckBox::indicator{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"    border: 1px solid #b1b1b1;\n"
"    width: 15px;\n"
"    height: 15px;\n"
"}\n"
"\n"
"QRadioButton::indicator\n"
"{\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:hover, QCheckBox::indicator:hover\n"
"{\n"
"    border: 1px solid #ffaa00;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image:url(:/images/checkbox.png);\n"
"\n"
"\n"
"}\n"
"\n"
"QCheckBox::indicator:disabled, QRadioButton::indicator:disabled\n"
"{\n"
"    border: 1px solid #444;\n"
"\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
""));
        verticalLayout_2 = new QVBoxLayout(CSendOptionsForm);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        checkBox_arquivo = new QCheckBox(CSendOptionsForm);
        checkBox_arquivo->setObjectName(QStringLiteral("checkBox_arquivo"));
        QFont font;
        font.setPointSize(14);
        checkBox_arquivo->setFont(font);

        verticalLayout_3->addWidget(checkBox_arquivo);

        checkBox_id = new QCheckBox(CSendOptionsForm);
        checkBox_id->setObjectName(QStringLiteral("checkBox_id"));
        checkBox_id->setMinimumSize(QSize(0, 0));
        checkBox_id->setFont(font);
        checkBox_id->setIconSize(QSize(32, 32));

        verticalLayout_3->addWidget(checkBox_id);


        verticalLayout->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(CSendOptionsForm);

        QMetaObject::connectSlotsByName(CSendOptionsForm);
    } // setupUi

    void retranslateUi(QDialog *CSendOptionsForm)
    {
        CSendOptionsForm->setWindowTitle(QApplication::translate("CSendOptionsForm", "Dialog", Q_NULLPTR));
        checkBox_arquivo->setText(QApplication::translate("CSendOptionsForm", "Sempre avisar sobre arquivos existentes no destino", Q_NULLPTR));
        checkBox_id->setText(QApplication::translate("CSendOptionsForm", "Sempre avisar sobre ID existente no destino", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CSendOptionsForm: public Ui_CSendOptionsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSENDOPTIONSFORM_H
