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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
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
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_connectAuto;
    QComboBox *comboBox_sessions;
    QCheckBox *checkBox_updateIdForAllItems;
    QCheckBox *checkbox_usarModalidadeLogica;
    QCheckBox *checkBox_usarSubpastaComoPrefixo;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QTextEdit *te_magoMediasPath;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpinBox *spin_porta;
    QLabel *label_3;

    void setupUi(QDialog *CSendOptionsForm)
    {
        if (CSendOptionsForm->objectName().isEmpty())
            CSendOptionsForm->setObjectName(QStringLiteral("CSendOptionsForm"));
        CSendOptionsForm->resize(719, 349);
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

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBox_connectAuto = new QCheckBox(CSendOptionsForm);
        checkBox_connectAuto->setObjectName(QStringLiteral("checkBox_connectAuto"));
        checkBox_connectAuto->setMinimumSize(QSize(0, 23));
        checkBox_connectAuto->setMaximumSize(QSize(16777215, 23));
        checkBox_connectAuto->setFont(font);

        horizontalLayout->addWidget(checkBox_connectAuto);

        comboBox_sessions = new QComboBox(CSendOptionsForm);
        comboBox_sessions->setObjectName(QStringLiteral("comboBox_sessions"));

        horizontalLayout->addWidget(comboBox_sessions);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        checkBox_updateIdForAllItems = new QCheckBox(CSendOptionsForm);
        checkBox_updateIdForAllItems->setObjectName(QStringLiteral("checkBox_updateIdForAllItems"));
        checkBox_updateIdForAllItems->setFont(font);

        verticalLayout_2->addWidget(checkBox_updateIdForAllItems);

        checkbox_usarModalidadeLogica = new QCheckBox(CSendOptionsForm);
        checkbox_usarModalidadeLogica->setObjectName(QStringLiteral("checkbox_usarModalidadeLogica"));
        checkbox_usarModalidadeLogica->setFont(font);

        verticalLayout_2->addWidget(checkbox_usarModalidadeLogica);

        checkBox_usarSubpastaComoPrefixo = new QCheckBox(CSendOptionsForm);
        checkBox_usarSubpastaComoPrefixo->setObjectName(QStringLiteral("checkBox_usarSubpastaComoPrefixo"));
        checkBox_usarSubpastaComoPrefixo->setFont(font);

        verticalLayout_2->addWidget(checkBox_usarSubpastaComoPrefixo);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(CSendOptionsForm);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMaximumSize(QSize(16777215, 23));
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        te_magoMediasPath = new QTextEdit(CSendOptionsForm);
        te_magoMediasPath->setObjectName(QStringLiteral("te_magoMediasPath"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(te_magoMediasPath->sizePolicy().hasHeightForWidth());
        te_magoMediasPath->setSizePolicy(sizePolicy1);
        te_magoMediasPath->setMaximumSize(QSize(16777215, 23));
        te_magoMediasPath->setFont(font);

        horizontalLayout_2->addWidget(te_magoMediasPath);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(CSendOptionsForm);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        spin_porta = new QSpinBox(CSendOptionsForm);
        spin_porta->setObjectName(QStringLiteral("spin_porta"));
        spin_porta->setFont(font);
        spin_porta->setMinimum(10000);
        spin_porta->setMaximum(100000);

        horizontalLayout_3->addWidget(spin_porta);

        label_3 = new QLabel(CSendOptionsForm);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(CSendOptionsForm);

        QMetaObject::connectSlotsByName(CSendOptionsForm);
    } // setupUi

    void retranslateUi(QDialog *CSendOptionsForm)
    {
        CSendOptionsForm->setWindowTitle(QApplication::translate("CSendOptionsForm", "Dialog", Q_NULLPTR));
        checkBox_arquivo->setText(QApplication::translate("CSendOptionsForm", "Sempre avisar sobre arquivos existentes no destino", Q_NULLPTR));
        checkBox_id->setText(QApplication::translate("CSendOptionsForm", "Sempre avisar sobre ID existente no destino", Q_NULLPTR));
        checkBox_connectAuto->setText(QApplication::translate("CSendOptionsForm", "Conectar-se automaticante ao iniciar", Q_NULLPTR));
        checkBox_updateIdForAllItems->setText(QApplication::translate("CSendOptionsForm", "Atualizar as informa\303\247\303\265es de um arquivo para todos os destinos simultaneamente.", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        checkbox_usarModalidadeLogica->setToolTip(QApplication::translate("CSendOptionsForm", "<html><head/><body><p>Quando ativado, o arquivo sera enviado para a pasta de midias do Mago. Quando desativado, sera enviado para a subpasta que tem o nome da modalidade do arquivo</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        checkbox_usarModalidadeLogica->setText(QApplication::translate("CSendOptionsForm", "Usar modalidade logica", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        checkBox_usarSubpastaComoPrefixo->setToolTip(QApplication::translate("CSendOptionsForm", "<html><head/><body><p>Quando ativado, adiciona a modalidade no inicio do nome do arquivo; </p><p>exemplo &quot;arquivo.mxf&quot; sera renomeado para &quot;modalidadetal_arquivo.mxf&quot; </p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        checkBox_usarSubpastaComoPrefixo->setText(QApplication::translate("CSendOptionsForm", "Usar modalidade como prefixo no nome do arquivo", Q_NULLPTR));
        label->setText(QApplication::translate("CSendOptionsForm", "Pasta de midias do Mago", Q_NULLPTR));
        te_magoMediasPath->setHtml(QApplication::translate("CSendOptionsForm", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:14pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2';\"><br /></p></body></html>", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("CSendOptionsForm", "<html><head/><body><p>Para enviar v\303\255deos ao Mago, o MagoSend utiliza o servi\303\247o 4SMagoTransferServer.</p><p>A porta definida aqui ser\303\241 utilizada para a comunica\303\247\303\243o com esse servi\303\247o. Caso existam m\303\272ltiplos hosts, as portas subsequentes ser\303\243o alocadas automaticamente a partir desta</p><p>(necessario reiniciar a aplicacao para surtir efeito)</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("CSendOptionsForm", "Porta usada com  o Transfer local", Q_NULLPTR));
        label_3->setText(QApplication::translate("CSendOptionsForm", "10.000 - 50.000", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CSendOptionsForm: public Ui_CSendOptionsForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSENDOPTIONSFORM_H
