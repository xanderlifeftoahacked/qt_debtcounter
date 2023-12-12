#pragma once
#include <QWidget>

namespace Ui {
class ResultForm;
}

class ResultForm : public QWidget {
  Q_OBJECT

public:
  explicit ResultForm(QString, QWidget *parent = nullptr);
  ~ResultForm();

private:
  Ui::ResultForm *ui;
};
