#include "aimmanager.h"

#include <QDebug>
#include <QRandomGenerator>

namespace
{
const float DefaultCursorPosition = 200.0f;
    const float DefaultAimPosition = 185.0f;
    const float AimRange = 25.0f;
    const float Dt = 4.5f;
    const int MinRange = -2;
    const int MaxRange = 3;
    const int DefaultMinDirection = -10;
    const int DefaultMaxDirection = 10;
}

AimManager::AimManager()
    : m_MousePosX(DefaultCursorPosition)
    , m_MousePosY(DefaultCursorPosition)
    , m_AimPosX(DefaultAimPosition)
    , m_AimPosY(DefaultAimPosition)
    , m_Direction(0.0f, 0.0f)
{

}

void AimManager::ResetToDefault()
{
    m_MousePosX = m_MousePosY = DefaultCursorPosition;
    m_AimPosX = m_AimPosY = DefaultAimPosition;
    m_Direction = QVector2D(0.0f, 0.0f);
}

void AimManager::Update()
{
    if (m_Direction.isNull())
    {
        float randomX = static_cast<float>(QRandomGenerator::global()->bounded(DefaultMinDirection, DefaultMaxDirection));
        float randomY = static_cast<float>(QRandomGenerator::global()->bounded(DefaultMinDirection, DefaultMaxDirection));
        m_Direction = QVector2D(randomX, randomY).normalized();
    }

    if ((m_AimPosX >= m_MousePosX + AimRange) || (m_AimPosX <= m_MousePosX - AimRange))
    {
        int rand = static_cast<float>(QRandomGenerator::global()->bounded(MinRange, MaxRange));
        if (rand == 0)
        {
            rand = 1;
        }
        float newX = m_MousePosX + static_cast<float>(rand);

        m_Direction.setX(newX - m_AimPosX);
        m_Direction.setY(m_MousePosY - m_AimPosY);

    }
    if ((m_AimPosY >= m_MousePosY + AimRange) || (m_AimPosY <= m_MousePosY - AimRange))
    {
        int rand = static_cast<float>(QRandomGenerator::global()->bounded(MinRange, MaxRange));
        if (rand == 0)
        {
            rand = 1;
        }
        float newY = m_MousePosY + static_cast<float>(rand);

        m_Direction.setX(m_MousePosX - m_AimPosX);
        m_Direction.setY(newY - m_AimPosY);
    }

    m_Direction.normalize();
    m_AimPosX += m_Direction.x() * Dt;
    m_AimPosY += m_Direction.y() * Dt;
}

void AimManager::UpdateMouseCursorPosition(float activeMousePosX, float activeMousePosY)
{
    m_MousePosX = activeMousePosX;
    m_MousePosY = activeMousePosY;
}
