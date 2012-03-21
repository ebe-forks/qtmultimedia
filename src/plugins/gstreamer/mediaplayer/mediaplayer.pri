INCLUDEPATH += $$PWD

DEFINES += QMEDIA_GSTREAMER_PLAYER

HEADERS += \
    $$PWD/qgstreamerplayercontrol.h \
    $$PWD/qgstreamerplayerservice.h \
    $$PWD/qgstreamerplayersession.h \
    $$PWD/qgstreamerstreamscontrol.h \
    $$PWD/qgstreamermetadataprovider.h \
    $$PWD/qgstreameravailabilitycontrol.h

SOURCES += \
    $$PWD/qgstreamerplayercontrol.cpp \
    $$PWD/qgstreamerplayerservice.cpp \
    $$PWD/qgstreamerplayersession.cpp \
    $$PWD/qgstreamerstreamscontrol.cpp \
    $$PWD/qgstreamermetadataprovider.cpp \
    $$PWD/qgstreameravailabilitycontrol.cpp


