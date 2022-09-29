#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QStandardItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->addItems( QStringList() << "en_US" << "ru_RU" );
    connect( ui->comboBox, SIGNAL( currentIndexChanged( QString ) ),
             this, SLOT( changeLanguage( QString ) ) );

    qtLanguageTranslator.load( QString( "QtLanguage_" ) + QString( "en_US" ) );
    qApp->installTranslator( &qtLanguageTranslator );

    model =  new QStandardItemModel( this );
    ui->listView->setModel( model );
    ui->listView->setEditTriggers( QAbstractItemView::NoEditTriggers );
    qDebug() << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> MainWindow create! <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::showEvent( QShowEvent* event )
{
    qDebug() << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> MainWinow show! <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
}

void MainWindow::hideEvent( QHideEvent* event )
{
    qDebug() << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> MainWinow hide! <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<";
}

void MainWindow::changeEvent( QEvent* event )
{
    if (event->type() == QEvent::LanguageChange)
    {
        ui->retranslateUi(this);    // переведём окно заново
    }
}

void MainWindow::changeLanguage( const QString& language )
{
    qtLanguageTranslator.load( "QtLanguage_" + language, ":/resources/language/" );   // Загружаем перевод
    qApp->installTranslator( &qtLanguageTranslator );        // Устанавливаем перевод в приложение
}

void MainWindow::on_pushButton_clicked()
{
    auto line = ui->lineEdit->text();
    if ( !line.isEmpty() )
    {
        QStandardItem *Item = new QStandardItem();
        Item->setCheckable( true );
        Item->setText( line );
        model->appendRow( Item );
        ui->listView->setModel( model );
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    auto itemList = model->findItems( "*", Qt::MatchWildcard | Qt::MatchRecursive );

    for( auto item : itemList )
    {
        if( Qt::Checked == item->checkState() )
        {
            model->removeRow( item->row() );
        }
    }
}

