#ifndef HISTORY_H
#define HISTORY_H

#include <QLabel>
#include <QEvent>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

class history : public QWidget
{
  Q_OBJECT
public:
  explicit history(QWidget *parent = nullptr);
  void setNameAndAddress(QString,QString);

signals:

public slots:
  void deleteHistory();

protected:
  void enterEvent(QEvent*);
  void leaveEvent(QEvent*);

private:
  QLabel *NameLabel;
  QLabel *AddressLabel;
  QString name;
  QString address;
  QPushButton *deleteBtn;
};

#endif // HISTORY_H
