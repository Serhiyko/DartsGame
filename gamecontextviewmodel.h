#ifndef GAMECONTEXTVIEWMODEL_H
#define GAMECONTEXTVIEWMODEL_H

#include <QObject>
#include <qqml.h>
#include <QTimer>
#include <QString>

#include "aimmanager.h"
#include "scoremanager.h"

class GameContextViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(float aimPosX READ GetAimPosX NOTIFY aimPosUpdated)
    Q_PROPERTY(float aimPosY READ GetAimPosY NOTIFY aimPosUpdated)


    Q_PROPERTY(float player1Hit1PosX READ GetPlayer1Hit1PosX NOTIFY player1Hit1);
    Q_PROPERTY(float player1Hit1PosY READ GetPlayer1Hit1PosY NOTIFY player1Hit1);

    Q_PROPERTY(float player2Hit1PosX READ GetPlayer2Hit1PosX NOTIFY player2Hit1);
    Q_PROPERTY(float player2Hit1PosY READ GetPlayer2Hit1PosY NOTIFY player2Hit1);


    Q_PROPERTY(float player1Hit2PosX READ GetPlayer1Hit2PosX NOTIFY player1Hit2);
    Q_PROPERTY(float player1Hit2PosY READ GetPlayer1Hit2PosY NOTIFY player1Hit2);

    Q_PROPERTY(float player2Hit2PosX READ GetPlayer2Hit2PosX NOTIFY player2Hit2);
    Q_PROPERTY(float player2Hit2PosY READ GetPlayer2Hit2PosY NOTIFY player2Hit2);


    Q_PROPERTY(float player1Hit3PosX READ GetPlayer1Hit3PosX NOTIFY player1Hit3);
    Q_PROPERTY(float player1Hit3PosY READ GetPlayer1Hit3PosY NOTIFY player1Hit3);

    Q_PROPERTY(float player2Hit3PosX READ GetPlayer2Hit3PosX NOTIFY player2Hit3);
    Q_PROPERTY(float player2Hit3PosY READ GetPlayer2Hit3PosY NOTIFY player2Hit3);


    Q_PROPERTY(float player1Hit4PosX READ GetPlayer1Hit4PosX NOTIFY player1Hit4);
    Q_PROPERTY(float player1Hit4PosY READ GetPlayer1Hit4PosY NOTIFY player1Hit4);

    Q_PROPERTY(float player2Hit4PosX READ GetPlayer2Hit4PosX NOTIFY player2Hit4);
    Q_PROPERTY(float player2Hit4PosY READ GetPlayer2Hit4PosY NOTIFY player2Hit4);


    Q_PROPERTY(QString player1Score READ GetPlayer1Score NOTIFY playerScore);
    Q_PROPERTY(QString player2Score READ GetPlayer2Score NOTIFY playerScore);
    Q_PROPERTY(QString gameWinner READ GetGameWinner NOTIFY gameOver)

    QML_ELEMENT
public:
    explicit GameContextViewModel(QObject *parent = nullptr);
    ~GameContextViewModel();

    float GetAimPosX() const;
    float GetAimPosY() const;


    float GetPlayer1Hit1PosX() const;
    float GetPlayer1Hit1PosY() const;

    float GetPlayer1Hit2PosX() const;
    float GetPlayer1Hit2PosY() const;

    float GetPlayer1Hit3PosX() const;
    float GetPlayer1Hit3PosY() const;

    float GetPlayer1Hit4PosX() const;
    float GetPlayer1Hit4PosY() const;


    float GetPlayer2Hit1PosX() const;
    float GetPlayer2Hit1PosY() const;

    float GetPlayer2Hit2PosX() const;
    float GetPlayer2Hit2PosY() const;

    float GetPlayer2Hit3PosX() const;
    float GetPlayer2Hit3PosY() const;

    float GetPlayer2Hit4PosX() const;
    float GetPlayer2Hit4PosY() const;

    QString GetPlayer1Score() const;
    QString GetPlayer2Score() const;

    QString GetGameWinner() const;

private:
    void ResetGameState();

    void UpdateFirstPlayerScore();
    void UpdateSeconfPlayerScore();

    bool GetIsGameOver() const;

signals:
    void aimPosUpdated();

    void player1Hit1();
    void player1Hit2();
    void player1Hit3();
    void player1Hit4();

    void player2Hit1();
    void player2Hit2();
    void player2Hit3();
    void player2Hit4();

    void playerScore();
    void gameOver();

public slots:
    void onNewGameButtonClicked();

    void onMousePositionChanged(float posX, float posY);
    void onHit();

    void onTimeExpired();

private:
    ScoreManager::Players m_ActivePlayer;
    int m_HitCounter;

    AimManager* m_AimManager;
    ScoreManager* m_ScoreManager;
    QTimer* m_Timer;
};

#endif // GAMECONTEXTVIEWMODEL_H
