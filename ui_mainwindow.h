/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_8;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_11;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QComboBox *cb_sessions;
    QPushButton *btn_connectSession;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *te_ID;
    QTextEdit *te_titulo;
    QLabel *label_4;
    QComboBox *cb_modalidades;
    QPushButton *btn_atualizarDados;
    QTableWidget *hostsTable;
    QHBoxLayout *horizontalLayout_9;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_6;
    QPushButton *btn_NovoIP;
    QPushButton *btn_ExcluirIP;
    QPushButton *btn_cancelaAtual;
    QHBoxLayout *horizontalLayout_7;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QPushButton *btn_Enviar;
    QPushButton *btn_pausar;
    QPushButton *btn_Remover;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 640);
        MainWindow->setStyleSheet(QLatin1String("QToolTip\n"
"{\n"
"     border: 1px solid black;\n"
"     background-color: #ffa02f;\n"
"     padding: 1px;\n"
"     border-radius: 3px;\n"
"     opacity: 100;\n"
"}\n"
"\n"
"QLabel { background-color: rgba(255, 255, 255, 10); \n"
"    color: #f0f0f0;  /* Light text for contrast */\n"
"    font-size: 12pt;\n"
"    font-weight: bold;  /* Make the text bold to stand out */\n"
"}\n"
"\n"
"\n"
"QWidget\n"
"{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"}\n"
"\n"
"QWidget:item:hover\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #ca0619);\n"
" \n"
"}\n"
"\n"
"QWidget:item:selected\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QMenuBar::item\n"
"{\n"
"    background: transparent;\n"
"}\n"
"\n"
"QMenuBar::item:selected\n"
"{\n"
"    background: transparent;\n"
"    border: 1px solid #ffaa00;\n"
"}\n"
"\n"
"QMenuBar::item:pressed\n"
"{\n"
"    background: #444;\n"
" "
                        "   border: 1px solid #000;\n"
"    background-color: QLinearGradient(\n"
"        x1:0, y1:0,\n"
"        x2:0, y2:1,\n"
"        stop:1 #212121,\n"
"        stop:0.4 #343434/*,\n"
"        stop:0.2 #343434,\n"
"        stop:0.1 #ffaa00*/\n"
"    );\n"
"    margin-bottom:-1px;\n"
"    padding-bottom:1px;\n"
"}\n"
"\n"
"QMenu\n"
"{\n"
"    border: 1px solid #000;\n"
"}\n"
"\n"
"QMenu::item\n"
"{\n"
"    padding: 2px 20px 2px 20px;\n"
"}\n"
"\n"
"QMenu::item:selected\n"
"{\n"
"    color: #000000;\n"
"}\n"
"\n"
"QWidget:disabled\n"
"{\n"
"    color: #404040;\n"
"    background-color: #323232;\n"
"}\n"
"\n"
"QAbstractItemView\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4d4d4d, stop: 0.1 #646464, stop: 1 #5d5d5d);\n"
"}\n"
"\n"
"QWidget:focus\n"
"{\n"
"    /*border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);*/\n"
"}\n"
"\n"
"QLineEdit\n"
"{\n"
"    background-color: #3d3d3d;\n"
"    color: #f0f0f0;\n"
"    border: 1px solid #5a"
                        "5a5a;  /* Subtle border */\n"
"    border-radius: 6px;\n"
"    font-size: 11pt;\n"
"}\n"
"\n"
"QPushButton\n"
"{\n"
"    color: #b1b1b1;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #565656, stop: 0.1 #525252, stop: 0.5 #4e4e4e, stop: 0.9 #4a4a4a, stop: 1 #464646);\n"
"    border-width: 1px;\n"
"    border-color: #1e1e1e;\n"
"    border-style: solid;\n"
"    border-radius: 6;\n"
"    padding: 3px;\n"
"    font-size: 12px;\n"
"    padding-left: 5px;\n"
"    padding-right: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #2d2d2d, stop: 0.1 #2b2b2b, stop: 0.5 #292929, stop: 0.9 #282828, stop: 1 #252525);\n"
"}\n"
"\n"
"QComboBox\n"
"{\n"
"    selection-background-color: #ffaa00;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #565656, stop: 0.1 #525252, stop: 0.5 #4e4e4e, stop: 0.9 #4a4a4a, stop: 1 #464646);\n"
"    border-style: solid;\n"
"    border: 1px solid #1e1e1e;\n"
""
                        "    border-radius: 5;\n"
"}\n"
"\n"
"QComboBox:hover,QPushButton:hover\n"
"{\n"
"    border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"\n"
"QComboBox:on\n"
"{\n"
"    padding-top: 3px;\n"
"    padding-left: 4px;\n"
"    background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #2d2d2d, stop: 0.1 #2b2b2b, stop: 0.5 #292929, stop: 0.9 #282828, stop: 1 #252525);\n"
"    selection-background-color: #ffaa00;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView\n"
"{\n"
"    border: 2px solid darkgray;\n"
"    selection-background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QComboBox::drop-down\n"
"{\n"
"     subcontrol-origin: padding;\n"
"     subcontrol-position: top right;\n"
"     width: 15px;\n"
"\n"
"     border-left-width: 0px;\n"
"     border-left-color: darkgray;\n"
"     border-left-style: solid; /* just a single line */\n"
"     border-top-right-radius: 3px; /* same radius as the QC"
                        "omboBox */\n"
"     border-bottom-right-radius: 3px;\n"
" }\n"
"\n"
"QComboBox::down-arrow\n"
"{\n"
"     image: url(:/down_arrow.png);\n"
"}\n"
"\n"
"QGroupBox {\n"
"    font: bold;\n"
"    border: 1px solid gray;\n"
"    border-radius: 6px;\n"
"    margin-top: 6px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 7px;\n"
"    padding: 0px 5px 0px 5px;\n"
"}\n"
"\n"
"QTextEdit:focus\n"
"{\n"
"    border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"     border: 1px solid #222222;\n"
"     background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0.0 #121212, stop: 0.2 #282828, stop: 1 #484848);\n"
"     height: 12px;\n"
"     margin: 0px 16px 0 16px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 0.5 #d7801a, stop: 1 #ffa02f);\n"
"      min-height: 20px;\n"
"      border-radius: 2px;\n"
"}\n"
""
                        "\n"
"QScrollBar::add-line:horizontal {\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"      width: 14px;\n"
"      subcontrol-position: right;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"      width: 14px;\n"
"     subcontrol-position: left;\n"
"     subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::right-arrow:horizontal, QScrollBar::left-arrow:horizontal\n"
"{\n"
"      border: 1px solid black;\n"
"      width: 1px;\n"
"      height: 1px;\n"
"      background: white;\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal\n"
"{\n"
"      background: none;\n"
"}\n"
"\n"
"QScrollBar:vertical\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0"
                        ", x2: 1, y2: 0, stop: 0.0 #121212, stop: 0.2 #282828, stop: 1 #484848);\n"
"      width: 7px;\n"
"      margin: 16px 0 16px 0;\n"
"      border: 1px solid #222222;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical\n"
"{\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 0.5 #d7801a, stop: 1 #ffa02f);\n"
"      min-height: 20px;\n"
"      border-radius: 2px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical\n"
"{\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"      height: 14px;\n"
"      subcontrol-position: bottom;\n"
"      subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical\n"
"{\n"
"      border: 1px solid #1b1b19;\n"
"      border-radius: 2px;\n"
"      background: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #d7801a, stop: 1 #ffa02f);\n"
"      height: 14px;\n"
"      subcontrol-position: top;\n"
"      subcontrol-origin: marg"
                        "in;\n"
"}\n"
"\n"
"QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical\n"
"{\n"
"      border: 1px solid black;\n"
"      width: 1px;\n"
"      height: 1px;\n"
"      background: white;\n"
"}\n"
"\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical\n"
"{\n"
"      background: none;\n"
"}\n"
"\n"
"QTextEdit\n"
"{\n"
"    background-color:  #242424;\n"
"	border: 0px solid #6c6c6c;\n"
"}\n"
"\n"
"QPlainTextEdit\n"
"{\n"
"    background-color: #242424;\n"
"}\n"
"\n"
"QHeaderView::section\n"
"{\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #616161, stop: 0.5 #505050, stop: 0.6 #434343, stop:1 #656565);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #6c6c6c;\n"
"}\n"
"\n"
"QCheckBox:disabled\n"
"{\n"
"color: #414141;\n"
"}\n"
"\n"
"QDockWidget::title\n"
"{\n"
"    text-align: center;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #323232, stop"
                        ": 0.5 #242424, stop:1 #323232);\n"
"}\n"
"\n"
"QDockWidget::close-button, QDockWidget::float-button\n"
"{\n"
"    text-align: center;\n"
"    spacing: 1px; /* spacing between items in the tool bar */\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #323232, stop: 0.5 #242424, stop:1 #323232);\n"
"}\n"
"\n"
"QDockWidget::close-button:hover, QDockWidget::float-button:hover\n"
"{\n"
"    background: #242424;\n"
"}\n"
"\n"
"QDockWidget::close-button:pressed, QDockWidget::float-button:pressed\n"
"{\n"
"    padding: 1px -1px -1px 1px;\n"
"}\n"
"\n"
"QMainWindow::separator\n"
"{\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #161616, stop: 0.5 #151515, stop: 0.6 #212121, stop:1 #343434);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #4c4c4c;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"}\n"
"\n"
"QMainWindow::separator:hover\n"
"{\n"
"\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #d7801a"
                        ", stop:0.5 #b56c17 stop:1 #ffa02f);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    border: 1px solid #6c6c6c;\n"
