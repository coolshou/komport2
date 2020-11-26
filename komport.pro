# -------------------------------------------------
# Project created by QtCreator 2011-02-09T06:45:33
# -------------------------------------------------
QT += core \
    gui
greaterThan(QT_MAJOR_VERSION, 4) {
    QT       += widgets
}


TARGET = komport
TEMPLATE = app


unix{
    QMAKE_CXXFLAGS_RELEASE += -g
    QMAKE_CFLAGS_RELEASE += -g
    QMAKE_CXXFLAGS_RELEASE -= -O2
    QMAKE_CFLAGS_RELEASE -= -O2
    QMAKE_LFLAGS_RELEASE =
    target.path += /usr/bin
    INSTALLS += target
}

SOURCES += src/main.cpp \
    src/komport.cpp \
    src/cserial.cpp \
    src/cdevicelock.cpp \
    src/ccharcell.cpp \
    src/ccellarray.cpp \
    src/cscreen.cpp \
    src/cemulation.cpp \
    src/cemulationVT102.cpp

HEADERS += src/komport.h \
    src/cserial.h \
    src/cdevicelock.h \
    src/ccharcell.h \
    src/ccellarray.h \
    src/cscreen.h \
    src/cemulation.h \
    src/cemulationVT102.h \
    src/cemulationVT102.h

win32{
    SOURCES +=  \
        src/Win32Serial.cpp

    HEADERS +=  \
        src/Win32Serial.h
}

FORMS += src/komport.ui \
    src/settingsdialog.ui

RESOURCES += komport.qrc

OTHER_FILES += README.TXT \
    EMULATION.TXT \
    Komport.iss
