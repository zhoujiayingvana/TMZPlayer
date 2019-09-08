#include "networkmodel.h"

NetworkModel::NetworkModel(QWidget *parent) : QWidget(parent)
{
    //初始化
    this->m_Manager=new QNetworkAccessManager(this);
    connect(m_Manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(doProcessfinished(QNetworkReply*)));
    this->m_Request=new QNetworkRequest();

//   this->m_Request->setUrl(QUrl("http://jx.618g.com/?url=https://www.iqiyi.com/v_19rrtd7tr4.html?vfrm=pcw_home&vfrmblk=B&vfrmrst=fcs_0_p11"));

//    //获取哔哩哔哩access key，成功
//    this->m_Request->setUrl(QUrl("https://api.kaaass.net/biliapi/user/login"));
//    QByteArray append("user=bili_7687549109&passwd=zjy19981213");
//    this->m_Reply=this->m_Manager->post(*this->m_Request,append);
    
    
//    //每日视频推荐，有待完善
//    this->m_Request->setUrl(QUrl("https://api.apiopen.top/todayVideo"));
//    this->m_Reply=this->m_Manager->get(*this->m_Request);
    
//    //音乐搜索，成功
//    this->m_Request->setUrl(QUrl("https://api.apiopen.top/searchMusic?name=周杰伦"));
//    this->m_Reply=this->m_Manager->get(*this->m_Request);
    
    //解析哔哩哔哩视频2，成功
    this->m_Request->setUrl(QUrl("https://api.kaaass.net/biliapi/video/resolve?id=47797049&access_key=79ae0015%2C1570090912%2C756a1991&direct=true&dash=true"));//请求解析b站的视频
    this->m_Reply = this->m_Manager->get(*this->m_Request);
    
    //油管视频解析
//    this->m_Request->setUrl(QUrl("http://www.youtube.com/get_video_info?video_id=dQ3Mt9yiz6k"));
//    this->m_Reply=this->m_Manager->get(*this->m_Request);    
    
    
    //使用官方api解析哔哩哔哩视频
//    this->m_Request->setUrl((QUrl()));
}
void NetworkModel::doProcessfinished(QNetworkReply * reply)
{
    qDebug()<<reply->readAll();
    QJsonObject data = QJsonDocument::fromJson(reply->readAll()).object();
    qDebug() << data;
}
