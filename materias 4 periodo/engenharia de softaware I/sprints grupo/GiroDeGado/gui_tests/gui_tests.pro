QT       += core gui widgets testlib sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

LIBS += -L$$PWD/../bin/api/debug -lapi
LIBS += -L$$PWD/../bin/api/release -lapi
LIBS += -L$$PWD/../bin/api/ -lapi

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../gui/entity/cattlebirthscreen.cpp \
    ../gui/entity/cattlebuyscreen.cpp \
    ../gui/entity/cattleconsultscreen.cpp \
    ../gui/entity/cattleeditscreen.cpp \
    ../gui/entity/cattlemanagementscreen.cpp \
    ../gui/entity/cattleregisterscreen.cpp \
    ../gui/entity/cattleremovescreen.cpp \
    ../gui/entity/financialconsultscreen.cpp \
    ../gui/entity/financialmanagementscreen.cpp \
    ../gui/entity/financialrecordscreen.cpp \
    ../gui/entity/financialremovescreen.cpp \
    ../gui/entity/homescreen.cpp \
    ../gui/entity/loginscreen.cpp \
    ../gui/entity/reportscreen.cpp \
    ../gui/entity/signupscreen.cpp \
    ../gui/entity/usereditscreen.cpp \
    ../gui/entity/usermanagementscreen.cpp \
    ../gui/entity/userqueryscreen.cpp \
    ../gui/entity/userremovescreen.cpp \
    main.cpp \
    test/unit/cattle_birth_unit_test.cpp \
    test/unit/cattle_buy_unit_test.cpp \
    test/unit/cattle_consult_unit_test.cpp \
    test/unit/cattle_edit_unit_test.cpp \
    test/unit/cattle_management_unit_test.cpp \
    test/unit/cattle_register_unit_test.cpp \
    test/unit/cattle_remove_unit_test.cpp \
    test/unit/financial_consult_unit_test.cpp \
    test/unit/financial_management_unit_test.cpp \
    test/unit/financial_record_unit_test.cpp \
    test/unit/financial_remove_unit_test.cpp \
    test/unit/home_unit_test.cpp \
    test/unit/login_unit_test.cpp \
    test/unit/report_unit_test.cpp \
    test/unit/signup_unit_test.cpp \
    test/unit/user_consult_unit_test.cpp \
    test/unit/user_edit_unit_test.cpp \
    test/unit/user_management_unit_test.cpp \
    test/unit/user_remove_unit_test.cpp

HEADERS += \
    ../gui/entity/cattlebirthscreen.h \
    ../gui/entity/cattlebuyscreen.h \
    ../gui/entity/cattleconsultscreen.h \
    ../gui/entity/cattleeditscreen.h \
    ../gui/entity/cattlemanagementscreen.h \
    ../gui/entity/cattleregisterscreen.h \
    ../gui/entity/cattleremovescreen.h \
    ../gui/entity/financialconsultscreen.h \
    ../gui/entity/financialmanagementscreen.h \
    ../gui/entity/financialrecordscreen.h \
    ../gui/entity/financialremovescreen.h \
    ../gui/entity/homescreen.h \
    ../gui/entity/loginscreen.h \
    ../gui/entity/reportscreen.h \
    ../gui/entity/signupscreen.h \
    ../gui/entity/usereditscreen.h \
    ../gui/entity/usermanagementscreen.h \
    ../gui/entity/userqueryscreen.h \
    ../gui/entity/userremovescreen.h \
    lib_global.h

FORMS += \
    ../gui/views/cattlebirthscreen.ui \
    ../gui/views/cattlebuyscreen.ui \
    ../gui/views/cattleconsultscreen.ui \
    ../gui/views/cattleeditscreen.ui \
    ../gui/views/cattlemanagementscreen.ui \
    ../gui/views/cattleregisterscreen.ui \
    ../gui/views/cattleremovescreen.ui \
    ../gui/views/financialconsultscreen.ui \
    ../gui/views/financialmanagementscreen.ui \
    ../gui/views/financialrecordscreen.ui \
    ../gui/views/financialremovescreen.ui \
    ../gui/views/homescreen.ui \
    ../gui/views/loginscreen.ui \
    ../gui/views/reportscreen.ui \
    ../gui/views/signupscreen.ui \
    ../gui/views/usereditscreen.ui \
    ../gui/views/usermanagementscreen.ui \
    ../gui/views/userqueryscreen.ui \
    ../gui/views/userremovescreen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    bd_giro_tests.db
