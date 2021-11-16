#ifndef LANGUAGE_H
#define LANGUAGE_H
#include <QObject>

class Language: public QObject
{
public:
    explicit Language(QObject *parent = nullptr);


    Language();
//    QString polish  (QString mapa,QString plec,QString przod,QString tyl,QString lewo,QString prawo,QString tak,QString nie);
    void english ();



    QString mapa(QString mapa, QString choseLang);
    QString plecak(QString plecak, QString choseLang);
    QString przod(QString przod, QString choseLang);

    QString tyl(QString tyl, QString choseLang);

    QString lewo(QString lewo, QString choseLang);

    QString prawo(QString prawo, QString choseLang);

    QString tak(QString tak, QString choseLang);

    QString nie(QString nie, QString choseLang);
QString menufile(QString menufile, QString choseLang);

QString wybierzJezyk( QString choseLang);


};

#endif // LANGUAGE_H
