#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDebug>
#include <QDirIterator>
#include <vector>
#include <QStandardItemModel>
#include <QStringListModel>
#include "Note.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_listView_pressed(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QDirIterator *dirIt;
    std::vector<Note> mNotes;


     QStandardItemModel* mNoteListModel;

};

#endif // MAINWINDOW_H
