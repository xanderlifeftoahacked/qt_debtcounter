#include "resultform.h"
#include "ui_resultform.h"

ResultForm::ResultForm(QString str, QWidget *parent)
    : QWidget(parent), ui(new Ui::ResultForm) {
  ui->setupUi(this);
  ui->textBrowser->setText(str);
}

ResultForm::~ResultForm() { delete ui; }
