QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    src/mainwindow.cpp \
    src/utils.cpp

HEADERS += \
    src/mainwindow.h \
    src/utils.h


FORMS += \
    src/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/3rd/tensorrt/lib/release/ -lnvinfer
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/3rd/tensorrt/lib/debug/ -lnvinfer

INCLUDEPATH += $$PWD/3rd/tensorrt/include
DEPENDPATH += $$PWD/3rd/tensorrt/include

INCLUDEPATH += "C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\v11.8\include"  # cuda_runtime_api.h


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/3rd/opencv455/lib/release/ -lopencv_world455
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/3rd/opencv455/lib/debug/ -lopencv_world455d

INCLUDEPATH += $$PWD/3rd/opencv455/include
DEPENDPATH += $$PWD/3rd/opencv455/include

RESOURCES += \
    image.qrc


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/3rd/cudaYolov8/lib/release/ -lcudaYolov8
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/3rd/cudaYolov8/lib/debug/ -lcudaYolov8

INCLUDEPATH += $$PWD/3rd/cudaYolov8/include
DEPENDPATH += $$PWD/3rd/cudaYolov8/include
