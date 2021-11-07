#include "scoremanager.h"
#include <QtMath>

namespace
{
    const float Radius1 = 22.0f;
    const float Radius2 = 35.0f;
    const float Radius3 = 55.0f;
    const float Radius4 = 67.0f;
    const float Radius5 = 84.0f;
    const float Radius6 = 100.0f;

    const float Center = 200.0f;

    const float DefaultPosition = -400.0f;

    const int ScoreForRadius1 = 10;
    const int ScoreForRadius2 = 40;
    const int ScoreForRadius3 = 20;
    const int ScoreForRadius4 = 40;
    const int ScoreForRadius5 = 20;
    const int ScoreForRadius6 = 15;
}

void ScoreManager::UpdatePlayerScore(Players player, float posX, float posY)
{
    if (player == Players::Player1)
    {
        m_FirstPlayerHits.push_back(QVector2D(posX, posY));
    }
    else
    {
        m_SecondPlayerHits.push_back(QVector2D(posX, posY));
    }

    int score = 0;

    if (IsInsideCircle(posX, posY, Radius1))
    {
        score = ScoreForRadius1;
    }
    else if (IsInsideCircle(posX, posY, Radius2))
    {
        score = ScoreForRadius2;
    }
    else if (IsInsideCircle(posX, posY, Radius3))
    {
        score = ScoreForRadius3;
    }
    else if (IsInsideCircle(posX, posY, Radius4))
    {
        score = ScoreForRadius4;
    }
    else if (IsInsideCircle(posX, posY, Radius5))
    {
        score = ScoreForRadius5;
    }
    else if (IsInsideCircle(posX, posY, Radius6))
    {
        score = ScoreForRadius6;
    }

    m_Score[player] += score;
}

bool ScoreManager::IsInsideCircle(float posX, float posY, float radius)
{
    float deltaX = posX - Center;
    float deltaY = posY - Center;

    return qPow(deltaX, 2) + qPow(deltaY, 2) <= qPow(radius, 2);
}

float ScoreManager::GetXCoord(Players player, int hitNumber) const
{
    if (player == Players::Player1)
    {
        if (m_FirstPlayerHits.empty())
        {
            return DefaultPosition;
        }

        return m_FirstPlayerHits[hitNumber].x();
    }

    if (m_SecondPlayerHits.empty())
    {
        return DefaultPosition;
    }
    return m_SecondPlayerHits[hitNumber].x();
}

float ScoreManager::GetYCoord(Players player, int hitNumber) const
{
    if (player == Players::Player1)
    {
        if (m_FirstPlayerHits.empty())
        {
            return DefaultPosition;
        }

        return m_FirstPlayerHits[hitNumber].y();
    }

    if (m_SecondPlayerHits.empty())
    {
        return DefaultPosition;
    }

    return m_SecondPlayerHits[hitNumber].y();
}

int ScoreManager::GetFirstPLayerScore() const
{
    return m_Score[Players::Player1];
}

int ScoreManager::GetSecondPlayerScore() const
{
    return m_Score[Players::Player2];
}

void ScoreManager::ResetScore()
{
    m_Score.clear();
    m_FirstPlayerHits.clear();
    m_SecondPlayerHits.clear();
}
