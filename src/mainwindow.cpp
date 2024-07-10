#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QString>
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <QPixmap>
#include <QImage>
#include <QDebug>
#include <QThread>
#include <memory>
#include <QDir>
#include "src/utils.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->resize(QSize(1920, 1080));
    this->setWindowTitle("YOLOV8 Detect System");
    this->setMinimumSize(QSize(1200, 800));

    QObject::connect(ui->pushButton_start,        &QPushButton::clicked, this, &MainWindow::runDet);
    QObject::connect(ui->pushButton_end,          &QPushButton::clicked, this, &MainWindow::stopDet);
    QObject::connect(ui->pushButton_selectedFile, &QPushButton::clicked, this, &MainWindow::openSelectFile);

    mkDir(picSavePath);

}

MainWindow::~MainWindow()
{

    delete ui;
    if (yolov8)
        delete yolov8;
}

void MainWindow::mkDir(QString picSavePath){

    QDir dir(picSavePath);
    if (!dir.exists())
        dir.mkdir(picSavePath);
}

void MainWindow::runDet(){

    ui->pushButton_end->setEnabled(true);
    ui->pushButton_start->setEnabled(false);
    ui->comboBox_detType->setEnabled(false);
    ui->comboBox_model->setEnabled(false);
    ui->pushButton_selectedFile->setEnabled(false);

    QString enginepath;
    if (ui->comboBox_model->currentIndex() == 0) {  // s
        enginepath = modelDir + "yolov8s.engine";
    }else if (ui->comboBox_model->currentIndex() == 1){  // m
        enginepath = modelDir + "yolov8m.engine";
    }else if (ui->comboBox_model->currentIndex() == 2){  // x
        enginepath = modelDir + "yolov8x.engine";
    }

    yolov8 = new cudaYolov8(enginepath.toStdString(), classPath.toStdString());

    if (ui->comboBox_detType->currentIndex() == 0)
    {
        // img
        cv::Mat img = cv::imread(ui->lineEdit->text().toStdString());
        if (!img.empty())
        {
            inferAndShowResult(img);

            size_t found = ui->lineEdit->text().toStdString().find_last_of("/\\");

            auto path = ui->lineEdit->text().toStdString();
            std::string filename = (found != std::string::npos) ? path.substr(found + 1) : path;
            QString save_ = picSavePath + "//" +  QString::fromStdString(filename);
            qDebug() <<save_;
            cv::cvtColor(img, img, cv::COLOR_RGB2BGR);
            cv::imwrite(save_.toStdString(), img);
        }else{
            ui->textEdit->append("image Path is error, image read is error!!!");
            stopDet();
        }

    }
    else if (ui->comboBox_detType->currentIndex() == 1)
    {
         // imgs
        if (isAddressDirectory(ui->lineEdit->text())){
            auto t_beg = std::chrono::high_resolution_clock::now();

            size_t found = ui->lineEdit->text().toStdString().find_last_of("/\\");

            auto path = ui->lineEdit->text().toStdString();
            std::string filename = (found != std::string::npos) ? path.substr(found + 1) : path;
            QString saveImgsPath = picSavePath + "//" +  QString::fromStdString(filename);

            mkDir(saveImgsPath);

            std::string imgsPath = ui->lineEdit->text().toStdString();
            std::vector<std::string> image_files = get_image_files(imgsPath);

            ui->textEdit->append("图片数量:" + QString::number(image_files.size()));
            int num = 0;
            int fileNums = image_files.size();

            isStopDet = false;
            while (char(cv::waitKey(1) != 27)) {

                if (num >= fileNums)
                    break;

                if (isStopDet)   // 手动停止
                    break;

                cv::Mat img = cv::imread(imgsPath + "//" + image_files.at(num));
                inferAndShowResult(img);

                cv::cvtColor(img, img, cv::COLOR_RGB2BGR);
                cv::imwrite(saveImgsPath.toStdString() + "//" + image_files.at(num) , img);
                num++;
            }

            auto t_end = std::chrono::high_resolution_clock::now();
            float total_inf = std::chrono::duration<float, std::milli>(t_end - t_beg).count();
            std::cout << "Inference time: " << int(total_inf) / 1000 << "s" << std::endl;
        }else{
            ui->textEdit->append("imageFile Path is error!!!");
            stopDet();
        }
    }else if (ui->comboBox_detType->currentIndex() == 2)
    {
        auto t_beg = std::chrono::high_resolution_clock::now();

        // video
        cv::Mat img;

        std::string videoPath = ui->lineEdit->text().toStdString();
        cv::VideoCapture test;
        if (test.open(videoPath)) { // 尝试打开视频文件
            cv::VideoCapture cap(ui->lineEdit->text().toStdString());
            isStopDet = false;

            while (char(cv::waitKey(1) != 27)) {
                cap >> img;
                if (isStopDet)
                    break;
                inferAndShowResult(img);
            }
            auto t_end = std::chrono::high_resolution_clock::now();
            float total_inf = std::chrono::duration<float, std::milli>(t_end - t_beg).count();
            std::cout << "Inference time: " << int(total_inf) / 1000 << "s" << std::endl;

        }else{
            ui->textEdit->append("video Path is error!!!");
            stopDet();
        }

    }else {

        //  capture
        cv::Mat img;
        cv::VideoCapture cap(0);

        isStopDet = false;
        while (char(cv::waitKey(1) != 27)) {
            cap >> img;
            if (isStopDet)
                break;
            inferAndShowResult(img);
        }
    }

    delete yolov8;
    yolov8 = nullptr;
}