"    spacing: 3px; /* spacing between items in the tool bar */\n"
"}\n"
"\n"
"QToolBar::handle\n"
"{\n"
"     spacing: 3px; /* spacing between items in the tool bar */\n"
"     background: url(:/images/handle.png);\n"
"}\n"
"\n"
"QMenu::separator\n"
"{\n"
"    height: 2px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:0 #161616, stop: 0.5 #151515, stop: 0.6 #212121, stop:1 #343434);\n"
"    color: white;\n"
"    padding-left: 4px;\n"
"    margin-left: 10px;\n"
"    margin-right: 5px;\n"
"}\n"
"\n"
"QProgressBar {\n"
"    border: 1px solid #404040;\n"
"    text-align: center;\n"
"    background-color: #3E3E3E;\n"
"}\n"
"\n"
"QProgressBar::chunk {\n"
"    background-color: #0534cc;\n"
"    width: 2px;\n"
"}\n"
"\n"
"\n"
"QTabBar::tab {\n"
"    color: #b1b1b1;\n"
"    border: 1px solid #444;\n"
"    border-bottom-style: none;\n"
"    background-color: #323232;\n"
"   "
                        " padding-left: 10px;\n"
"    padding-right: 10px;\n"
"    padding-top: 3px;\n"
"    padding-bottom: 2px;\n"
"    margin-right: -1px;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 1px solid #444;\n"
"    top: 1px;\n"
"}\n"
"\n"
"QTabBar::tab:last\n"
"{\n"
"    margin-right: 0; /* the last selected tab has nothing to overlap with on the right */\n"
"    border-top-right-radius: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:first:!selected\n"
"{\n"
" margin-left: 0px; /* the last selected tab has nothing to overlap with on the right */\n"
"\n"
"\n"
"    border-top-left-radius: 3px;\n"
"}\n"
"\n"
"QTabBar::tab:!selected\n"
"{\n"
"    color: #b1b1b1;\n"
"    border-bottom-style: solid;\n"
"    margin-top: 3px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #212121, stop:.4 #343434);\n"
"}\n"
"\n"
"QTabBar::tab:selected\n"
"{\n"
"    border-top-left-radius: 3px;\n"
"    border-top-right-radius: 3px;\n"
"    margin-bottom: 0px;\n"
"}\n"
"\n"
"QTabBar::tab:!selected:hover\n"
"{\n"
"    /*border-top: 2"
                        "px solid #ffaa00;\n"
