#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QStringList>
#include <QCompleter>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->InputEdit->setText("hanlulu");
    //ui->InputEdit->setEchoMode(QLineEdit::Password);
    QString str=ui->InputEdit->text();
    qDebug()<<str;
    //设置填充
    QStringList list;
    list<<"Han"<<"hanlulu"<<"hanlu";
    QCompleter *com=new QCompleter(list,this);
    com->setCaseSensitivity(Qt::CaseInsensitive);
    ui->InputEdit->setCompleter(com);
    ui->labelTex->setText("显示文字");
    ui->labelImg->setPixmap(QPixmap(":/image/img/ahu.png"));
    ui->labelImg->setScaledContents(true);
    ui->labelurl->setText("<h1><a href=\"https://www.baidu.com\">百度一下</h1>");
    ui->labelurl->setOpenExternalLinks(true);
    ui->labelurl->setScaledContents(true);





}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_NextButton_pressed()
{
    //设置槽
    static int i=0;
    ui->stackedWidget->setCurrentIndex(++i%4);
}

void MainWindow::on_addButton_clicked()
{
   static int i=0;
   ui->progressBar->setValue((++i)*10);
}
