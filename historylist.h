#ifndef HISTORYLIST_H
#define HISTORYLIST_H

#include <QListWidget>

class historyList : public QListWidget
{
  Q_OBJECT
public:
  explicit historyList(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // HISTORYLIST_H
