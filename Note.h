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
            QFile* mNoteData hinzugefuegt
            QTextStream* mNoteText hinzugefuegt,
            um mit dem Notiztext zu interagieren

*TODO:
*           Ausdenken wie Notizdatei aussehen soll
*           Tag-System ausarbeiten
*           Wie werden Notizen in der GUI angezeigt?
*************************************/
#ifndef NOTE_H
#define NOTE_H

#include <QString> //QString
#include <QtDebug> //qDebug
#include <QFile>   //QFile
#include <QTextStream>  //QTextStream

#include <QStandardItem>

class Note
{
public:
    Note(const QString& notepath);

public:
    QString mNotePath;          //Pfad der Notizdatei
    QString mNoteName;          //Name der Notizdatei

    QFile* mNoteData;           //Haellt den FilePtr einer Notizdatei
    QTextStream* mNoteText;     //Stream zum interagieren mit dem Text
};

#endif // NOTE_H
