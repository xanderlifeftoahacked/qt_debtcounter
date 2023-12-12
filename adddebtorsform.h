#pragma once

#include <QDialog>
#include <QListWidget>

namespace Ui {
class AddDebtorsForm;
}

class AddDebtorsForm : public QDialog {
  Q_OBJECT

public:
  explicit AddDebtorsForm(QVector<QVector<QString>>, QWidget *parent = nullptr);
  QVector<QString> debtors;
  ~AddDebtorsForm();

private slots:
  void on_confirmButton_clicked();

private:
  Ui::AddDebtorsForm *ui;
};
