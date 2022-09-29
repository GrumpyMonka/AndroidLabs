#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->label->setText ( QString::number ( ++orda ) );
    if ( 0 < opacity )
        this->setStyleSheet ( "background: rgba( 204, 204, 204, 0." + QString::number ( --opacity ) + ");" );
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->label_2->setText ( QString::number ( ++alince ) );
    if ( 9 > opacity )
        this->setStyleSheet ( "background: rgba( 204, 204, 204, 0." + QString::number ( ++opacity ) + ");" );
}

