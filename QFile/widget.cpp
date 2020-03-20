#include "widget.h"
#include "ui_widget.h"
#include<QFileDialog>
#include<QFile>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_OpenButton_clicked()
{
    QString path =QFileDialog::getOpenFileName(this,"open","../");
    if(path.isEmpty()==false){
        QFile file(path);
        bool openFlag=file.open(QIODevice::ReadOnly);
        if(openFlag==true){
#if 0
           QByteArray array=file.readAll();
           ui->textEdit->setText(array);
#endif
           QByteArray array;
           while(file.atEnd()==false){
               array+=file.readLine();
           }
            ui->textEdit->setText(array);

        }
        file.close();
    }
}

void Widget::on_SaveButton_clicked()
{
    QString path =QFileDialog::getSaveFileName(this,"save","../");
     if(path.isEmpty()==false){
         QFile file(path);
         bool saveFlag=file.open(QIODevice::WriteOnly);
         if(saveFlag==true){
             QString str =ui->textEdit->toPlainText();
             file.write(str.toUtf8());
         }
         file.close();
     }


}
