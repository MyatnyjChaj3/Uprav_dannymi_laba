#include "modifydialog.h"
#include "ui_modifydialog.h"
#include <QSqlQuery>
#include "mainwindow.h"

ModifyDialog::ModifyDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifyDialog)
{
    ui->setupUi(this);
    ui->label_3->setScaledContents(true);
    QSqlQuery *queryCombo = new QSqlQuery();
    queryCombo->exec("SELECT name FROM category");
    while (queryCombo->next())
    {
    ui->comboBox->addItem(queryCombo->value(0).toString());
    }
}

ModifyDialog::~ModifyDialog()
{
    delete ui;
}


void ModifyDialog::on_pushButton_clicked()
{
    QSqlQuery *query = new QSqlQuery();
    query->prepare("UPDATE product SET name = :name,"
    "catID = :category, ImagePath = :image WHERE ID = :ID");
    query->bindValue(":ID", tempID);
    query->bindValue(":name",ui->lineEdit->text());
    query->bindValue(":category",ui->comboBox->currentIndex()+1);
    query->bindValue(":image",Img);
    if(query->exec())
    {
    close();
    }
}
void ModifyDialog::sendingID(int aa)
{
    tempID = aa;
    QSqlQuery *query = new QSqlQuery();
    query->prepare("SELECT name, cat_ID, ImagePath FROM product"
    "WHERE ID = ?");
    query->bindValue(0,aa);
    if (query->exec())
    {
        query->next();
        ui->lineEdit->setText(query->value(0).toString());
        // ui->lineEdit_2->setText(query->value(1).toString());
        ui->comboBox->setCurrentIndex(query->value(1).toInt()-1);
        Img = query->value(2).toString();
        ui->label_3->setPixmap(Img);
    }
}

