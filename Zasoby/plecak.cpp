#include "plecak.h"
#include "ui_plecak.h"
#include "language.h"

Plecak::Plecak(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Plecak)
{
    ui->setupUi(this);
}

Plecak::~Plecak()
{
    delete ui;
}
