#include "debtorsaddedform.h"
#include "ui_debtorsaddedform.h"

DebtorsAddedForm::DebtorsAddedForm(QWidget *parent)
    : QDialog(parent), ui(new Ui::DebtorsAddedForm) {
  ui->setupUi(this);
}

DebtorsAddedForm::~DebtorsAddedForm() { delete ui; }

void DebtorsAddedForm::on_pushButton_clicked() { this->close(); }
