#include "smallwidget.h"
#include <QSpinBox>
#include<QSlider>
#include<QHBoxLayout>
SmallWidget::SmallWidget(QWidget *parent) : QWidget(parent){
    QSpinBox *spin =new QSpinBox(this);
    QSlider *slid=new QSlider(Qt::Horizontal,this);
    QHBoxLayout *Layout=new QHBoxLayout(this);
    Layout->addWidget(spin);
    Layout->addWidget(slid);
    setLayout(Layout);
    connect(spin,QOverload<int>::of(&QSpinBox::valueChanged),
            slid,
            &QSlider::setValue);
    connect(slid,&QSlider::valueChanged,spin,&QSpinBox::setValue);
}
