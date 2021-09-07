QT       += core sql
QT       -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG -= app_bundle

LIBS += -L$$PWD/../bin/api/debug -lapi
LIBS += -L$$PWD/../bin/api/release -lapi
LIBS += -L$$PWD/../bin/api/ -lapi

SOURCES += \
    main.cpp

HEADERS += \
    ../api/test/functional/main_functional_test.h \
    ../api/test/unit/main_unit_test.h \
    lib_global.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    bd_giro_tests.db