"    padding-bottom: 3px;*/\n"
"    border-top-left-radius: 3px;\n"
"    border-top-right-radius: 3px;\n"
"    background-color: QLinearGradient(x1:0, y1:0, x2:0, y2:1, stop:1 #212121, stop:0.4 #343434, stop:0.2 #343434, stop:0.1 #ffaa00);\n"
"}\n"
"\n"
"QRadioButton::indicator:checked, QRadioButton::indicator:unchecked{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"    border: 1px solid #b1b1b1;\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked\n"
"{\n"
"    background-color: qradialgradient(\n"
"        cx: 0.5, cy: 0.5,\n"
"        fx: 0.5, fy: 0.5,\n"
"        radius: 1.0,\n"
"        stop: 0.25 #ffaa00,\n"
"        stop: 0.3 #323232\n"
"    );\n"
"}\n"
"\n"
"QCheckBox::indicator{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"    border: 1px solid #b1b1b1;\n"
"    width: 9px;\n"
"    height: 9px;\n"
"}\n"
"\n"
"QRadioButton::indicator\n"
"{\n"
"    border-radius: 6px;\n"
"}\n"
"\n"
"QRadioButton::indicator:hover, QCheckBox::ind"
                        "icator:hover\n"
"{\n"
"    border: 1px solid #ffaa00;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked\n"
"{\n"
"    image:url(:/images/checkbox.png);\n"
"}\n"
"\n"
"QCheckBox::indicator:disabled, QRadioButton::indicator:disabled\n"
"{\n"
"    border: 1px solid #444;\n"
"}\n"
"\n"
"QComboBox:hover\n"
"{\n"
"    border: 2px solid QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #ffa02f, stop: 1 #d7801a);\n"
"}\n"
"\n"
"QAbstractSpinBox {\n"
"    padding: 5px;\n"
"    border: 1px solid #76797C;\n"
"    background-color: #232629;\n"
"    color: #eff0f1;\n"
"    border-radius: 2px;\n"
"    min-width: 75px;\n"
"}\n"
"\n"
"QAbstractSpinBox:up-button\n"
"{\n"
"    background-color: transparent;\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: center right;\n"
"}\n"
"\n"
"QAbstractSpinBox:down-button\n"
"{\n"
"    background-color: transparent;\n"
"    subcontrol-origin: border;\n"
"    subcontrol-position: center left;\n"
"}\n"
"\n"
"QAbstractSpinBox::up-arrow,QAbstractSpinBox::up-arrow:disabled,QAbstra"
                        "ctSpinBox::up-arrow:off {\n"
