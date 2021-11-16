#include "language.h"
#include "QList"
#include <iostream>
#include <QDebug>


using namespace std;
QList<QString> *lisPol = new QList<QString>;
QList<QString> *lisEng = new QList<QString>;

Language::Language(QObject *parent)
    : QObject(parent)
{

}

////QString Language::polish (QString mapa,QString plec,QString przod,QString tyl,QString /*lewo,QString prawo,QString tak,QString nie)
//{cout <<"Jestem w slotSomethingpol w Language"<<endl;

//    // QString mapa,plec,przod,tyl,lewo,prawo,tak,nie;




//    lewo= "W Lewo";
//    prawo= "W Prawo";
//    tak= "Tak";
//    nie= "Nie";
//    return plec;

//    //    lisPol->append("Mapa");
//    //    lisPol->append("Plecak");
//    //    lisPol->append("Na przód");
//    //    lisPol->append("W tył");
//    //    lisPol->append("Lewo");
//    //    lisPol->append("Prawo");
//    //    lisPol->append("Tak");
//    //    lisPol->append("Nie");
////}*/


QString Language::wybierzJezyk( QString choseLang)
{
    QString plikPl[9];

    /*QString plikPl [9] = {"Mapa", "Plecak", "Na Przód", "W Tył", "W Lewo", "W Prawo", "Tak", "Nie", "Plik"};*/
    if( choseLang=="pol")
    {
        //        plikPl [9] = {"Mapa", "Plecak", "Na Przód", "W Tył", "W Lewo", "W Prawo", "Tak", "Nie", "Plik"};
        //        plikPl[] = {"Mapa", "Plecak", "Na Przód", "W Tył", "W Lewo", "W Prawo", "Tak", "Nie", "Plik"};


        plikPl[0]=("Mapa");
        plikPl[1]=("Plecak");
        plikPl[2]=("Na Przód");
        plikPl[3]=("W Tył");
        plikPl[4]=("W Lewo");
        plikPl[5]=("W Prawo");
        plikPl[6]=("Tak");
        plikPl[7]=("Nie");
        plikPl[8]=("Plik");
        //        plikPl->push_back("Mapa");
        //        plikPl->push_back("Plecak");
        //        plikPl->push_back("Na Przód");
        //        plikPl->push_back("W Tył");
        //        plikPl->push_back("W Lewo");
        //        plikPl->push_back("W Prawo");
        //        plikPl->push_back("Tak");
        //        plikPl->push_back("Nie");
        //        plikPl->push_back("Plik");
    }
    else if (choseLang =="eng")
    {
        // {plikPl [9] = {"Miuytitya", "Plityicak", "Nytityid", "Wtyiiytył", "Wyitiyiyiwo", "Wyiyitiawo", "Tyiiyk", "Nyiiye", "Plrtruk"};

        plikPl[0]=("Mgfjfgpa");
        plikPl[1]=("Pjfgjak");
        plikPl[2]=("Na gfjgfdjzód");
        plikPl[3]=("Wgfjfgjł");
        plikPl[4]=("Wfgjfjewo");
        plikPl[5]=("Wfgjawo");
        plikPl[6]=("fgjgfj");
        plikPl[7]=("fgjfge");
        plikPl[8]=("Pfgjgfjgik");

    }


    cout << plikPl[1].toStdString()<<endl;
//    for (int i=0;i<=8;i++)

//    {
//        cout <<plikPl[i].toStdString()<<endl;

//    }

//return plikPl[9];
return 0;
}



QString Language::mapa(QString mapa, QString choseLang)
{
    if (choseLang=="pol")
    {
        mapa = "Mapa";
    }
    else if
            (choseLang=="eng")
    {
        mapa = "Map";
    }
    return mapa;
}
QString Language::plecak(QString plecak, QString choseLang)
{
    if (choseLang=="pol")
    {
        plecak = "Plecak";
    }
    else if
            (choseLang=="eng")
    {
        plecak = "Backpack";
    }

    return plecak;
}
QString Language::przod(QString przod, QString choseLang)
{
    if (choseLang=="pol")
    {
        przod = "W Przód";
    }
    else if
            (choseLang=="eng")
    {
        przod = "Forward";
    }
    return przod;
}
QString Language::tyl(QString tyl, QString choseLang)
{  if (choseLang=="pol")
    {
        tyl = "W Tył";
    }
    else if
            (choseLang=="eng")
    {
        tyl = "Back";
    }

    return tyl;
}
//
QString Language::lewo(QString lewo, QString choseLang)
{if (choseLang=="pol")
    {
        lewo = "W Lewo";
    }
    else if
            (choseLang=="eng")
    {
        lewo = "Turn Left";
    }

    return lewo;
}
QString Language::prawo(QString prawo, QString choseLang)
{if (choseLang=="pol")
    {
        prawo = "W prawo";
    }
    else if
            (choseLang=="eng")
    {
        prawo = "Turn Right";
    }

    return prawo;
}
QString Language::tak(QString tak, QString choseLang)
{
    if (choseLang=="pol")
    {
        tak = "tak";
    }
    else if
            (choseLang=="eng")
    {
        tak = "yes";
    } if (choseLang=="pol")

        return tak;
}
QString Language::nie(QString nie, QString choseLang)
{
    if (choseLang=="pol")
    {
        nie = "nie";
    }
    else if
            (choseLang=="eng")
    {
        nie = "No";
    }
    return nie;
}
QString Language::menufile(QString menufile, QString choseLang)
{
    if (choseLang=="pol")
    {
        menufile = "Plik";
    }
    else if
            (choseLang=="eng")
    {
        menufile = "File";
    }
    return menufile;
}
void Language::english ()
{
    lisEng->append("Map");
    lisEng->append("Backpack");
    lisEng->append("Forward");
    lisEng->append("Back");
    lisEng->append("Left");
    lisEng->append("Right");
    lisEng->append("Yes");
    lisEng->append("No");
}