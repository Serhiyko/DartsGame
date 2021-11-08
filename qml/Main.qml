import Felgo 3.0
import QtQuick 2.0
import com.mycompany.gamecontext 1.0

GameWindow {
    id: battleSeaWindow
    screenWidth: 960
    screenHeight: 640

    GameContextViewModel {
        id: gamecontext
        onGameOver: {
            resultPopUp.visible = true
            dartsMouseArea.cursorShape = Qt.ArrowCursor
        }
    }

    Scene {
        Rectangle
        {
            id: dartsField
            width: 400
            height: 400
            color: "green"
            anchors.centerIn: parent

            Image {
                id: aimField
                source: "../assets/dartsboard.png"
                width: 200
                height: 200
                anchors.centerIn: parent
            }

            Rectangle {
                id: player1Hit1
                visible: true
                width: 10
                height: 10
                color: "black"
                radius: width*0.5

                x: Number(gamecontext.player1Hit1PosX).toFixed(2)
                y: Number(gamecontext.player1Hit1PosY).toFixed(2)
            }

            Rectangle {
                id: player1Hit2
                visible: true
                width: 10
                height: 10
                color: "black"
                radius: width*0.5
                x: Number(gamecontext.player1Hit2PosX).toFixed(2)
                y: Number(gamecontext.player1Hit2PosY).toFixed(2)
            }

            Rectangle {
                id: player1Hit3
                visible: true
                width: 10
                height: 10
                color: "black"
                radius: width*0.5
                x: Number(gamecontext.player1Hit3PosX).toFixed(2)
                y: Number(gamecontext.player1Hit3PosY).toFixed(2)
            }

            Rectangle {
                id: player1Hit4
                visible: true
                width: 10
                height: 10
                color: "black"
                radius: width*0.5
                x: Number(gamecontext.player1Hit4PosX).toFixed(2)
                y: Number(gamecontext.player1Hit4PosY).toFixed(2)
            }

            Rectangle {
                id: player2Hit1
                visible: true
                width: 10
                height: 10
                color: "violet"
                radius: width*0.5
                x: Number(gamecontext.player2Hit1PosX).toFixed(2)
                y: Number(gamecontext.player2Hit1PosY).toFixed(2)
            }

            Rectangle {
                id: player2Hit2
                visible: true
                width: 10
                height: 10
                color: "violet"
                radius: width*0.5
                x: Number(gamecontext.player2Hit2PosX).toFixed(2)
                y: Number(gamecontext.player2Hit2PosY).toFixed(2)
            }

            Rectangle {
                id: player2Hit3
                visible: true
                width: 10
                height: 10
                color: "violet"
                radius: width*0.5
                x: Number(gamecontext.player2Hit3PosX).toFixed(2)
                y: Number(gamecontext.player2Hit3PosY).toFixed(2)
            }

            Rectangle {
                id: player2Hit4
                visible: true
                width: 10
                height: 10
                color: "violet"
                radius: width*0.5
                x: Number(gamecontext.player2Hit4PosX).toFixed(2)
                y: Number(gamecontext.player2Hit4PosY).toFixed(2)
            }

            MouseArea {
                id: dartsMouseArea
                anchors.fill: parent
                hoverEnabled: true
                cursorShape: Qt.BlankCursor
                onPositionChanged: {
                    gamecontext.onMousePositionChanged(mouseX, mouseY)
                }

                onClicked: {
                    gamecontext.onHit()
                }
            }

            Image {
                id: aim
                source: "../assets/aim.png"
                width: 30
                height: 30
                x: gamecontext.aimPosX
                y: gamecontext.aimPosY
            }
        }

        Text {
            id: player1Score
            text: gamecontext.player1Score
            color: "white"
            font.pixelSize: 16
            anchors.top: parent.top
            x: 300
        }

        Text {
            id: player2Score
            text: gamecontext.player2Score
            color: "white"
            font.pixelSize: 16
            anchors.top: parent.top
            x: 100
        }

        Rectangle {
            id: resultPopUp
            width: 150
            height: 100
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter:  parent.verticalCenter
            visible: false

            Text {
                id: winnerString
                text: gamecontext.gameWinner
                color: "#32665a"
                font.pixelSize: 16
                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Rectangle {
                id: newGameButton
                width: 100
                height: 50
                color: "#32665a"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter:  parent.verticalCenter


                Text {
                    text: "New Game"
                    color: "white"
                    anchors.centerIn: parent
                }

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        resultPopUp.visible = false
                        dartsMouseArea.cursorShape = Qt.BlankCursor
                        gamecontext.onNewGameButtonClicked()
                    }
                }
            }
        }
    }
}
