QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        errors.cpp \
        framequeue.cpp \
        helper.cpp \
        main.cpp \
        video.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += $$PWD/include

DEPENDPATH += $$PWD/include

LIBS += $$PWD/lib/libavcodec.dll.a \
        $$PWD/lib/libavdevice.dll.a \
        $$PWD/lib/libavfilter.dll.a \
        $$PWD/lib/libavformat.dll.a \
        $$PWD/lib/libavutil.dll.a \
        $$PWD/lib/libswresample.dll.a \
        $$PWD/lib/libswscale.dll.a \
        $$PWD/lib/libpostproc.dll.a \
        $$PWD/lib/libSDL2.a \
        $$PWD/lib/libSDL2.dll.a \
        $$PWD/lib/libSDL2_test.a \
        $$PWD/lib/libSDL2main.a \

HEADERS += \
    errors.h \
    framequeue.h \
    helper.h \
    video.h
