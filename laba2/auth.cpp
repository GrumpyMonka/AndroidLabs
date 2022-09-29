#include "auth.h"
#include "ui_auth.h"

Auth::Auth(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Auth)
{
    ui->setupUi(this);
    qDebug() << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Auth create! <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
}

Auth::~Auth()
{
    delete ui;
}


void Auth::showEvent( QShowEvent* event )
{
    qDebug() << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Auth show! <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
}

void Auth::hideEvent( QHideEvent* event )
{
    qDebug() << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Auth hide! <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
}

void Auth::on_pushButton_clicked()
{
    if ( "admin" == ui->lineEdit->text() && "admin" == ui->lineEdit_2->text() )
    {
        window = new MainWindow( this );
        window->show();
        this->hide();
    }
}

