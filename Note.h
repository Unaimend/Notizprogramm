/************************************
*Author: 	Thomas Dost
*Datum: 	03.12.2015
*Beschr.	Klasse fuer eine Notiz

*Changelog:
            03.12.2015
            Erstellt
            QString mNoteName hinzugefuegt
            04.12.2015
            mNoteName zu mNotePath geaendert
            und neue Variable Qstring mNoteName hinzugefuegt
            QtDebug included
            mNoteName wird initialisiert

*TODO:
*           Ausdenken wie Notizdatei aussehen soll
*           Tag-System ausarbeiten
*           Wie werden Notizen in der GUI angezeigt?
*************************************/
#ifndef NOTE_H
#define NOTE_H

#include <QString> //QString
#include <QtDebug> //qDebug

class Note
{
public:
    Note(const QString& notename);

public:
    QString mNotePath;          //Pfad der Notizdatei
    QString mNoteName;          //Name der Notizdatei
};

#endif // NOTE_H
