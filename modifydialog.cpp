#include "modifydialog.h"
#include "ui_modifydialog.h"
#include <QSqlQuery>
#include "mainwindow.h"

ModifyDialog::ModifyDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyDialog)
{
    ui->setupUi(this);
}

ModifyDialog::~ModifyDialog()
{
    delete ui;
}


void ModifyDialog::on_pushButton_clicked()
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("UPDATE product SET name = :name,"
    "category = :category, WHERE ID = :ID");
    query->bindValue(":ID", tempID);
    query->bindValue(":name",ui->lineEdit->text());
    query->bindValue(":category",ui->lineEdit_2->text());
    if(query->exec())
    {
    close();
    }
}
void ModifyDialog::sendingID(int aa)
{
    tempID = aa;
    QSqlQuery *query = new QSqlQuery();
    query->prepare("SELECT name, category FROM product"
    "WHERE ID = ?");
    query->bindValue(0,aa);
    if (query->exec())
    {
        query->next();
        ui->lineEdit->setText(query->value(0).toString());
        ui->lineEdit_2->setText(query->value(1).toString());
    }
}

