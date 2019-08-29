#ifndef MINI_H
#define MINI_H

#include "clickablelabel.h"
#include <QWidget>

namespace Ui {
  class Mini;
}

class Mini : public QWidget
{
  Q_OBJECT
  class clickableLabel;

public:
  explicit Mini(QWidget *parent = nullptr);
  ~Mini();

private:
  Ui::Mini *ui;

protected slots:
  void setVolume(int);
};

#endif // MINI_H
