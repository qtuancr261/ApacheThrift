TEMPLATE = app
CONFIG += console c++
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp
LIBS += -lboost_system \
        -lboost_filesystem \
        -lboost_date_time

unix:!macx: LIBS += -L$$PWD/../../../../../zaloBackendCpp/svn_xallocatorlib/xallocatorlib/lib/ -lxallocator

INCLUDEPATH += $$PWD/../../../../../zaloBackendCpp/svn_xallocatorlib/xallocatorlib/inc/xallocator
DEPENDPATH += $$PWD/../../../../../zaloBackendCpp/svn_xallocatorlib/xallocatorlib/inc/xallocator

unix:!macx: PRE_TARGETDEPS += $$PWD/../../../../../zaloBackendCpp/svn_xallocatorlib/xallocatorlib/lib/libxallocator.a
