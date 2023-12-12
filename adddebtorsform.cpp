#include "adddebtorsform.h"
#include "ui_adddebtorsform.h"

AddDebtorsForm::AddDebtorsForm(QVector<QVector<QString>> lines, QWidget *parent)
    : QDialog(parent), ui(new Ui::AddDebtorsForm) {
  ui->setupUi(this);

  for (auto &line : lines) {
    for (auto &item : line) {
      QListWidgetItem *listItem = new QListWidgetItem(item, ui->listWidget);
      listItem->setFlags(listItem->flags() | Qt::ItemIsUserCheckable);
      listItem->setCheckState(Qt::Unchecked);
    }
  }

  ui->listWidget->setEnabled(true);
}

AddDebtorsForm::~AddDebtorsForm() { delete ui; }

void AddDebtorsForm::on_confirmButton_clicked() {
  debtors.clear();
  for (int i = 0; i < ui->listWidget->count(); ++i) {
    auto item = ui->listWidget->item(i);
    if (item->checkState() == Qt::Checked) {
      debtors.push_back(item->text());
    }
  }
  this->close();
}
