#ifndef TMZPLAYER_H
#define TMZPLAYER_H

#include <QMainWindow>
#include <QtWidgets/QPushButton>
#include <QMouseEvent>


namespace Ui {
class TMZPlayer;
}

class TMZPlayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit TMZPlayer(QWidget *parent = nullptr);
    ~TMZPlayer();

    bool nativeEvent(const QByteArray &eventType, void *message, long *result);

protected:
private slots:



private:
    Ui::TMZPlayer *ui;


};

#endif // TMZPLAYER_H
