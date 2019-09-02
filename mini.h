#ifndef MINI_H
#define MINI_H

#include <QWidget>
#include <QPushButton>

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
  bool drag;
  bool like;
  bool isPlaying;
  QPoint mouseStartPos;
  QPoint windowStartPos;

signals:
  void miniToMaxSignal();
  void miniToTraySignal();

  void sendLastSignal();
  void sendNextSignal();
  void sendPlayOrPauseSignal(bool);
  void sendLikeSignal(bool);

protected slots:

protected:
  void mousePressEvent(QMouseEvent*);
  void mouseMoveEvent(QMouseEvent*);
  void mouseReleaseEvent(QMouseEvent*);
  void enterEvent(QEvent*);
  void leaveEvent(QEvent*);

private slots:

  void on_maxModeBtn_clicked();

  void on_closeBtn_clicked();

  void on_volumeBtn_clicked();

  void on_playOrPauseBtn_clicked();
  void on_likeBtn_clicked();
};

#endif // MINI_H
