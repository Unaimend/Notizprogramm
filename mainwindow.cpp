#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


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
        qDebug() << it.mNotePath;
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}



