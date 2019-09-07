#ifndef HISTORY_H
#define HISTORY_H

#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>

class history : public QWidget
{
  Q_OBJECT
public:
  explicit history(QWidget *parent = nullptr);
  void setAddress(QString);

signals:

public slots:
  void deleteHistory();

private:
  QLabel *NameLabel;
  QLabel *AddressLabel;
  QString address;
  QPushButton *deleteBtn;
};

#endif // HISTORY_H
