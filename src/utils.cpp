#include "src/utils.h"
#include <iostream>
#include <QDebug>


std::vector<std::string> get_image_files(const std::string& directory) {
    std::vector<std::string> image_files;
    std::vector<std::string> image_extensions = {".jpg", ".jpeg", ".png", ".gif", ".bmp", ".tiff"};

    for (const auto& entry : fs::directory_iterator(directory)) {

        if (entry.is_regular_file()) {
            std::string extension = entry.path().extension().string();
            for (auto& c : extension) c = tolower(c); // 将扩展名转换为小写
            if (std::find(image_extensions.begin(), image_extensions.end(), extension) != image_extensions.end()) {
                image_files.push_back(entry.path().filename().string());
            }
        }
    }

    return image_files;
}


bool isAddressDirectory(const QString& path) {
    if (path == "")
        return false;
    QDir dir(path);
    return dir.exists();
}