"    image: url(:/images/up_arrow_disabled.png);\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
"QAbstractSpinBox::up-arrow:hover\n"
"{\n"
"    image: url(:/images/up_arrow.png);\n"
"}\n"
"QAbstractSpinBox::down-arrow,QAbstractSpinBox::down-arrow:disabled,QAbstractSpinBox::down-arrow:off\n"
"{\n"
"    image: url(:/images/down_arrow_disabled.png);\n"
"    width: 10px;\n"
"    height: 10px;\n"
"}\n"
"QAbstractSpinBox::down-arrow:hover\n"
"{\n"
"    image: url(:/images/down_arrow.png);\n"
"}\n"
"\n"
"QTableWidget {\n"
"    background-color: #3d3d3d;  /* Dark gray background */\n"
"    color: #f0f0f0;  /* Light text color for readability */\n"
"    gridline-color: #5a5a5a;  /* Softer grid line color */\n"
"    selection-background-color: #ff9100;  /* Orange for selected row */\n"
"    selection-color: #000000;  /* Black text when selected */\n"
"    border: 1px solid #2a2a2a;  /* Border to match overall theme */\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #2a2a"
                        "2a;  /* Darker header background */\n"
"    color: #ffffff;  /* White text in headers */\n"
"    padding: 4px;\n"
"    border: 1px solid #4d4d4d;  /* Subtle border around headers */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QTableCornerButton::section {\n"
"    background-color: #2a2a2a;  /* Corner button matching header */\n"
"    border: 1px solid #4d4d4d; \n"
"}\n"
"\n"
"QHeaderView\n"
"{\n"
"    border-radius: 1px;\n"
"}\n"
"\n"
"QTableWidget::item:pressed, QListView::item:pressed, QTreeView::item:pressed  {\n"
"    background: #334E5E;\n"
"    color: #eff0f1;\n"
"	border: 0px solid #76797C;\n"
"}\n"
"\n"
"QTableWidget::item:selected:active, QTreeView::item:selected:active, QListView::item:selected:active  {\n"
"    background: #334E5E;\n"
"    color: #eff0f1;\n"
" 	border: 0px solid #76797C;\n"
"}\n"
"\n"
"QTableWidget::item::selected {\n"
"background-color: #transparent;\n"
"border: 0px solid #76797C;\n"
"}\n"
"\n"
"QTableWidget::row::selected {\n"
"background-color: #334E5E;\n"
"border: 0px solid #76797"
                        "C;\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"    background-color: transparent;\n"
