#include "Note.h"

Note::Note(const QString& notepath)
    :mNotePath(notepath)
{
    //Schaut vom Ende des String, nach Links ob ein "/"
    //gefunden wird, und gibt einen Teilstring ab da zurueck.
    //In diesem Fall de Namen der Notiz
    mNoteName = mNotePath.section("/", -1);
    qDebug() <<"NAme der Notiz" << mNoteName;
    //Neue FileStream erstellen
    mNoteData = new QFile(mNotePath);

    //Datei oeffnen
    if (!mNoteData->open(QIODevice::ReadWrite))
           return ;
   //QString um Text zu halten
    mNoteText = new QString(" ");
    qDebug() <<"2";
    //Temporaerer Stream fuers Lesen des Textes
    QTextStream temp(mNoteData);
    //Alles in den String schreiben
    *mNoteText = temp.readAll();
    //Stream schliesen
    mNoteData->close();


    qDebug() <<"1";


}

void Note::reload()
{

         //Alte Daten freigeben
         delete mNoteText;

        //Neue FileStream erstellen
        mNoteData = new QFile(mNotePath);
        //Datei oeffnen
        if (!mNoteData->open(QIODevice::ReadWrite | QIODevice::Text ))
               return;
        //QString um Text zu halten
         mNoteText = new QString(" ");

         //Temporaerer Stream fuers Lesen des Textes
         QTextStream temp(mNoteData);
         //Alles in den String schreiben
         *mNoteText = temp.readAll();
         //Stream schliesen
         mNoteData->close();
}


void Note::save(const QModelIndex &index, const QString& textToSave)
{
    QFile file(mNotePath);
    file.open(QIODevice::WriteOnly);
    QTextStream stream(&file);
    stream << textToSave;
    stream.flush();
    file.close();
    reload();







}

