#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>

class Health : public QGraphicsPixmapItem
{
public:
    explicit Health(QGraphicsItem *parent = nullptr);

    void increase();
    void decrease();
    const int &getHealth() const;
    void setPixmapForHealthBar(int);
private:
    int health;
};

#endif // HEALTH_H
