#ifndef METEOR_H
#define METEOR_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Meteor : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Meteor(QGraphicsItem *parent = nullptr);
private slots:
    void move();
    void rotate();
private:
    int counter;
};

#endif // METEOR_H
