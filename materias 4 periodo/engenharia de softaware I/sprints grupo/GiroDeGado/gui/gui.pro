QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

LIBS += -L$$PWD/../bin/api/debug -lapi
LIBS += -L$$PWD/../bin/api/release -lapi
LIBS += -L$$PWD/../bin/api/ -lapi

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    entity/cattlebirthscreen.cpp \
    entity/cattlebuyscreen.cpp \
    entity/cattleconsultscreen.cpp \
    entity/cattleeditscreen.cpp \
    entity/cattlemanagementscreen.cpp \
    entity/cattleregisterscreen.cpp \
    entity/cattleremovescreen.cpp \
    entity/financialconsultscreen.cpp \
    entity/financialmanagementscreen.cpp \
    entity/financialrecordscreen.cpp \
    entity/financialremovescreen.cpp \
    entity/homescreen.cpp \
    entity/loginscreen.cpp \
    entity/reportscreen.cpp \
    entity/signupscreen.cpp \
    entity/userqueryscreen.cpp \
    entity/userremovescreen.cpp \
    entity/usereditscreen.cpp \
    entity/usermanagementscreen.cpp \
    main.cpp

HEADERS += \
    ../api/includes/cattle.h \
    ../api/includes/cattleImpl.h \
    ../api/includes/farm.h \
    ../api/includes/farmImpl.h \
    ../api/includes/handlebody.h \
    ../api/includes/transaction.h \
    ../api/includes/transactionImpl.h \
    ../api/includes/user.h \
    ../api/includes/userImpl.h \
    ../api/test/unit/main_unit_test.h \
    entity/cattlebirthscreen.h \
    entity/cattlebuyscreen.h \
    entity/cattleconsultscreen.h \
    entity/cattleeditscreen.h \
    entity/cattlemanagementscreen.h \
    entity/cattleregisterscreen.h \
    entity/cattleremovescreen.h \
    entity/financialconsultscreen.h \
    entity/financialmanagementscreen.h \
    entity/financialrecordscreen.h \
    entity/financialremovescreen.h \
    entity/homescreen.h \
    entity/loginscreen.h \
    entity/reportscreen.h \
    entity/signupscreen.h \
    entity/userqueryscreen.h \
    entity/userremovescreen.h \
    entity/usereditscreen.h \
    entity/usermanagementscreen.h \
    lib_global.h

FORMS += \
    views/cattlebirthscreen.ui \
    views/cattlebuyscreen.ui \
    views/cattleconsultscreen.ui \
    views/cattleeditscreen.ui \
    views/cattlemanagementscreen.ui \
    views/cattleregisterscreen.ui \
    views/cattleremovescreen.ui \
    views/financialconsultscreen.ui \
    views/financialmanagementscreen.ui \
    views/financialrecordscreen.ui \
    views/financialremovescreen.ui \
    views/homescreen.ui \
    views/loginscreen.ui \
    views/reportscreen.ui \
    views/userqueryscreen.ui \
    views/userremovescreen.ui \
    views/usereditscreen.ui \    
    views/signupscreen.ui \
    views/usermanagementscreen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    bd_giro.db