"}  \n"
"\n"
"\n"
" /* style the sort indicator */\n"
"QHeaderView::down-arrow {\n"
"    image: url(:/qss_icons/rc/down_arrow.png);\n"
"}\n"
"\n"
"QHeaderView::up-arrow {\n"
"    image: url(:/qss_icons/rc/up_arrow.png);\n"
"}\n"
"\n"
"\n"
"QTableCornerButton::section {\n"
"    background-color: #31363b;\n"
"    border: 1px transparent #76797C;\n"
"    border-radius: 0px;\n"
"}\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        groupBox_3->setMaximumSize(QSize(16777215, 320));
        groupBox_3->setStyleSheet(QLatin1String("QGroupBox {\n"
" border: 1px solid gray;\n"
"}"));
        horizontalLayout_11 = new QHBoxLayout(groupBox_3);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        widget = new QWidget(groupBox_3);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        widget->setMaximumSize(QSize(16777215, 300));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);

        horizontalLayout->addWidget(label_5);

        cb_sessions = new QComboBox(widget);
        cb_sessions->setObjectName(QStringLiteral("cb_sessions"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(cb_sessions->sizePolicy().hasHeightForWidth());
        cb_sessions->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(cb_sessions);

        btn_connectSession = new QPushButton(widget);
        btn_connectSession->setObjectName(QStringLiteral("btn_connectSession"));

        horizontalLayout->addWidget(btn_connectSession);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));

        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetNoConstraint);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_6->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_6->addWidget(label_2);


        horizontalLayout_3->addLayout(horizontalLayout_6);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        te_ID = new QTextEdit(widget);
        te_ID->setObjectName(QStringLiteral("te_ID"));
        te_ID->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_4->addWidget(te_ID);

        te_titulo = new QTextEdit(widget);
        te_titulo->setObjectName(QStringLiteral("te_titulo"));
        te_titulo->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_4->addWidget(te_titulo);


        verticalLayout->addLayout(horizontalLayout_4);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout->addWidget(label_4);

        cb_modalidades = new QComboBox(widget);
        cb_modalidades->setObjectName(QStringLiteral("cb_modalidades"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(cb_modalidades->sizePolicy().hasHeightForWidth());
        cb_modalidades->setSizePolicy(sizePolicy4);
        cb_modalidades->setMinimumSize(QSize(200, 0));

        verticalLayout->addWidget(cb_modalidades, 0, Qt::AlignLeft);

        btn_atualizarDados = new QPushButton(widget);
        btn_atualizarDados->setObjectName(QStringLiteral("btn_atualizarDados"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(btn_atualizarDados->sizePolicy().hasHeightForWidth());
        btn_atualizarDados->setSizePolicy(sizePolicy5);
        btn_atualizarDados->setMaximumSize(QSize(200, 30));
        btn_atualizarDados->setStyleSheet(QLatin1String("QPushButton {\n"
"    qproperty-icon: url(:/images/refresh_yellow.png); /* Use icon instead of image */\n"
"    qproperty-iconSize: 16px 16px; /* Size of the icon */\n"
"    padding-left: 10px; /* Adjust padding to position the image */\n"
"    padding-right: 10px; /* Adjust padding to position the image */\n"
"    padding-top: 5px; /* Adjust vertical position */\n"
"    padding-bottom: 5px; /* Adjust vertical position */\n"
"}"));

        verticalLayout->addWidget(btn_atualizarDados);


        horizontalLayout_2->addLayout(verticalLayout);


        horizontalLayout_11->addWidget(widget);

        hostsTable = new QTableWidget(groupBox_3);
        hostsTable->setObjectName(QStringLiteral("hostsTable"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(1);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(hostsTable->sizePolicy().hasHeightForWidth());
        hostsTable->setSizePolicy(sizePolicy6);
        hostsTable->setMinimumSize(QSize(200, 250));
        hostsTable->setMaximumSize(QSize(16777215, 300));
        hostsTable->setStyleSheet(QLatin1String("  QTableWidget {\n"
"        background-color: #3E3E3E;\n"
"        border: 1px solid gray;\n"
"        margin: 5px; /* Adding margin for spacing */\n"
"    }"));

        horizontalLayout_11->addWidget(hostsTable);


        horizontalLayout_8->addWidget(groupBox_3);


        horizontalLayout_10->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy7);
        groupBox_2->setMinimumSize(QSize(0, 147));
        groupBox_2->setMaximumSize(QSize(16777215, 16777215));
        groupBox_2->setStyleSheet(QLatin1String("QGroupBox {\n"
"    font: bold;\n"
"    border: 1px solid gray;\n"
"    border-radius: 6px;\n"
"    margin-top: 20px;\n"
"	margin-right: 15px;\n"
"	margin-left: 6px;\n"
"	width: 148px;\n"
"}"));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 122, 107));
        verticalLayout_6 = new QVBoxLayout(layoutWidget);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        btn_NovoIP = new QPushButton(layoutWidget);
        btn_NovoIP->setObjectName(QStringLiteral("btn_NovoIP"));
        QSizePolicy sizePolicy8(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(btn_NovoIP->sizePolicy().hasHeightForWidth());
        btn_NovoIP->setSizePolicy(sizePolicy8);
        btn_NovoIP->setMinimumSize(QSize(120, 30));
        btn_NovoIP->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_6->addWidget(btn_NovoIP);

        btn_ExcluirIP = new QPushButton(layoutWidget);
        btn_ExcluirIP->setObjectName(QStringLiteral("btn_ExcluirIP"));
        sizePolicy8.setHeightForWidth(btn_ExcluirIP->sizePolicy().hasHeightForWidth());
        btn_ExcluirIP->setSizePolicy(sizePolicy8);
        btn_ExcluirIP->setMinimumSize(QSize(120, 30));
        btn_ExcluirIP->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_6->addWidget(btn_ExcluirIP);

        btn_cancelaAtual = new QPushButton(layoutWidget);
        btn_cancelaAtual->setObjectName(QStringLiteral("btn_cancelaAtual"));
        sizePolicy8.setHeightForWidth(btn_cancelaAtual->sizePolicy().hasHeightForWidth());
        btn_cancelaAtual->setSizePolicy(sizePolicy8);
        btn_cancelaAtual->setMinimumSize(QSize(120, 30));
        btn_cancelaAtual->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_6->addWidget(btn_cancelaAtual);


        horizontalLayout_9->addWidget(groupBox_2, 0, Qt::AlignTop);


        horizontalLayout_10->addLayout(horizontalLayout_9);


        verticalLayout_2->addLayout(horizontalLayout_10);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QSizePolicy sizePolicy9(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy9.setHorizontalStretch(2);
        sizePolicy9.setVerticalStretch(2);
        sizePolicy9.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy9);
        tableWidget->setStyleSheet(QLatin1String("  QTableWidget {\n"
"        background-color: #3E3E3E;\n"
"        border: 1px solid gray;\n"
"    }"));

        horizontalLayout_7->addWidget(tableWidget);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(0, 139));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        groupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
" border: 1px solid gray;\n"
"    font: bold;\n"
"    border-radius: 6px;\n"
"    margin-top: 10px;\n"
"	margin-right: 15px;\n"
"	margin-left: 6px;\n"
"	width: 148px;\n"
"}"));
        btn_Enviar = new QPushButton(groupBox);
        btn_Enviar->setObjectName(QStringLiteral("btn_Enviar"));
        btn_Enviar->setGeometry(QRect(20, 20, 120, 30));
        sizePolicy8.setHeightForWidth(btn_Enviar->sizePolicy().hasHeightForWidth());
        btn_Enviar->setSizePolicy(sizePolicy8);
        btn_Enviar->setMinimumSize(QSize(120, 30));
        btn_Enviar->setMaximumSize(QSize(16777215, 16777212));
        btn_pausar = new QPushButton(groupBox);
        btn_pausar->setObjectName(QStringLiteral("btn_pausar"));
        btn_pausar->setGeometry(QRect(20, 60, 120, 30));
        sizePolicy8.setHeightForWidth(btn_pausar->sizePolicy().hasHeightForWidth());
        btn_pausar->setSizePolicy(sizePolicy8);
        btn_pausar->setMinimumSize(QSize(120, 0));
        btn_pausar->setMaximumSize(QSize(16777215, 16777212));
        btn_Remover = new QPushButton(groupBox);
        btn_Remover->setObjectName(QStringLiteral("btn_Remover"));
        btn_Remover->setGeometry(QRect(20, 100, 120, 30));
        sizePolicy8.setHeightForWidth(btn_Remover->sizePolicy().hasHeightForWidth());
        btn_Remover->setSizePolicy(sizePolicy8);
        btn_Remover->setMinimumSize(QSize(120, 0));
        btn_Remover->setMaximumSize(QSize(16777215, 16777212));

        horizontalLayout_7->addWidget(groupBox, 0, Qt::AlignRight|Qt::AlignTop);


        verticalLayout_2->addLayout(horizontalLayout_7);


        verticalLayout_3->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 22));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        label_5->setText(QApplication::translate("MainWindow", "Sess\303\243o", Q_NULLPTR));
        btn_connectSession->setText(QApplication::translate("MainWindow", "Conectar", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "N\303\272mero", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "T\303\255tulo", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Modalidade", Q_NULLPTR));
        btn_atualizarDados->setText(QApplication::translate("MainWindow", "Atualizar Dados", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        btn_NovoIP->setText(QApplication::translate("MainWindow", "Novo", Q_NULLPTR));
        btn_ExcluirIP->setText(QApplication::translate("MainWindow", "Excluir", Q_NULLPTR));
        btn_cancelaAtual->setText(QApplication::translate("MainWindow", "Cancela atual", Q_NULLPTR));
        groupBox->setTitle(QString());
        btn_Enviar->setText(QApplication::translate("MainWindow", "Enviar todos", Q_NULLPTR));
        btn_pausar->setText(QApplication::translate("MainWindow", "Pausar todos", Q_NULLPTR));
        btn_Remover->setText(QApplication::translate("MainWindow", "Remover", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
