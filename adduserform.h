#pragma once

#include "ui_adduserform.h"
#include "utils.h"

#include <QWidget>

namespace Ui {
class AddUserForm;
}

class AddUserForm : public QWidget {
  Q_OBJECT

public:
  explicit AddUserForm(QWidget *parent = nullptr);
  ~AddUserForm();
  Ui::AddUserForm *ui;

private slots:
  void on_confirmButton_clicked();
};
