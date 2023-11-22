#include "connectiondialog.h"
#include "ui_connectiondialog.h"

ConnectionDialog::ConnectionDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConnectionDialog)
{
    ui->setupUi(this);
}

ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}

void ConnectionDialog::on_pushButton_clicked()
{
    // в след строке указывается используемый драйвер
    db = QSqlDatabase::addDatabase("QODBC");

    // далее формируется строка подключения
    db.setDatabaseName("DRIVER={SQL Server}; SERVER="
                       + ui -> lineEdit -> text() + ";DATABASE=" + ui -> lineEdit_2 -> text()+";");

    // указывается логин и пароль
    db.setUserName(ui -> lineEdit_3 -> text());
    db.setPassword(ui -> lineEdit_4 -> text());

    // создаем объект для вывода сообщения
    msg = new QMessageBox();


    if (db.open()) // попытка подключения к бд
    {
        msg -> setText("Соединение установлено");
    }
    else
    {
        msg -> setText("Соединение не установлено");

    }
    msg -> show();

  QSqlDatabase::removeDatabase("QODBC"); //функция разрыва текущего соединения с бд
}