void MainWindow::inferAndShowResult(cv::Mat & img){
    int epstime = yolov8->Inference(img);
    ui->textEdit->append(QString("cost Time: %1 ms").arg(epstime));

    cv::cvtColor(img, img, cv::COLOR_BGR2RGB);
    QImage rawImage = QImage((uchar*)(img.data),img.cols,img.rows,img.step,QImage::Format_RGB888);
    QImage resizedImage = rawImage.scaled(ui->label_pic->width(), ui->label_pic->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_pic->setPixmap(QPixmap::fromImage(resizedImage));
}

void MainWindow::stopDet(){

    ui->pushButton_start->setEnabled(true);
    ui->comboBox_detType->setEnabled(true);
    ui->comboBox_model->setEnabled(true);
    ui->pushButton_selectedFile->setEnabled(true);

    isStopDet = true;
    ui->pushButton_end->setEnabled(false);
}

void MainWindow::on_comboBox_detType_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        ui->pushButton_selectedFile->setEnabled(true);
        break;
    case 1:
        ui->pushButton_selectedFile->setEnabled(true);
        break;
    case 2:
        ui->pushButton_selectedFile->setEnabled(true);
        break;
    case 3:
        ui->pushButton_selectedFile->setEnabled(false);
        break;
    default:
        break;
    }

}

void MainWindow::openSelectFile(){

    QString fileType = "All Files (*);;Text Files (*.txt)" ;

    int type = 0;
    if (ui->comboBox_detType->currentIndex() == 0)   // 单张图
    {
        fileType = "Image Files (*.png *.jpg *.jpeg)";
        type = 0;
    }
    else if (ui->comboBox_detType->currentIndex() == 1){  // 文件夹

        type = 1;

    }else if (ui->comboBox_detType->currentIndex() == 2){
        fileType = "Video files (*.mp4 *.avi *.mov *.mkv)" ; // 视频
        type = 2;
    }

    QString selectedFile;

    if (type == 1){
        selectedFile = QFileDialog::getExistingDirectory(
            this,                  // 父窗口
            u8"选择文件夹_",          // 对话框标题
            "./",                  // 起始目录，默认为当前工作目录
            QFileDialog::ShowDirsOnly  // 选项，仅显示文件夹
            );
    }else {
        selectedFile  = QFileDialog::getOpenFileName(
            this,                  // 父窗口
            "选择文件",           // 对话框标题
            ".",                   // 起始目录，默认为当前工作目录
            fileType  // 文件过滤器
            );
    }
    if (!selectedFile.isEmpty()) {
        ui->lineEdit->setText(selectedFile);
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    isStopDet = true; // 关闭程序时，退出循环，释放内存
}


