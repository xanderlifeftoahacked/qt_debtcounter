#pragma once

#include <QString>
#include <QVector>
#include <QWidget>

namespace Ui {
class GetUsersForm;
}

class GetUsersForm : public QWidget {
  Q_OBJECT

public:
  explicit GetUsersForm(QWidget *parent = nullptr);
  ~GetUsersForm();

private:
  Ui::GetUsersForm *ui;
};
