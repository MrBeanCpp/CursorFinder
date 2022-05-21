#include "settingdialog.h"
#include "ui_settingdialog.h"
#include <QAbstractButton>
#include <QtDebug>
SettingDialog::SettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingDialog)
{
    ui->setupUi(this);
    setFixedSize(size());

    connect(ui->buttonBox, &QDialogButtonBox::clicked, [=](QAbstractButton* button) {
        if (button->text() == "Apply")
            emit apply(ui->spin_gap->value(), ui->spin_dist->value());
    });
}

void SettingDialog::setValue(int gap, int dist)
{
    ui->spin_gap->setValue(gap);
    ui->spin_dist->setValue(dist);
}

SettingDialog::~SettingDialog()
{
    delete ui;
}
