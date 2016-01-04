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
    if (!mNoteData->open(QIODevice::ReadWrite | QIODevice::Text))
           return;
    //Textstrean fuer zugriff benutzen
    mNoteText = new QTextStream(mNoteData);

}
