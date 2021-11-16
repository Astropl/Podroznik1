#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QPointer>
#include "DataBase/maindb.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
//MainDb *mainDB = new MainDb(this);

private:
    Ui::MainWindow *ui;

public:
    void initForm();
    void createFolders();
    void initMenu();

void setLanguageLoad ();
QString setLanguage (QString choseLang);
void setLanguageFirst();


private slots:

    void on_btnBackPack_clicked();
    void on_btnForward_clicked();
    void on_btnTurnLeft_clicked();
    void on_btnTurnRight_clicked();
    void on_btnGoBack_clicked();
    void dataBase();
    //signals:
    //    void on_btnForward_clicked();
    void slot_SomethingCheckedPl();
    void slot_SomethingCheckedEng();

    void on_btnMap_clicked();
    void on_btnYes_clicked();
    void on_btnNo_clicked();
void slot_AddLanguage();


private:
QMenu *mainfile;
QMenu *mainEdycja;
QMenu *mainInfo;
QMenu *mainSettings;
QMenu *mainSettingsLang;
QMenu *mainSettingsAddLang;
 QAction *launguageEng;
QAction *launguagePol;
QAction *addLanguage;
        //QPointer<QAction> launguagePol = nullptr;
       // QPointer<QAction> launguageEng = nullptr;


};
#endif // MAINWINDOW_H
