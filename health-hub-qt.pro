QT += charts

INCLUDEPATH += $$PWD/include

HEADERS += \
    ./include/controller.h

SOURCES += \
    ./src/model.cpp \
    ./src/view.cpp \
    ./src/main.cpp \
    ./src/ads1015.cpp \
    ./src/controller.cpp \

target.path = $$[QT_INSTALL_EXAMPLES]/charts/linechart
INSTALLS += target
