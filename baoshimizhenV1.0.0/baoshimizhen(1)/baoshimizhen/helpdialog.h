﻿#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>

namespace Ui {
class HelpDialog;
}

class HelpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HelpDialog(QWidget *parent = nullptr);
    ~HelpDialog();


private:
    Ui::HelpDialog *ui;
public slots:
    void setText(int);
};

#endif // HELPDIALOG_H
