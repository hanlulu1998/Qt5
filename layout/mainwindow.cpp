#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_4->setText("<h1><a href=\"https://www.baidu.com\">"
                         "百度一下</a></h1>");
    ui->label_4->setOpenExternalLinks(true);
    ui->label_4->setScaledContents(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

