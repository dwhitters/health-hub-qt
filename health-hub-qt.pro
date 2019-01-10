QT += charts

INCLUDEPATH += $$PWD/include

SOURCES += \
    ./src/model.cpp \
    ./src/view.cpp \
    ./src/main.cpp \
    ./src/ads1015.cpp \

target.path = $$[QT_INSTALL_EXAMPLES]/charts/linechart
INSTALLS += target
