/************************************
*Author: 	Thomas Dost
*Datum: 	03.12.2015
*Beschr.	Klasse fuer eine Notiz

*Changelog:
            03.12.2015
            Erstellt
            QString mNoteName hinzugefuegt


*TODO:
*           Ausdenken wie Notizdatei aussehen soll
*           Tag-System ausarbeiten
*           Wie werden Notizen in der GUI angezeigt?
*************************************/
#ifndef NOTE_H
#define NOTE_H

#include <QString> //QString

class Note
{
public:
    Note(QString& notename);

private:
    QString mNoteName;          //Name der Notizdatei

};

#endif // NOTE_H
