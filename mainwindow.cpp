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



}






MainWindow::~MainWindow()
{

    delete ui;
}




void MainWindow::on_listView_pressed(const QModelIndex &index)
{
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

}

void MainWindow::on_mButtonSave_clicked()
{
    for(auto& it : mNotes)
    {
        if(it.mNoteName == mNoteListModel->data(TestIndex).toString())
        {
            QFile file(it.mNotePath);
            file.open(QIODevice::WriteOnly);
            QTextStream stream(&file);
            stream << ui->textEdit->toPlainText();
            stream.flush();
            file.close();
            it.reload();
        }
        else
        {

        }
    }


}
