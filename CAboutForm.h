#ifndef CABOUTFORM_H
#define CABOUTFORM_H

#include <QDialog>

namespace Ui {
class CAboutForm;
}

class CAboutForm : public QDialog
{
    Q_OBJECT

public:
    explicit CAboutForm(QWidget *parent = 0);
    ~CAboutForm();

protected:
    void closeEvent(QCloseEvent *ev);
private slots:
    void on_pushButton_clicked();

private:
    Ui::CAboutForm *ui;

signals:
    void closed();
};

#endif // CABOUTFORM_H
