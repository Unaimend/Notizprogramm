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
            void reload() hinzugefuegt.
            mNoteText ist jetzt ein String der den Text haelt
            void save() hinzugefuegt
*TODO:
*           Ausdenken wie Notizdatei aussehen soll
*           Tag-System ausarbeiten
*           Wie werden Notizen in der GUI angezeigt?11
*           Wenn Datei im Konstruktor nicht geoeffnet
*           werden kann muss das gehandelt werden.
*           Konstruktoren schreiben
*BUG
*            [1] Allokiert keinen Speicher zur Runtime Note erstellung FIXED
*************************************/
#ifndef NOTE_H
#define NOTE_H

#include <QString> //QString
#include <QtDebug> //qDebug
#include <QFile>   //QFile
#include <QTextStream>  //QTextStream



class Note
{
public:
    Note(const QString& notepath);

public:
    QString mNotePath;          //Pfad der Notizdatei
    QString mNoteName;          //Name der Notizdatei

    QFile* mNoteData;           //Haellt den FilePtr einer Notizdatei
    QString* mNoteText;     //Stream zum interagieren mit dem Text


    /*********************
    *Beschr: Laedt die Notiz neu
    *************************/
    void reload();
    /*********************
    *Beschr: Speichert die Notiz
    *Param1: Index der Notiz die gespeichert werden soll
    *Param2: Text der gespeichert werden soll
    *************************/
    void save(const QModelIndex &index, const QString& textToSave);
};

#endif // NOTE_H
