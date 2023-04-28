QT       += core gui openglwidgets \
        multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Sources/Bullet.cpp \
    Sources/Enemy.cpp \
    Sources/Game.cpp \
    Sources/Health.cpp \
    Sources/Player.cpp \
    Sources/Score.cpp \
    Sources/main.cpp \

HEADERS += \
    Headers/Enemy.h \
    Headers/Game.h \
    Headers/Bullet.h \
    Headers/Enemy.h \
    Headers/Game.h \
    Headers/Health.h \
    Headers/Player.h \
    Headers/Score.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    Resources.qrc
