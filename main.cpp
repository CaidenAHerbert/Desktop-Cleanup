//
// Created by Caiden Herbert on 5/21/24.
//

#include "File.h"
#include <iostream>
#include <filesystem>
#include <cstdlib>



int main() {
    File fileManager;

    //setting desktop folder
    std::string desktopPath = std::string(getenv("HOME")) + "/Desktop";

    //setting screenshot folder
    std::string screenshotPath = std::string(getenv("HOME")) + "/Screenshot";

    //run program with desired folders
    fileManager.screenshotManagement(desktopPath, screenshotPath);

    return 0;
}