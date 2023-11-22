#include "adddialog.h"
#include "ui_adddialog.h"
#include <QSqlQuery>
#include <QMessageBox>

AddDialog::AddDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::on_pushButton_clicked()

{
    QSqlQuery *query = new QSqlQuery();
    query -> prepare("INSERT INTO product (name, cat_ID) VALUES (:name, :cat_ID)");
    query -> bindValue(":name", ui -> lineEdit -> text());
    query -> bindValue(":cat_ID", ui -> lineEdit_2 -> text());
    QMessageBox*mess =  new QMessageBox();

    if(!query -> exec())
    {
        mess -> setText("Запрос составлен неверно!");
        mess -> show();
    }
}

