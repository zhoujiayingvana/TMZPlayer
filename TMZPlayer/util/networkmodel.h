#ifndef NETWORKMODEL_H
#define NETWORKMODEL_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>

class NetworkModel : public QWidget
{
    Q_OBJECT
public:
    explicit NetworkModel(QWidget *parent = nullptr);
    
signals:
    
public slots:
    void doProcessfinished(QNetworkReply*);
private:
    QNetworkAccessManager *m_Manager;//网络对象
    QNetworkRequest *m_Request;//请求对象
    QNetworkReply *m_Reply;//返回对象
    
};

#endif // NETWORKMODEL_H
