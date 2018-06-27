#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "player.h"
#include "score.h"
#include "health.h"
#include "shield.h"

class Game : public QGraphicsView
{
public:
    Game(QWidget *parent = nullptr);

    QGraphicsScene *scene;
    Player *player;
    Score *score;
    Health *health;
    Shield *shield;

    QTimer *enemy_timer;
    QTimer *meteor_timer;
    QTimer *life_timer;
    QTimer *bonus_timer;
    QTimer *boss_timer;

    unsigned int enemy_time;
    unsigned int meteor_time;
    unsigned int life_time;
    unsigned int bonus_time;
    unsigned int boss_time;
};

#endif // GAME_H
