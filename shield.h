#ifndef SHIELD_H
#define SHIELD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Shield : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Shield(QGraphicsItem *parent = nullptr);
private slots:
    void showShield();
};

#endif // SHIELD_H
