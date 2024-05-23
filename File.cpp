//
// Created by Caiden Herbert on 5/21/24.
//

#include <filesystem>
#include "File.h"
#include <iostream>

// Use the file system namespace
namespace fs = std::__fs::filesystem;

void File::screenshotManagement(const std::string& sourceFolder, const std::string& destinationFolder) {

    // Create the destination folder if it does not already exist
    if (!fs::exists(destinationFolder)) {
        fs::create_directory(destinationFolder);
    }

    //Iterates through the files in the source folder
    for (const auto& entry : fs::directory_iterator(sourceFolder)) {
        std::string filePath = entry.path().string();
        std::string fileName = entry.path().filename().string();

        //if file name begins with screenshot, moves the file into destination folder
        if (fileName.substr(0, 10) == "Screenshot") {

            //creates destination path
            std::string destPath = destinationFolder + "/" + fileName;

            //moves the file to destination folder
            try {
                fs::rename(filePath, destPath);
                std::cout << "Moved: " << fileName << std::endl;
            } catch (fs::filesystem_error& e) { //if error in process
                std::cerr << "Error moving file: " << e.what() << std::endl;
            }
        }
    }

    std::cout << "Screenshot management complete." << std::endl;

}