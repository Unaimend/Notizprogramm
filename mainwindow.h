#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtDebug>
#include <QDirIterator>
#include <vector>
#include <QStandardItemModel>
#include <QStringListModel>
#include "Note.h"
#include <QTextDocumentWriter>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
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

    void on_mButtonSave_clicked();

    void on_textEdit_textChanged();

    void on_mButtonNew_clicked();

private:
    Ui::MainWindow *ui;
    QDirIterator *dirIt;
    std::vector<Note> mNotes;

    QModelIndex TestIndex;
     QStandardItemModel* mNoteListModel;

};

#endif // MAINWINDOW_H
