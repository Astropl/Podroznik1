#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DataBase/maindb.h"
#include "Mapa/mapa.h"
#include "Zasoby/language.h"
#include "Zasoby/plecak.h"
#include "Zasoby/addlanguage.h"
#include <iostream>
#include <QAction>
#include <QObject>
#include <direct.h>
//#include <QPainter>
//#include "checkable.h"
#include <QDebug>
#include <QCheckBox>
#include <QtWidgets>


using namespace std;

bool btnForward = false;
bool btnBack = false;
bool btnLeft = false;
bool btnRight = false;

//QAction *launguagePol; //= new QAction(("Polski"), this);
//QAction *launguageEng; //= new QAction(("Angielski"), this);
//QCheckBox *launguagePol = new QCheckBox("Cosisk Pol");
//QCheckBox *launguageEng = new QCheckBox("Cosisk Eng");
QString mapa, plec, przod,tyl,lewo,prawo,tak,nie, menufile;
QString choseLang="";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initForm();
    createFolders();
    dataBase();
    setLanguageLoad ();
    setLanguageFirst();
    setLanguage (choseLang);


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setLanguageFirst()
{MainDb *mainDB = new MainDb(this);
    mainDB->dbLanguageSetSaveFirst(choseLang);
}
void MainWindow::initMenu()
{
    //    QAction *launguagePol = new QAction(("Polski"), this);
    //    QAction *launguageEng = new QAction(("Angielski"), this);
    setWindowTitle("Podróżnik v 1.0");



    QAction *fileNew = new QAction(("&Od nowa"), this);
    QAction *fileWyjscie = new QAction(("&Wyjście"), this);
    launguagePol = new QAction(("Polski"), this);
    launguagePol->setCheckable(true);

    connect(launguagePol, SIGNAL(triggered()), this, SLOT (slot_SomethingCheckedPl()));




    launguageEng = new QAction(("Angielski"), this);
    launguageEng->setCheckable(true);
    connect(launguageEng, SIGNAL(triggered()), this, SLOT (slot_SomethingCheckedEng()));

    addLanguage= new QAction(("Dodaj / Edytuj język"),this);
    connect(addLanguage, SIGNAL(triggered()), this, SLOT (slot_AddLanguage()));


    QAction *infoOProgramie = new QAction(("&O Programie"), this);
    QAction *infoOAutorze = new QAction(("O &Autorze"), this);
    QAction *infoLog = new QAction(("&Log"), this);

    mainfile = menuBar()->addMenu("Plik");
    mainSettings = menuBar()->addMenu("Ustawienia");
    mainSettingsLang = mainSettings->addMenu("Język");
    mainSettings->addSeparator();
    mainSettingsAddLang = mainSettings->addMenu("Opcje");
    mainInfo = menuBar()->addMenu("Informacje");


    mainfile->addAction(fileNew);

    mainfile->addSeparator();
    mainfile->addAction(fileWyjscie);

    mainSettingsLang->addAction(launguagePol);
    mainSettingsLang->addAction(launguageEng);
    mainSettingsAddLang->addAction(addLanguage);

    mainInfo->addAction(infoOProgramie);
    mainInfo->addAction(infoOAutorze);
    mainInfo->addAction(infoLog);



    //connect(settingsOption, &QAction::triggered,this, SLOT (openInfo()));

    //connect(settingsOption, SIGNAL(triggered()), this, SLOT(on_actionOpcje_triggered()));
    connect(infoOProgramie, SIGNAL(triggered()), this, SLOT(on_actionO_programie_triggered()));


    ui->frame_2->setFrameShape(QFrame::Box);
    ui->frame->setFrameShape(QFrame::Box);
    ui->frame_3->setFrameShape(QFrame::Box);
}


void MainWindow::setLanguageLoad ()
{QString choseLange;
    MainDb *mainDB = new MainDb(this);
  choseLange=  mainDB-> dbLanguageSetLoad(choseLange);


  if (choseLange=="")
  {
      choseLange = "pol";
      mainDB->dbLanguageSetSaveFirst(choseLange);
  }
choseLang = choseLange;




}
QString MainWindow::setLanguage (QString choseLang)
{
 MainDb *mainDB = new MainDb(this);

    Language *lang = new Language(this);

    //QString plikPl [9];

    //lang->wybierzJezyk(plikPl,choseLang);
 //plikPl[] = lang->wybierzJezyk(choseLang);
    //for (int i=0;i<=8;i++)

    //
    //qDebug ()<<plikPl[3]<<" \n";

  //


    //
    //Wejsc do DB. Odczytac  po indexie zawerotsoc. Przesłałłc z pol lub eng







    //
//    mapa = plikPl[0];
//    plec = plikPl[1];
//    przod = plikPl[2];
//    tyl = plikPl[3];

//    lewo = plikPl[4];
//    prawo = plikPl[5];
//    tak = plikPl[6];
//    nie = plikPl[7];
    //menufile =plikPl[8];

//    mapa=  lang->mapa(mapa,choseLang);
//    plec= lang->plecak(plec,choseLang);
//    przod= lang->przod(przod,choseLang);
//    tyl = lang->tyl(tyl,choseLang);
//    lewo= lang->lewo(lewo,choseLang);
//    prawo =  lang->prawo(prawo,choseLang);
//    tak = lang->tak(tak,choseLang);
//    nie = lang->nie(nie,choseLang);
//menufile = lang->menufile(menufile, choseLang);



    ui->btnMap->setText(mapa);
    ui->btnBackPack->setText(plec);
    ui->btnGoBack->setText(tyl);
    ui->btnForward->setText(przod);
    ui->btnTurnLeft->setText(lewo);
    ui->btnTurnRight->setText(prawo);
    ui->btnYes->setText(tak);
    ui->btnNo->setText(nie);

    //mainfile->setTitle(menufile);

    if (choseLang=="pol")
    {
        launguagePol->setChecked(true);
        launguageEng->setChecked(false);
    }

    else if (choseLang =="eng")
    {
        launguageEng->setChecked(true);
        launguagePol->setChecked(false);
    }

    // zapisz do bazy
    mainDB->dbLanguageSetSave(choseLang);

    // update zrobic w main db z eng i pol. nadpisac.




    return 0;
}

