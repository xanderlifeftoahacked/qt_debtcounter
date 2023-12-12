#pragma once

#include <QDialog>

namespace Ui {
class DebtorsAddedForm;
}

class DebtorsAddedForm : public QDialog {
  Q_OBJECT

public:
  explicit DebtorsAddedForm(QWidget *parent = nullptr);
  ~DebtorsAddedForm();

private slots:
  void on_pushButton_clicked();

private:
  Ui::DebtorsAddedForm *ui;
};
