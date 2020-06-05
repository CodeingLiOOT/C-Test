#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QMainWindow>

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = nullptr);
    ~RegisterWindow();

private:
    Ui::RegisterWindow *ui;
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
signals:
    void sendsignal();
};

#endif // REGISTERWINDOW_H
