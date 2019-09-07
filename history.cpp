#include "history.h"

history::history(QWidget *parent) : QWidget(parent)
{
  if (this->objectName().isEmpty())
    this->setObjectName(QString::fromUtf8("this"));
  this->resize(221, 57);

  NameLabel = new QLabel(this);
  NameLabel->setObjectName(QString::fromUtf8("NameLabel"));
  NameLabel->setGeometry(QRect(0, 0, 221, 31));
  NameLabel->setText("歌曲名字");

  QFont font;
  font.setFamily(QString::fromUtf8("Adobe Arabic"));
  font.setPointSize(11);

  NameLabel->setFont(font);
  AddressLabel = new QLabel(this);
  AddressLabel->setObjectName(QString::fromUtf8("AddressLabel"));
  AddressLabel->setGeometry(QRect(0, 31, 221, 21));
  AddressLabel->setText("歌曲地址");

  deleteBtn = new QPushButton(this);
  deleteBtn->setObjectName(QString::fromUtf8("deleteBtn"));
  deleteBtn->setGeometry(QRect(190, 8, 20, 20));
  QIcon icon;
  icon.addFile(QString::fromUtf8(":/image/image/btn_delete_n.png"), QSize(), QIcon::Normal, QIcon::Off);
  deleteBtn->setIcon(icon);
  deleteBtn->setFlat(true);

  connect(deleteBtn,SIGNAL(clicked()),this,SLOT(deleteHistory));
}

/* Author: zyt
 * Name: setAddress
 * Function: 设置该历史记录的文件位置
 */
void history::setAddress(QString _address)
{
  address = _address;
  this->AddressLabel->setText(address);
}

/* Author: zyt
 * Name: deleteHistory
 * Function: 槽：删除该历史纪录
 */
void history::deleteHistory()
{
  delete this;
}
