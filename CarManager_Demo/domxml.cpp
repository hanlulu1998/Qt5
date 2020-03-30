#include "domxml.h"
#include<QFile>
#include<QDomDocument> //文件
#include<QDomProcessingInstruction> //格式头部
#include<QDomElement> //元素
#include<QTextStream>
#include<QDateTime>
#include<QDomAttr>

DomXML::DomXML()
{

}
void DomXML::createXML(QString filepath){
    QFile file(filepath);
    if(true==file.exists()){
        return;
    }
    else{
        bool isOK=file.open(QIODevice::WriteOnly);
        if(true==isOK){
            QDomDocument doc;
            //创建格式头
            QDomProcessingInstruction ins;
            ins=doc.createProcessingInstruction("xml","version=\'1.0\' encoding=\'utf-8\'");
            doc.appendChild(ins);
            //根节点
            QDomElement root=doc.createElement("日销售清单");

            doc.appendChild(root);

            //保存
            QTextStream stream(&file);
            doc.save(stream,4);//文本流输出，4个空格
            file.close();
        }
    }
}
void DomXML::appendXML(QString filepath, QStringList list){
     QFile file(filepath);
     bool isOK=file.open(QIODevice::ReadOnly);
     if(true==isOK){
          QDomDocument doc;
          isOK=doc.setContent(&file);
          if(true==isOK){
               file.close();
               QDomElement root=doc.documentElement();
               QDateTime date=QDateTime::currentDateTime();
               QString dateStr=date.toString("yyyy-MM-dd");
               if(root.hasChildNodes()){

                   //查找最后子节点
                   QDomElement lastElement=root.lastChildElement();
                   if(lastElement.attribute("date")==dateStr)
                   {
                       DomXML::writeXML(doc,lastElement,list);
                   }
                   else
                   {
                       //创建日期
                         QDomElement dateElement=doc.createElement("日期");
                         //创建属性
                         QDomAttr dateAttr =doc.createAttribute("date");
                         dateAttr.setNodeValue(dateStr);

                         //节点关联属性
                         dateElement.setAttributeNode(dateAttr);

                         root.appendChild(dateElement);

                         DomXML::writeXML(doc,dateElement,list);
                   }

               }
               else {
                   //创建日期
                     QDomElement dateElement=doc.createElement("日期");
                     //创建属性
                     QDomAttr dateAttr =doc.createAttribute("date");
                     dateAttr.setNodeValue(dateStr);

                     //节点关联属性
                     dateElement.setAttributeNode(dateAttr);

                     root.appendChild(dateElement);

                     DomXML::writeXML(doc,dateElement,list);

               }
               //保存文件
               isOK=file.open(QIODevice::WriteOnly);
               if(true==isOK){
                   QTextStream stream(&file);
                   doc.save(stream,4);//文本流输出，4个空格
                   file.close();
               }
          }

     }

}
void DomXML::writeXML(QDomDocument &doc,QDomElement &root,QStringList &list){
    QDateTime time=QDateTime::currentDateTime();
    QString timeStr=time.toString("hh-mm-ss");

    //创建时间节点
    QDomElement timeElement=doc.createElement("时间");
    //创建属性
    QDomAttr timeAttr =doc.createAttribute("time");
    timeAttr.setNodeValue(timeStr);

    timeElement.setAttributeNode(timeAttr);

    root.appendChild(timeElement);

    QDomElement factory = doc.createElement("厂家");
    QDomElement brand = doc.createElement("品牌");
    QDomElement price = doc.createElement("报价");
    QDomElement num = doc.createElement("数量");
    QDomElement total = doc.createElement("金额");

    QDomText text = doc.createTextNode(list.at(0));
    factory.appendChild(text);

    text = doc.createTextNode(list.at(1));
    brand.appendChild(text);

    text = doc.createTextNode(list.at(2));
    price.appendChild(text);

    text = doc.createTextNode(list.at(3));
    num.appendChild(text);

    text = doc.createTextNode(list.at(4));
    total.appendChild(text);

    timeElement.appendChild(factory);
    timeElement.appendChild(brand);
    timeElement.appendChild(price);
    timeElement.appendChild(num);
    timeElement.appendChild(total);

}
void DomXML::readXML(QString filePath, QStringList &fList, QStringList &bList, QStringList &pList, QStringList &nList, QStringList &tList){
    QFile file(filePath);
       bool isOk = file.open(QIODevice::ReadOnly);
       if(true == isOk){
           QDomDocument doc;
           isOk = doc.setContent(&file);
           if(isOk){
               //获取根节点
               QDomElement root = doc.documentElement();
               file.close();

               QDateTime date = QDateTime::currentDateTime();
               QString dateStr = date.toString("yyyy-MM-dd");
               if(root.hasChildNodes()){
                   //找最后一个节点元素
                   QDomElement lastEmt = root.lastChildElement();
                   if(lastEmt.attribute("date") == dateStr){
                       //找出当前日期下所有时间子节点
                       QDomNodeList list = lastEmt.childNodes();
                       for(int i = 0; i < list.size(); i++){
                           //转换为元素，找到时间节点下的所有子节点
                           QDomNodeList subList = list.at(i).toElement().childNodes();

                           QString factory = subList.at(0).toElement().text();
                           fList.append(factory);

                           QString brand = subList.at(1).toElement().text();
                           bList.append(brand);

                           QString price = subList.at(2).toElement().text();
                           pList.append(price);

                           QString num = subList.at(3).toElement().text();
                           nList.append(num);

                           QString total = subList.at(4).toElement().text();
                           tList.append(total);
                       }
                   }

               }
           }

       }




}
