QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adddebtorsform.cpp \
    adduserform.cpp \
    debtorsaddedform.cpp \
    getusersform.cpp \
    main.cpp \
    mainwindow.cpp \
    resultform.cpp \
    utils.cpp

HEADERS += \
    adddebtorsform.h \
    adduserform.h \
    constants.h \
    debtorsaddedform.h \
    getusersform.h \
    mainwindow.h \
    resultform.h \
    utils.h

FORMS += \
    adddebtorsform.ui \
    adduserform.ui \
    debtorsaddedform.ui \
    getusersform.ui \
    mainwindow.ui \
    resultform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
