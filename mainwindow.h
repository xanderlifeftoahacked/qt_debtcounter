#pragma once

#include "adddebtorsform.h"
#include "adduserform.h"
#include "debtorsaddedform.h"
#include "getusersform.h"
#include "resultform.h"
#include "ui_adduserform.h"
#include "ui_mainwindow.h"
#include "utils.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  void updateCbox();

private slots:

  void on_getUsersListButton_clicked();

  void on_addUserButton_clicked();

  void on_chooseDebtorsButton_clicked();

  void on_confirmButton_clicked();

  void on_moneySpentLineEdit_textChanged(const QString &arg1);

  void on_purposeLineEdit_textChanged(const QString &arg1);

  void on_getResultButton_clicked();

private:
  Ui::MainWindow *ui;
  AddDebtorsForm *debtorsform;
};
