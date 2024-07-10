#ifndef UTILS_H
#define UTILS_H

#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
#include <filesystem>
#include <QDir>
namespace fs = std::filesystem;

bool isAddressDirectory(const QString& path);     // 判断是否为文件夹
std::vector<std::string> get_image_files(const std::string& directory);

#endif // UTILS_H
