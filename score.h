#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QGraphicsItem>

class Score : public QGraphicsTextItem
{
public:
    explicit Score(QGraphicsItem *parent = nullptr);

    void increase(const int&);
    const int& getScore() const;
private:
    int score;
};

#endif // SCORE_H