void MainWindow::slot_SomethingCheckedPl()
{choseLang = "pol";
    cout <<"Jestem w slotSomethingpol"<<endl;

    cout <<"pl"<<endl;
    launguageEng->setChecked(false);//    if (launguagePol->isChecked())
    //
    cout <<"4"<<endl;

    setLanguage(choseLang);



}
void MainWindow::slot_AddLanguage()
{
   cout<< "Dodaj nowy jeżeyk lub zedytuj"<<endl;
   AddLanguage *addLang = new AddLanguage(this);
      addLang->show();

}

void MainWindow::slot_SomethingCheckedEng()
{choseLang = "eng";
    cout <<"Jestem w slotSomethingeng"<<endl;

    cout <<"eng"<<endl;
    launguagePol->setChecked(false);

    cout <<"4"<<endl;
    setLanguage(choseLang);
//mainfile->setWindowTitle("abrakadabra");


}
void MainWindow::initForm()
{//Menu
    initMenu();



    cout<<"Inicjalizacja formy"<<endl;
    //    QPainter painter(this);
    //        painter.drawLine(400,800,400,0);
    //        painter.drawLine(800,400,0,400);
    //        painter.drawRect(50,50,10,10);
    //        painter.fillRect(50,50,10,10,QColor("red"));
    ui->txtEditHistory->setEnabled(false);
    //ui->txtEditHistory->placeholderText("Witsaj Wędrowcze.");
    ui->txtEditHistory->appendPlainText("Witsaj Wędrowcze.");
    ui->txtEditHistory->appendPlainText("Otwoerasz powoli oczy. Słońce razi, Wiatr smaga p policzkach.");
    ui->txtEditHistory->appendPlainText("Podnosisz powoli obolałą głowę do góry.");
    ui->txtEditHistory->appendPlainText("-Chyba wczoraj za mocno popiłem. - Myslisz sobie.");
    ui->txtEditHistory->appendPlainText("\n");
    ui->txtEditHistory->appendPlainText("Przed tobą skały i jedno małe wejście do środka.");
    ui->txtEditHistory->appendPlainText("Za tobą gęste krzaki. - Do tyłu raczej nie pójdę. Muszę przejść przez tą dziurę w skale.");
    ui->txtEditHistory->appendPlainText("Wstajesz i podchodzisz do skały. - Muszę zdecydować.");
    ui->txtEditInteracion->appendPlainText("Możesz iść do przodu lub do tyłu. Co wybierasz?");
    bool btnForward = true;
    bool btnBack = true;
    bool btnLeft = false;
    bool btnRight = false;


    if (btnForward==true)
    {
        ui->btnForward->setEnabled(true);
    }
    else
    {
        ui->btnForward->setEnabled(false);
    }

    if (btnBack==true)
    {
        ui->btnGoBack->setEnabled(true);
    }
    else
    {
        ui->btnGoBack->setEnabled(false);
    }
    if (btnLeft==true)
    {
        ui->btnTurnLeft->setEnabled(true);
    }
    else
    {
        ui->btnTurnLeft->setEnabled(false);
    }
    if (btnRight==true)
    {
        ui->btnTurnRight->setEnabled(true);
    }
    else
    {
        ui->btnTurnRight->setEnabled(false);
    }

}
void MainWindow::dataBase()
{
    cout<<"Baza danych"<<endl;
 MainDb *mainDB = new MainDb(this);
    mainDB->initDb ();
}

void MainWindow::createFolders()
{
    cout<<"createFolders"<<endl;
    _mkdir("C:/Users/pawel/Documents/Cplusplus/Podroznik1/DataBase/mainDB");

}
void MainWindow::on_btnBackPack_clicked()
{
    cout<<"Otwórz plecak"<<endl;
    Plecak *plecak = new Plecak(this);
    plecak->show();
}

void MainWindow::on_btnForward_clicked()
{
    cout<<"Na przód"<<endl;
}

void MainWindow::on_btnTurnLeft_clicked()
{
    cout<<"W lewo"<<endl;
}

void MainWindow::on_btnTurnRight_clicked()
{
    cout<<"W prawo"<<endl;
}

void MainWindow::on_btnGoBack_clicked()
{
    cout<<"W tył"<<endl;
}

void MainWindow::on_btnMap_clicked()
{
    cout<<"mapa"<<endl;
    Mapa *mapa = new Mapa(this);
    mapa->show();

}

void MainWindow::on_btnYes_clicked()
{
    cout<<"Tak"<<endl;
}

void MainWindow::on_btnNo_clicked()
{
    cout<<"Nie"<<endl;
}
