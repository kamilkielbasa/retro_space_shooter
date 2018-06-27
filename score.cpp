#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    score = 0;

    this->setPlainText(QString("Score : ") + QString::number(score));
    this->setDefaultTextColor(Qt::blue);
    this->setFont(QFont("times", 30, QFont::Bold));
}

void Score::increase(const int &n)
{
    score += n;
    this->setPlainText(QString("Score : ") + QString::number(score));
}

const int &Score::getScore() const
{
    return score;
}


