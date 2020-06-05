#ifndef RANKWINDOW_H
#define RANKWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QTableView>

namespace Ui {
class RankWindow;
}

class RankWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RankWindow(QWidget *parent = nullptr);
    ~RankWindow();
    QSqlTableModel *model;

private:
    Ui::RankWindow *ui;
private slots:
    void on_pushButton_clicked();
signals:
    void sendsignal();
};

#endif // RANKWINDOW_H
