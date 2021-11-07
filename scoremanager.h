#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H

#include <QVector>
#include <QVector2D>
#include <QMap>

class ScoreManager
{
public:
    enum class Players
    {
        Player1 = 0,
        Player2 = 1,
        Count
    };


public:
    ScoreManager() = default;
    ~ScoreManager() = default;

    void UpdatePlayerScore(Players player, float posX, float posY);

    float GetXCoord(Players player, int hitNumber) const;
    float GetYCoord(Players player, int hitNumber) const;

    int GetFirstPLayerScore() const;
    int GetSecondPlayerScore() const;

    void ResetScore();

private:
    bool IsInsideCircle(float posX, float posY, float radius);

private:
    QVector<QVector2D> m_FirstPlayerHits;
    QVector<QVector2D> m_SecondPlayerHits;

    QMap<Players, int> m_Score;
};

#endif // SCOREMANAGER_H
