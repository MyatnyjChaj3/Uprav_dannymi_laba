#ifndef PRINTDIALOG_H
#define PRINTDIALOG_H
#include <QDialog>
#include <QSqlQuery> //создание запросов
#include <QFileDialog> //диалоговое окно работы с файлами
#include <QFile> //работа с файлами
#include <QTextStream> //организация текстовых потоков
#include <QAxObject>

#include <QWidget>

namespace Ui {
class PrintDialog;
}

class PrintDialog : public QWidget
{
    Q_OBJECT

public:
    explicit PrintDialog(QWidget *parent = nullptr);
    ~PrintDialog();

private slots:
    void on_pushButton_clicked();

    void on_toolButton_clicked();

private:
    Ui::PrintDialog *ui;
};

#endif // PRINTDIALOG_H
