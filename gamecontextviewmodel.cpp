#include "gamecontextviewmodel.h"

namespace
{
    const int FrameTime = 33;
    const int MaxHits = 4;
}

GameContextViewModel::GameContextViewModel(QObject *parent)
    : QObject(parent)
    , m_ActivePlayer(ScoreManager::Players::Player1)
    , m_HitCounter(0)
    , m_AimManager(new AimManager())
    , m_ScoreManager(new ScoreManager())
{
    m_Timer = new QTimer(this);
    connect(m_Timer, SIGNAL(timeout()), this, SLOT(onTimeExpired()));
    m_Timer->start(FrameTime);
}

GameContextViewModel::~GameContextViewModel()
{
    if (m_Timer != nullptr)
    {
        delete m_Timer;
    }

    if (m_ScoreManager != nullptr)
    {
        delete  m_ScoreManager;
    }

    if (m_AimManager != nullptr)
    {
        delete m_AimManager;
    }

}

void GameContextViewModel::onNewGameButtonClicked()
{
    ResetGameState();
}

void GameContextViewModel::ResetGameState()
{
    m_ScoreManager->ResetScore();
    emit playerScore();

    m_AimManager->ResetToDefault();
    emit player1Hit1();
    emit player1Hit2();
    emit player1Hit3();
    emit player1Hit4();
    emit player2Hit1();
    emit player2Hit2();
    emit player2Hit3();
    emit player2Hit4();

    m_ActivePlayer = ScoreManager::Players::Player1;

    m_HitCounter = 0;
    emit GetIsGameOver();
}

void GameContextViewModel::onMousePositionChanged(float posX, float posY)
{
    m_AimManager->UpdateMouseCursorPosition(posX, posY);
    emit aimPosUpdated();
}

float GameContextViewModel::GetAimPosX() const
{
    return m_AimManager->GetAimPosX();
}

float GameContextViewModel::GetAimPosY() const
{
    return m_AimManager->GetAimPosY();
}

void GameContextViewModel::onHit()
{
    if (m_ActivePlayer == ScoreManager::Players::Player1)
    {
        UpdateFirstPlayerScore();
    }
    else
    {
        UpdateSeconfPlayerScore();
    }

    emit playerScore();

    if (GetIsGameOver())
    {
        emit gameOver();
    }
}

void GameContextViewModel::UpdateFirstPlayerScore()
{
    m_ScoreManager->UpdatePlayerScore(ScoreManager::Players::Player1, GetAimPosX(), GetAimPosY());
    if (m_HitCounter == 0)
    {
        emit player1Hit1();
    }
    else if (m_HitCounter == 1)
    {
        emit player1Hit2();
    }
    else if (m_HitCounter == 2)
    {
        emit player1Hit3();
    }
    else if (m_HitCounter == 3)
    {
        emit player1Hit4();
    }

    m_ActivePlayer = ScoreManager::Players::Player2;
}

void GameContextViewModel::UpdateSeconfPlayerScore()
{
    m_ScoreManager->UpdatePlayerScore(ScoreManager::Players::Player2, GetAimPosX(), GetAimPosY());
    if (m_HitCounter == 0)
    {
        emit player2Hit1();
    }
    else if (m_HitCounter == 1)
    {
        emit player2Hit2();
    }
    else if (m_HitCounter == 2)
    {
        emit player2Hit3();
    }
    else if (m_HitCounter == 3)
    {
        emit player2Hit4();
    }

    m_ActivePlayer = ScoreManager::Players::Player1;
    m_HitCounter++;
}

void GameContextViewModel::onTimeExpired()
{
    if (!GetIsGameOver())
    {
        m_Timer->start(FrameTime);
        m_AimManager->Update();
        emit aimPosUpdated();
    }
}


float GameContextViewModel::GetPlayer1Hit1PosX() const
{
    return m_ScoreManager->GetXCoord(ScoreManager::Players::Player1, 0);
}

float GameContextViewModel::GetPlayer1Hit1PosY() const
{
    return m_ScoreManager->GetYCoord(ScoreManager::Players::Player1, 0);
}

float GameContextViewModel::GetPlayer1Hit2PosX() const
{
    return m_ScoreManager->GetXCoord(ScoreManager::Players::Player1, 1);
}

float GameContextViewModel::GetPlayer1Hit2PosY() const
{
    return m_ScoreManager->GetYCoord(ScoreManager::Players::Player1, 1);
}

float GameContextViewModel::GetPlayer1Hit3PosX() const
{
    return m_ScoreManager->GetXCoord(ScoreManager::Players::Player1, 2);
}

float GameContextViewModel::GetPlayer1Hit3PosY() const
{
    return m_ScoreManager->GetYCoord(ScoreManager::Players::Player1, 2);
}

float GameContextViewModel::GetPlayer1Hit4PosX() const
{
    return m_ScoreManager->GetXCoord(ScoreManager::Players::Player1, 3);
}

float GameContextViewModel::GetPlayer1Hit4PosY() const
{
    return m_ScoreManager->GetYCoord(ScoreManager::Players::Player1, 3);
}


float GameContextViewModel::GetPlayer2Hit1PosX() const
{
    return m_ScoreManager->GetXCoord(ScoreManager::Players::Player2, 0);
}

float GameContextViewModel::GetPlayer2Hit1PosY() const
{
    return m_ScoreManager->GetYCoord(ScoreManager::Players::Player2, 0);
}

float GameContextViewModel::GetPlayer2Hit2PosX() const
{
    return m_ScoreManager->GetXCoord(ScoreManager::Players::Player2, 1);
}

float GameContextViewModel::GetPlayer2Hit2PosY() const
{
    return m_ScoreManager->GetYCoord(ScoreManager::Players::Player2, 1);
}

float GameContextViewModel::GetPlayer2Hit3PosX() const
{
    return m_ScoreManager->GetXCoord(ScoreManager::Players::Player2, 2);
}

float GameContextViewModel::GetPlayer2Hit3PosY() const
{
    return m_ScoreManager->GetYCoord(ScoreManager::Players::Player2, 2);
}

float GameContextViewModel::GetPlayer2Hit4PosX() const
{
    return m_ScoreManager->GetXCoord(ScoreManager::Players::Player2, 3);
}

float GameContextViewModel::GetPlayer2Hit4PosY() const
{
    return m_ScoreManager->GetYCoord(ScoreManager::Players::Player2, 3);
}

QString GameContextViewModel::GetPlayer1Score()
{
    int score = m_ScoreManager->GetFirstPLayerScore();
    return QStringLiteral("Player 1 score: %1!").arg(score);
}

QString GameContextViewModel::GetPlayer2Score()
{
    int score = m_ScoreManager->GetSecondPlayerScore();
    return QStringLiteral("Player 2 score: %1!").arg(score);
}

bool GameContextViewModel::GetIsGameOver() const
{
    return m_HitCounter >= MaxHits;
}
