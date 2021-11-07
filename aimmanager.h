#ifndef AIMMANAGER_H
#define AIMMANAGER_H

#include <QVector2D>

class AimManager
{
public:
    AimManager();
    ~AimManager() = default;

    void UpdateMouseCursorPosition(float activeMousePosX, float activeMousePosY);
    void Update();

    float GetAimPosX() const {return m_AimPosX + 15.0f;}
    float GetAimPosY() const {return m_AimPosY + 15.0f;}

    void ResetToDefault();

private:
    float m_MousePosX;
    float m_MousePosY;

    float m_AimPosX;
    float m_AimPosY;

    QVector2D m_Direction;
};

#endif // AIMMANAGER_H
