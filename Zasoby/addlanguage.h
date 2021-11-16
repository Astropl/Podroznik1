#ifndef ADDLANGUAGE_H
#define ADDLANGUAGE_H

#include <QMainWindow>

namespace Ui {
class AddLanguage;
}

class AddLanguage : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddLanguage(QWidget *parent = nullptr);
    ~AddLanguage();

private slots:
    void on_btnExit_clicked();

private:
    Ui::AddLanguage *ui;
};

#endif // ADDLANGUAGE_H
