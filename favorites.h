#ifndef FAVORITES_H
#define FAVORITES_H

#include <QFont>
#include <QIcon>
#include <QPushButton>

class favorites : public QPushButton
{
  Q_OBJECT
public:
  explicit favorites(QWidget *parent = nullptr);

signals:
  void sendingFavoritesSNAndFiles(int,QList<QString>);
  void sendingFavoritesNameSignal(QString);

public slots:
  void favoritesBtnClickedSlot();
  void changeFilesInListSlot(int currentSN,QList<QString> temp_filesInList);

private:
  int SN;
  QList<QString> favoritesList;
};

#endif // FAVORITES_H
