/********************************************************************************
** Form generated from reading UI file 'CModalidadesForm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMODALIDADESFORM_H
#define UI_CMODALIDADESFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CModalidadesForm
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *Modalidades;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_importMods;
    QPushButton *btn_ExportarMods;
    QPushButton *btn_remover;
    QPushButton *btn_removerTodas;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *te_modName;
    QTextEdit *te_modDesc;
    QVBoxLayout *verticalLayout_5;
    QPushButton *btn_adicionarModalidade;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btn_Ok;

    void setupUi(QWidget *CModalidadesForm)
    {
        if (CModalidadesForm->objectName().isEmpty())
            CModalidadesForm->setObjectName(QStringLiteral("CModalidadesForm"));
        CModalidadesForm->resize(464, 345);
        CModalidadesForm->setMinimumSize(QSize(464, 0));
        verticalLayout_2 = new QVBoxLayout(CModalidadesForm);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        Modalidades = new QLabel(CModalidadesForm);
        Modalidades->setObjectName(QStringLiteral("Modalidades"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Modalidades->sizePolicy().hasHeightForWidth());
        Modalidades->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        font.setWeight(75);
        Modalidades->setFont(font);

        verticalLayout->addWidget(Modalidades);

        tableWidget = new QTableWidget(CModalidadesForm);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        btn_importMods = new QPushButton(CModalidadesForm);
        btn_importMods->setObjectName(QStringLiteral("btn_importMods"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(2);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_importMods->sizePolicy().hasHeightForWidth());
        btn_importMods->setSizePolicy(sizePolicy1);
        btn_importMods->setMinimumSize(QSize(75, 0));
        btn_importMods->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_2->addWidget(btn_importMods);

        btn_ExportarMods = new QPushButton(CModalidadesForm);
        btn_ExportarMods->setObjectName(QStringLiteral("btn_ExportarMods"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btn_ExportarMods->sizePolicy().hasHeightForWidth());
        btn_ExportarMods->setSizePolicy(sizePolicy2);
        btn_ExportarMods->setMinimumSize(QSize(75, 0));
        btn_ExportarMods->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_2->addWidget(btn_ExportarMods, 0, Qt::AlignLeft);

        btn_remover = new QPushButton(CModalidadesForm);
        btn_remover->setObjectName(QStringLiteral("btn_remover"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btn_remover->sizePolicy().hasHeightForWidth());
        btn_remover->setSizePolicy(sizePolicy3);
        btn_remover->setMinimumSize(QSize(75, 0));
        btn_remover->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_2->addWidget(btn_remover);

        btn_removerTodas = new QPushButton(CModalidadesForm);
        btn_removerTodas->setObjectName(QStringLiteral("btn_removerTodas"));
        sizePolicy1.setHeightForWidth(btn_removerTodas->sizePolicy().hasHeightForWidth());
        btn_removerTodas->setSizePolicy(sizePolicy1);
        btn_removerTodas->setMinimumSize(QSize(100, 0));
        btn_removerTodas->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(btn_removerTodas);


        horizontalLayout->addLayout(horizontalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(CModalidadesForm);
        label->setObjectName(QStringLiteral("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFont(font);

        horizontalLayout_3->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetMinAndMaxSize);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(CModalidadesForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy4);
        label_2->setMaximumSize(QSize(16777215, 25));
        QFont font1;
        font1.setPointSize(11);
        label_2->setFont(font1);

        verticalLayout_3->addWidget(label_2);

        label_3 = new QLabel(CModalidadesForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy5);
        label_3->setMinimumSize(QSize(0, 17));
        label_3->setFont(font1);

        verticalLayout_3->addWidget(label_3);


        horizontalLayout_4->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setSizeConstraint(QLayout::SetMinAndMaxSize);
        te_modName = new QTextEdit(CModalidadesForm);
        te_modName->setObjectName(QStringLiteral("te_modName"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(2);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(te_modName->sizePolicy().hasHeightForWidth());
        te_modName->setSizePolicy(sizePolicy6);
        te_modName->setMinimumSize(QSize(0, 25));
        te_modName->setMaximumSize(QSize(16777215, 25));

        verticalLayout_4->addWidget(te_modName);

        te_modDesc = new QTextEdit(CModalidadesForm);
        te_modDesc->setObjectName(QStringLiteral("te_modDesc"));
        QSizePolicy sizePolicy7(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy7.setHorizontalStretch(1);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(te_modDesc->sizePolicy().hasHeightForWidth());
        te_modDesc->setSizePolicy(sizePolicy7);
        te_modDesc->setMaximumSize(QSize(16777215, 25));

        verticalLayout_4->addWidget(te_modDesc);


        horizontalLayout_4->addLayout(verticalLayout_4);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetMinAndMaxSize);
        btn_adicionarModalidade = new QPushButton(CModalidadesForm);
        btn_adicionarModalidade->setObjectName(QStringLiteral("btn_adicionarModalidade"));
        btn_adicionarModalidade->setEnabled(true);
        btn_adicionarModalidade->setMinimumSize(QSize(50, 0));
        btn_adicionarModalidade->setMaximumSize(QSize(80, 16777215));
        btn_adicionarModalidade->setLayoutDirection(Qt::RightToLeft);

        verticalLayout_5->addWidget(btn_adicionarModalidade, 0, Qt::AlignRight);


        verticalLayout->addLayout(verticalLayout_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        btn_Ok = new QPushButton(CModalidadesForm);
        btn_Ok->setObjectName(QStringLiteral("btn_Ok"));

        horizontalLayout_5->addWidget(btn_Ok);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(CModalidadesForm);

        QMetaObject::connectSlotsByName(CModalidadesForm);
    } // setupUi

    void retranslateUi(QWidget *CModalidadesForm)
    {
        CModalidadesForm->setWindowTitle(QApplication::translate("CModalidadesForm", "Form", Q_NULLPTR));
        Modalidades->setText(QApplication::translate("CModalidadesForm", "Modalidades", Q_NULLPTR));
        btn_importMods->setText(QApplication::translate("CModalidadesForm", "Importar", Q_NULLPTR));
        btn_ExportarMods->setText(QApplication::translate("CModalidadesForm", "Exportar", Q_NULLPTR));
        btn_remover->setText(QApplication::translate("CModalidadesForm", "Remover", Q_NULLPTR));
        btn_removerTodas->setText(QApplication::translate("CModalidadesForm", "Remover todas", Q_NULLPTR));
        label->setText(QApplication::translate("CModalidadesForm", "Adicionar Modalidade", Q_NULLPTR));
        label_2->setText(QApplication::translate("CModalidadesForm", "Nome da Modalidade", Q_NULLPTR));
        label_3->setText(QApplication::translate("CModalidadesForm", "Descri\303\247\303\243o", Q_NULLPTR));
        btn_adicionarModalidade->setText(QApplication::translate("CModalidadesForm", "Adicionar", Q_NULLPTR));
        btn_Ok->setText(QApplication::translate("CModalidadesForm", "Ok", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CModalidadesForm: public Ui_CModalidadesForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMODALIDADESFORM_H
