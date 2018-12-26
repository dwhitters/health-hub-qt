QT += charts

INCLUDEPATH += $$PWD/include

SOURCES += \
    ./src/model.cpp \
    ./src/view.cpp \
    ./src/main.cpp \

target.path = $$[QT_INSTALL_EXAMPLES]/charts/linechart
INSTALLS += target
