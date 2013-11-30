QT       += core
QT       += network
QT       -= gui

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

SOURCES += main.cpp \
    map.cpp \
    game.cpp \
    spritesheet.cpp \
    resourceholder.cpp \
    mapspritesheet.cpp

LIBS += -LD:/Qt/SFML-build/lib

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += D:/Qt/SFML-src/include
DEPENDPATH += D:/Qt/SFML-src/include

HEADERS += \
    map.h \
    game.h \
    spritesheet.h \
    resourceholder.h \
    mapspritesheet.h
