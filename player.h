#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

enum ShotType { Single, Double, Triple };

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Player(QGraphicsItem *parent = nullptr);

    void keyPressEvent(QKeyEvent *event);

    const QMediaPlayer& getExpSound() const { return *explosion_sound; }
    QMediaPlayer& setExpSound() { return *explosion_sound; }

    void setShotType(const ShotType& st) { shot_type = st; }
    const ShotType& getShotType() const { return shot_type; }

private slots:
    void enemySpawn();
    void meteorSpawn();
    void lifeSpawn();
    void bonusSpawn();
    void bossSpawn();

private:
    void chooseShotType(const ShotType&);
    void backToSingleShot();

private:
    unsigned int double_shot;
    unsigned int triple_shot;
    ShotType shot_type;
    QMediaPlayer *bullet_sound;
    QMediaPlayer *explosion_sound;
};

#endif // PLAYER_H
