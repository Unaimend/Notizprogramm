#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->listView->setViewMode(QListView::ListMode);


    mNoteListModel = new QStandardItemModel();
    ui->listView->setModel(mNoteListModel);



    if(!QDir("notes").exists())
    {
        QDir().mkdir("notes");
    }

    dirIt = new QDirIterator(QDir::currentPath() + "/notes", QDirIterator::Subdirectories);

    while (dirIt->hasNext())
    {
        dirIt->next();
        if (QFileInfo(dirIt->filePath()).isFile())
        {
            mNotes.push_back(Note(dirIt->filePath()));
        }
    }
    for(auto& it : mNotes)
    {
        QStandardItem* Items = new QStandardItem(it.mNoteName);

        mNoteListModel->appendRow(Items);
        qDebug() << it.mNotePath;
    }

    if(!mNotes.empty())
    {
       ui->textEdit->setText(*(mNotes[0].mNoteText));
    }




}






MainWindow::~MainWindow()
{

    delete ui;
}




void MainWindow::on_listView_pressed(const QModelIndex &index)
{
     qDebug() << "KLICKED";
    TestIndex = index;
    for(auto& it : mNotes)
    {
        if(it.mNoteName == mNoteListModel->data(index).toString())
        {
            ui->textEdit->setText(*(it.mNoteText));
        }
        else
        {

        }
    }
qDebug() << "ENDED CLICKED";
}

void MainWindow::on_mButtonSave_clicked()
{

    for(auto& it : mNotes)
    {
        if(it.mNoteName == mNoteListModel->data(TestIndex).toString())
        {

            it.save(TestIndex,ui->textEdit->toPlainText());

        }
        else
        {

        }
    }


}

//SUPER LANGSAME LOESUNG ABER WAS SOLLS
void MainWindow::on_textEdit_textChanged()
{
    for(auto& it : mNotes)
    {
        if(it.mNoteName == mNoteListModel->data(TestIndex).toString())
        {
            it.save(TestIndex,ui->textEdit->toPlainText());

        }
        else
        {

        }
    }

}

void MainWindow::on_mButtonNew_clicked()
{
    bool ok;
    QString filename = QInputDialog::getText(this, tr("Neue Notiz"),
                                                              tr("Notizname?"), QLineEdit::Normal,
                                                              "", &ok);
    qDebug() << "/notes/" + filename;
    if (ok && !filename.isEmpty())
    {
         QFile * testFile = new QFile("notes/" + filename);
         if( ! testFile->open(QIODevice::WriteOnly) )
         {
           QMessageBox::warning(this, "", "Unable to open: " + filename , "OK");
         }
          delete testFile;
     }
     else if(ok && filename.isEmpty())
     {
         QMessageBox::warning(this, "", "Kein Dateiname angegeben" + filename , "OK");
     }
     else
     {

     }
    Note temp(QDir::currentPath() + "/notes/" + filename);


    mNotes.push_back(temp);

    QStandardItem* Items = new QStandardItem(temp.mNoteName);


    mNoteListModel->appendRow(Items);


}
