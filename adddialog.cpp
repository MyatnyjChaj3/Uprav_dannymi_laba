#include "adddialog.h"
#include "ui_adddialog.h"
#include <QSqlQuery>
#include <QMessageBox>

AddDialog::AddDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);
    ui->label_3->setScaledContents(true);
    QSqlQuery *queryCombo = new QSqlQuery();
    queryCombo->exec("SELECT name FROM category");
    while (queryCombo->next())
    {
    ui->comboBox->addItem(queryCombo->value(0).toString());
    }

    ui -> dateEdit -> setDate(QDate::currentDate());
}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::on_pushButton_clicked()

{
    QSqlQuery *query = new QSqlQuery();
    query -> prepare("INSERT INTO product (name, catID, ImagePath, prodDate) VALUES (:name, :category, :image, :date)");
    query -> bindValue(":name", ui -> lineEdit -> text());
    query -> bindValue(":category", ui -> comboBox->currentIndex()+1);
    query->bindValue(":image",Img);
    query->bindValue(":date", ui->dateEdit->text());
    QMessageBox*mess =  new QMessageBox();

    if(!query -> exec())
    {
        mess -> setText("Запрос составлен неверно!");
        mess -> show();
    }
}


void AddDialog::on_toolButton_clicked()
{
    Img = QFileDialog::getOpenFileName(0, "Открыть файл", Img, "*.jpg");

    ui -> label_3 -> setPixmap(Img);
}

