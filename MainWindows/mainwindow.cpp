#include "mainwindow.h"
# include<QMenuBar>
#include<QMenu>
#include<QAction>
#include <QDebug>
#include<QToolBar>
#include<QPushButton>
#include<QStatusBar>
#include<QLabel>
#include<QTextEdit>
#include<QDockWidget>
#include<QDialog>
#include<QMessageBox>
#include<QFileDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *Bar=menuBar();
    setMenuBar(Bar);
    //菜单栏
    QMenu *pFile=Bar->addMenu("文件");
    QAction *pNew=pFile->addAction("新建");
    pFile->addSeparator();//添加分割线
    connect(pNew,&QAction::triggered,
            [=](){
        qDebug()<<"新建成功";

    });
    QAction *pOpen=pFile->addAction("打开");
    connect(pOpen,&QAction::triggered,
            [=](){
        QString fileName=QFileDialog::getOpenFileName(this,
                                                      "打开",
                                                      "../",
                                                      "All(*);;"
                                                      "cpp(*.cpp *.hpp);;"
                                                      "c(*.c *.h)");
        qDebug()<<"打开成功"<<fileName;

    });
    //工具栏
    QToolBar *ToolBar=addToolBar("工具栏");
    ToolBar->addAction(pNew);
    QPushButton *b=new QPushButton(this);
    b->setText("打开");
    connect(b,&QPushButton::clicked,
            [=](){
        QString fileName=QFileDialog::getOpenFileName(this,
                                                      "打开",
                                                      "../",
                                                      "All(*);;"
                                                      "cpp(*.cpp *.hpp);;"
                                                      "c(*.c *.h)");
       qDebug()<<"打开成功"<<fileName;
    });
    ToolBar->addSeparator();
    ToolBar->addWidget(b);

    //状态栏
    QStatusBar *StatusBar=statusBar();
    QLabel *Label=new QLabel(this);
    Label->setText("已就绪");
    StatusBar->addWidget(Label);
    StatusBar->addWidget(new QLabel("工作中",this));

    //文本编辑
    QTextEdit *TextEdit=new QTextEdit(this);
    setCentralWidget(TextEdit);

    //浮动栏
    QDockWidget *DockWidget=new QDockWidget(this);
    addDockWidget(Qt::LeftDockWidgetArea,DockWidget);
    QTextEdit *TextDock=new QTextEdit(this);
    DockWidget->setWidget(TextDock);

    //菜单栏
    QAction *pMod=Bar->addAction("模态对话框");
    QAction *pNMod=Bar->addAction("非模态对话框");
    connect(pMod,&QAction::triggered,
            [=](){
       QDialog ModDialog;
       ModDialog.exec();
       qDebug()<<"模态对话框已经关闭";

    });
    connect(pNMod,&QAction::triggered,
            [=](){
        //设置非模态对话框自动回收内存
       QDialog *NModDialog=new QDialog;
       NModDialog->setAttribute(Qt::WA_DeleteOnClose);
       NModDialog->show();
       qDebug()<<"非模态对话框已经打开";

    });
    QAction *pExit=pFile->addAction("退出");
    connect(pExit,&QAction::triggered,this,&MainWindow::close);
    QAction *pAbout=Bar->addAction("关于");
    connect(pAbout,&QAction::triggered,
            [=](){
        QMessageBox::about(this,"关于","Qt程序设计");
    });
    QAction *pUpdate=Bar->addAction("更新");
    connect(pUpdate,&QAction::triggered,
            [=](){
       int ret=QMessageBox::question(this,"更新","是否更新");
       switch (ret) {
       case QMessageBox::Yes: qDebug()<<"更新中";break;
       case QMessageBox::No:  qDebug()<<"未更新";break;
       }

    });










}

MainWindow::~MainWindow()
{
}

