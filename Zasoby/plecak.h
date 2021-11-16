#ifndef PLECAK_H
#define PLECAK_H

#include <QMainWindow>

namespace Ui {
class Plecak;
}

class Plecak : public QMainWindow
{
    Q_OBJECT

public:
    explicit Plecak(QWidget *parent = nullptr);
    ~Plecak();

private:
    Ui::Plecak *ui;
};

#endif // PLECAK_H
