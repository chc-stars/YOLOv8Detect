#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <string.h>
#include "3rd/cudaYolov8/include/cudaYolov8.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    enum class detType{
        image = 0,   // det Pic
        images = 1,   // det Pics (files)
        video = 2,     // det Video
        camera = 3,     // det Camera
    };
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


protected slots:
    void runDet();
    void stopDet();

    void openSelectFile();


protected:
    void closeEvent(QCloseEvent *event) override;


    void inferAndShowResult(cv::Mat &img);
    void mkDir(QString picSavePath);
private slots:
    void on_comboBox_detType_currentIndexChanged(int index);


private:
    Ui::MainWindow *ui;
    cudaYolov8 *yolov8 = nullptr;

    QString modelDir = "E:/CODE/QT/Ours/objectDet/YOLOV8Detect/weights/";
    QString classPath = "E:/CODE/QT/Ours/objectDet/YOLOV8Detect/weights/classes.txt";

    QString picSavePath = "E:/CODE/QT/Ours/objectDet/YOLOV8Detect/output";

    bool isStopDet = false; // 运行状态

};
#endif // MAINWINDOW_H
