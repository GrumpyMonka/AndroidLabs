#ifndef AUTH_H
#define AUTH_H

#include <QWidget>
#include <QDebug>

#include <mainwindow.h>

namespace Ui {
class Auth;
}

class Auth : public QWidget
{
    Q_OBJECT

public:
    explicit Auth(QWidget *parent = nullptr);
    ~Auth();

private slots:
    void on_pushButton_clicked();

    void showEvent( QShowEvent* event ) override;
    void hideEvent( QHideEvent* event ) override;

private:
    Ui::Auth *ui;
    MainWindow* window;
};

#endif // AUTH_H
