#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void changeEvent( QEvent* ) override;

public slots:
    void changeLanguage( const QString& );

    void showEvent( QShowEvent* event ) override;
    void hideEvent( QHideEvent* event ) override;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel* model;
    QTranslator qtLanguageTranslator;
};
#endif // MAINWINDOW_H
