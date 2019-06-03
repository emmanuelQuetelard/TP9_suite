TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    message.cpp \
    publicmessage.cpp \
    privatemessage.cpp \
    date.cpp \
    user.cpp \
    system.cpp

HEADERS += \
    date.h \
    message.h \
    publicmessage.h \
    user.h \
    privatemessage.h \
    system.h
