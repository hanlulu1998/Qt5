#ifndef DOMXML_H
#define DOMXML_H
#include<QString>
#include<QStringList>
#include<QDomDocument>
#include<QDomElement>
class DomXML
{
public:
    DomXML();

    static void createXML(QString filepath);

    static void appendXML(QString filepath,QStringList list);

    static void writeXML(QDomDocument &doc,QDomElement &root,QStringList &list);

    static void readXML(QString filePath,
                            QStringList &fList,
                            QStringList &bList,
                            QStringList &pList,
                            QStringList &nList,
                            QStringList &tList
                            );
};

#endif // DOMXML_H
