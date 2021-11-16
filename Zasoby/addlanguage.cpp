#include "addlanguage.h"
#include "ui_addlanguage.h"

AddLanguage::AddLanguage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddLanguage)
{
    ui->setupUi(this);
}

AddLanguage::~AddLanguage()
{
    delete ui;
}

void AddLanguage::on_btnExit_clicked()
{
    //Exit

}
