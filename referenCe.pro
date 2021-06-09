QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    customstring.cpp \
    dashboardpage.cpp \
    loginpage.cpp \
    main.cpp \
    mainwindow.cpp \
    pagearrays.cpp \
    pageclass.cpp \
    pagedatatypes.cpp \
    pagedynamicmemory.cpp \
    pagefunctions.cpp \
    pagehome.cpp \
    pageifstatement.cpp \
    pageinheritance.cpp \
    pageinputoutput.cpp \
    pagelibmath.cpp \
    pagelibstdio.cpp \
    pagelibstdlib.cpp \
    pagelibstring.cpp \
    pagelibtime.cpp \
    pagelooping.cpp \
    pagemissing.cpp \
    pagemodular.cpp \
    pageoperators.cpp \
    pagepointers.cpp \
    pagestrings.cpp \
    pagestructures.cpp \
    pageswitchcasestatement.cpp \
    pagetextfilehandling.cpp \
    pagetry.cpp \
    quizpage.cpp \
    referencepage.cpp

HEADERS += \
    customstring.h \
    dashboardpage.h \
    dictionary.h \
    loginpage.h \
    mainwindow.h \
    pagearrays.h \
    pageclass.h \
    pagedatatypes.h \
    pagedynamicmemory.h \
    pagefunctions.h \
    pagehome.h \
    pageifstatement.h \
    pageinheritance.h \
    pageinputoutput.h \
    pagelibmath.h \
    pagelibstdio.h \
    pagelibstdlib.h \
    pagelibstring.h \
    pagelibtime.h \
    pagelooping.h \
    pagemissing.h \
    pagemodular.h \
    pageoperators.h \
    pagepointers.h \
    pagestrings.h \
    pagestructures.h \
    pageswitchcasestatement.h \
    pagetextfilehandling.h \
    pagetry.h \
    quizpage.h \
    referencepage.h

FORMS += \
    dashboardpage.ui \
    loginpage.ui \
    mainwindow.ui \
    quizpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
