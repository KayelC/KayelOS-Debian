/* === This file is part of Calamares - <http://github.com/calamares> === */

import QtQuick 2.0;
import calamares.slideshow 1.0;

Presentation
{
    id: presentation

    function nextSlide() { presentation.goToNextSlide(); }

    Timer {
        id: advanceTimer
        interval: 7500
        running: true
        repeat: true
        onTriggered: nextSlide()
    }

    // --- VARIABILI GLOBALI DEL TEMA ---
    property string themeColor: "#C59B27"      // Oro antico
    property string shadowColor: "#1a1a1a"     // Ombra scura
    property string textFont: "Helvetica"
    property int textSize: 22
    property color panelColor: "#000000"       // Vlak achter de tekst
    property real panelOpacity: 0.45
    property int panelRadius: 8
    property int panelMargin: 6

    // Sfondo globale per fondere gli eventuali margini con la sidebar
    Rectangle {
        anchors.fill: parent
        color: "#292F34" 
        z: -1
    }

    // --- SLIDE 1 ---
    Slide {
        Item {
            anchors.centerIn: parent
            width: Math.min(parent.width, parent.height * (810.0/485.0))
            height: Math.min(parent.height, parent.width / (810.0/485.0))

            Image { source: "1-reproductive-system.png"; anchors.fill: parent }
            Rectangle {
                color: panelColor; opacity: panelOpacity; radius: panelRadius
                width: text1.contentWidth + panelMargin * 2; height: text1.contentHeight + panelMargin * 2
                anchors.horizontalCenter: text1.horizontalCenter
                anchors.top: text1.top; anchors.topMargin: -panelMargin
            }
            Text {
                id: text1
                font.family: textFont; font.pixelSize: textSize; font.bold: true; color: themeColor; style: Text.Outline; styleColor: shadowColor
                anchors.centerIn: parent
                wrapMode: Text.WordWrap; width: parent.width * 0.95; horizontalAlignment: Text.Center
                textFormat: Text.RichText
                text: qsTr("<h1>Welcome to KayelOS</h1><br/><h2>A focused Debian-based environment built for class, development and everyday use.</h2>")
            }
        }
    }

    // --- SLIDE 2 ---
    Slide {
        Item {
            anchors.centerIn: parent
            width: Math.min(parent.width, parent.height * (810.0/485.0))
            height: Math.min(parent.height, parent.width / (810.0/485.0))

            Image { source: "2-start-reproduction.png"; anchors.fill: parent }
            Rectangle {
                color: panelColor; opacity: panelOpacity; radius: panelRadius
                width: text2.contentWidth + panelMargin * 2; height: text2.contentHeight + panelMargin * 2
                anchors.horizontalCenter: text2.horizontalCenter
                anchors.top: text2.top; anchors.topMargin: -panelMargin
            }
            Text {
                id: text2
                font.family: textFont; font.pixelSize: textSize; font.bold: true; color: themeColor; style: Text.Outline; styleColor: shadowColor
                anchors.centerIn: parent
                wrapMode: Text.WordWrap; width: parent.width * 0.95; horizontalAlignment: Text.Center
                textFormat: Text.RichText
                text: qsTr("<h1>KayelOS</h1><br/><h2>Built on Debian 13 with a lightweight DWM desktop.</h2>")
            }
        }
    }

    // --- SLIDE 3 ---
    Slide {
        Item {
            anchors.centerIn: parent
            width: Math.min(parent.width, parent.height * (810.0/485.0))
            height: Math.min(parent.height, parent.width / (810.0/485.0))

            Image { source: "3-its-your-system.png"; anchors.fill: parent }
            Rectangle {
                color: panelColor; opacity: panelOpacity; radius: panelRadius
                width: text3.contentWidth + panelMargin * 2; height: text3.contentHeight + panelMargin * 2
                anchors.horizontalCenter: text3.horizontalCenter
                anchors.top: text3.top; anchors.topMargin: -panelMargin
            }
            Text {
                id: text3
                font.family: textFont; font.pixelSize: textSize; font.bold: true; color: themeColor; style: Text.Outline; styleColor: shadowColor
                anchors.centerIn: parent
                wrapMode: Text.WordWrap; width: parent.width * 0.95; horizontalAlignment: Text.Center
                textFormat: Text.RichText
                text: qsTr("<h1>Your environment</h1><br/><h2>QuickShell, terminal tools and development essentials are ready from first boot.</h2>")
            }
        }
    }

    // --- SLIDE 4 ---
    Slide {
        Item {
            anchors.centerIn: parent
            width: Math.min(parent.width, parent.height * (810.0/485.0))
            height: Math.min(parent.height, parent.width / (810.0/485.0))

            Image { source: "4-eggs-presentation.png"; anchors.fill: parent }
            Rectangle {
                color: panelColor; opacity: panelOpacity; radius: panelRadius
                width: text4.contentWidth + panelMargin * 2; height: text4.contentHeight + panelMargin * 2
                anchors.horizontalCenter: text4.horizontalCenter
                anchors.top: text4.top; anchors.topMargin: -panelMargin
            }
            Text {
                id: text4
                font.family: textFont; font.pixelSize: textSize; font.bold: true; color: themeColor; style: Text.Outline; styleColor: shadowColor
                anchors.centerIn: parent
                wrapMode: Text.WordWrap; width: parent.width * 0.95; horizontalAlignment: Text.Center
                textFormat: Text.RichText
                text: qsTr("<h1>Simple by design</h1><br/><h2>A clean desktop that stays out of your way.</h2>")
            }
        }
    }

    // --- SLIDE 5 ---
    Slide {
        Item {
            anchors.centerIn: parent
            width: Math.min(parent.width, parent.height * (810.0/485.0))
            height: Math.min(parent.height, parent.width / (810.0/485.0))

            Image { source: "5-wait-hatching.png"; anchors.fill: parent }
            Rectangle {
                color: panelColor; opacity: panelOpacity; radius: panelRadius
                width: text5.contentWidth + panelMargin * 2; height: text5.contentHeight + panelMargin * 2
                anchors.horizontalCenter: text5.horizontalCenter
                anchors.top: text5.top; anchors.topMargin: -panelMargin
            }
            Text {
                id: text5
                font.family: textFont; font.pixelSize: textSize; font.bold: true; color: themeColor; style: Text.Outline; styleColor: shadowColor
                anchors.centerIn: parent
                wrapMode: Text.WordWrap; width: parent.width * 0.95; horizontalAlignment: Text.Center
                textFormat: Text.RichText
                text: qsTr("<h1>Installing KayelOS</h1><br/><h3>Your system is being prepared.<br/>This may take a few minutes.</h3>")
            }
        }
    }

    // --- SLIDE 6 ---
    Slide {
        Item {
            anchors.centerIn: parent
            width: Math.min(parent.width, parent.height * (810.0/485.0))
            height: Math.min(parent.height, parent.width / (810.0/485.0))

            Image { source: "6-follow-penguins.png"; anchors.fill: parent }
            Rectangle {
                color: panelColor; opacity: panelOpacity; radius: panelRadius
                width: text6.contentWidth + panelMargin * 2; height: text6.contentHeight + panelMargin * 2
                anchors.horizontalCenter: text6.horizontalCenter
                anchors.top: text6.top; anchors.topMargin: -panelMargin
            }
            Text {
                id: text6
                font.family: textFont; font.pixelSize: textSize; font.bold: true; color: themeColor; style: Text.Outline; styleColor: shadowColor
                anchors.centerIn: parent
                wrapMode: Text.WordWrap; width: parent.width * 0.95; horizontalAlignment: Text.Center
                textFormat: Text.RichText
                text: qsTr("<h1>Almost ready</h1><br/><h2>Your KayelOS installation is nearly complete.</h2>")
            }
        }
    }

    // --- SLIDE 7 ---
    Slide {
        Item {
            anchors.centerIn: parent
            width: Math.min(parent.width, parent.height * (810.0/485.0))
            height: Math.min(parent.height, parent.width / (810.0/485.0))

            Image { source: "7-created-by.png"; anchors.fill: parent }
            Rectangle {
                color: panelColor; opacity: panelOpacity; radius: panelRadius
                width: text7.contentWidth + panelMargin * 2; height: text7.contentHeight + panelMargin * 2
                anchors.horizontalCenter: text7.horizontalCenter
                anchors.top: text7.top; anchors.topMargin: -panelMargin
            }
            Text {
                id: text7
                font.family: textFont; font.pixelSize: textSize; font.bold: true; color: themeColor; style: Text.Outline; styleColor: shadowColor
                anchors.centerIn: parent
                wrapMode: Text.WordWrap; width: parent.width * 0.95; horizontalAlignment: Text.Center
                textFormat: Text.RichText
                text: qsTr("<h1>KayelOS</h1><br/><h2>Installation complete. Enjoy your new system.</h2>")
            }
        }
    }
    
    function onActivate() { presentation.currentSlide = 0; }
}
