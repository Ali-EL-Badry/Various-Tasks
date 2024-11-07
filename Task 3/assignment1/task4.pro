QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Machine/CPU/Alu and Cu/Alu/Alu.cpp \
    Machine/CPU/Alu and Cu/Alu/Alu.cpp \
    Machine/CPU/Alu and Cu/Alu/Alu.cpp \
    Machine/CPU/Alu and Cu/Alu/Alu.cpp \
    Machine/CPU/Alu and Cu/Alu/Alu.cpp \
    Machine/CPU/Alu and Cu/Alu/Alu.cpp \
    Machine/CPU/Alu and Cu/Alu/Alu.cpp \
    Machine/CPU/Alu and Cu/Alu/Alu.cpp \
    Machine/CPU/Alu and Cu/CU/CU.cpp \
    Machine/CPU/Alu and Cu/CU/CU.cpp \
    Machine/CPU/Alu and Cu/CU/CU.cpp \
    Machine/CPU/Alu and Cu/CU/CU.cpp \
    Machine/CPU/Alu and Cu/CU/CU.cpp \
    Machine/CPU/Alu and Cu/CU/CU.cpp \
    Machine/CPU/Alu and Cu/CU/CU.cpp \
    Machine/CPU/Alu and Cu/CU/CU.cpp \
    Machine/CPU/CPU.cpp \
    Machine/CPU/Register/Register.cpp \
    Machine/Memory/Memory.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Machine/CPU/Alu and Cu/Alu/Alu.h \
    Machine/CPU/Alu and Cu/Alu/Alu.h \
    Machine/CPU/Alu and Cu/Alu/Alu.h \
    Machine/CPU/Alu and Cu/Alu/Alu.h \
    Machine/CPU/Alu and Cu/Alu/Alu.h \
    Machine/CPU/Alu and Cu/Alu/Alu.h \
    Machine/CPU/Alu and Cu/Alu/Alu.h \
    Machine/CPU/Alu and Cu/CU/CU.h \
    Machine/CPU/Alu and Cu/CU/CU.h \
    Machine/CPU/Alu and Cu/CU/CU.h \
    Machine/CPU/Alu and Cu/CU/CU.h \
    Machine/CPU/Alu and Cu/CU/CU.h \
    Machine/CPU/Alu and Cu/CU/CU.h \
    Machine/CPU/Alu and Cu/CU/CU.h \
    Machine/CPU/Alu and Cu/CU/CU.h \
    Machine/CPU/CPU.h \
    Machine/CPU/Register/Register.h \
    Machine/Memory/Memory.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
