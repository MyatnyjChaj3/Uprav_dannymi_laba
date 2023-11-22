#ifndef MODIFYDIALOG_H
#define MODIFYDIALOG_H

#include <QWidget>

namespace Ui {
class ModifyDialog;
}

class ModifyDialog : public QWidget
{
    Q_OBJECT

public:
    explicit ModifyDialog(QWidget *parent = nullptr);
    ~ModifyDialog();

    int tempID;
    QString Img;

private slots:
    void on_pushButton_clicked();
    void sendingID(int);

private:
    Ui::ModifyDialog *ui;
};

#endif // MODIFYDIALOG_H
