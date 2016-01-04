#include "Note.h"

Note::Note(const QString& notepath)
    :mNotePath(notepath)
{
    //Schaut vom Ende des String, nach Links ob ein "/"
    //gefunden wird, und gibt einen Teilstring ab da zurueck.
    //In diesem Fall de Namen der Notiz
    mNoteName = mNotePath.section("/", -1);

    //Neue FileStream erstellen
    mNoteData = new QFile(mNotePath);
    //Datei oeffnen
    if (!mNoteData->open(QIODevice::ReadWrite | QIODevice::Text ))
           return;
   //QString um Text zu halten
    mNoteText = new QString();

    //Temporaerer Stream fuers Lesen des Textes
    QTextStream temp(mNoteData);
    //Alles in den String schreiben
    *mNoteText = temp.readAll();
    //Stream schliesen
    mNoteData->close();


}

void Note::reload()
{
        //Neue FileStream erstellen
        mNoteData = new QFile(mNotePath);
        //Datei oeffnen
        if (!mNoteData->open(QIODevice::ReadWrite | QIODevice::Text ))
               return;
        //QString um Text zu halten
         mNoteText = new QString();

         //Temporaerer Stream fuers Lesen des Textes
         QTextStream temp(mNoteData);
         //Alles in den String schreiben
         *mNoteText = temp.readAll();
         //Stream schliesen
         mNoteData->close();
}
