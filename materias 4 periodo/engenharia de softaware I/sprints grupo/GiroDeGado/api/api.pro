QT       += core sql
QT       -= gui

TEMPLATE = lib
DEFINES += LIB_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    lib/cattleImpl.cpp \
    lib/farmImpl.cpp \
    lib/transactionImpl.cpp \
    lib/userImpl.cpp \
    test/functional/functional_tests.cpp \
    test/functional/main_functional_test.cpp \
    test/unit/main_unit_test.cpp \
    test/unit/unit_cattle.cpp \
    test/unit/unit_farm.cpp \
    test/unit/unit_transaction.cpp \
    test/unit/unit_user.cpp

HEADERS += \
    includes/cattle.h \
    includes/cattleImpl.h \
    includes/farm.h \
    includes/farmImpl.h \
    includes/handlebody.h \
    includes/transaction.h \
    includes/transactionImpl.h \
    includes/user.h \
    includes/userImpl.h \
    lib_global.h \
    test/functional/functional_tests.h \
    test/functional/main_functional_test.h \
    test/unit/main_unit_test.h \
    test/unit/unit_cattle.h \
    test/unit/unit_farm.h \
    test/unit/unit_transaction.h \
    test/unit/unit_user.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
