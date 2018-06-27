#ifndef SHOT_H
#define SHOT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Shot : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Shot(QGraphicsItem *parent = nullptr);
private slots:
    void deleteShot();
};

#endif // SHOT_H
