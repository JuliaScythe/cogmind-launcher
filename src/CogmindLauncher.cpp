//
// Created by jake on 16/12/18.
//

#include "CogmindLauncher.h"
#include <iostream>
#include <libconfig.h++>
#include <sys/stat.h>
#include <cstdlib>
#include <fstream>
#include <boost/filesystem.hpp>

CogmindLauncher::CogmindLauncher() : configurationManager(libconfig::Config()) {
    std::cout << "Cogmind Launcher v0.1" << std::endl;

    std::string configRoot = "/.config/CogmindLauncher/";
    std::string configFile = "settings.cfg";

    std::string configPath = getenv("HOME") + configRoot + configFile;
    std::string configDirectory = getenv("HOME") + configRoot;

    if (!fileExists(configPath)) {

        // Create the directories leading up to the config file
        boost::filesystem::create_directories(configDirectory);

        // Create the actual config file
        std::ofstream outfile (configPath);
        outfile.close();

    }

    configurationManager.readFile(configPath.c_str());
    try {
        cogmindBaseDirectory = (std::string) configurationManager.lookup("cogmindDirectory");
    } catch (libconfig::SettingNotFoundException& e) {
        cogmindBaseDirectory = configDirectory + "cogmind/";
        configurationManager.getRoot().add("cogmindDirectory", libconfig::Setting::TypeString);
        configurationManager.lookup("cogmindDirectory") = cogmindBaseDirectory;
        configurationManager.writeFile(configPath.c_str());
    } // ew


}

bool CogmindLauncher::fileExists(const std::string file) {
    std::ifstream f(file.c_str());
    return f.good();
}

void CogmindLauncher::launchGame() {
    system(std::string("cd " + cogmindBaseDirectory + "&& wine COGMIND.exe &").c_str());
}

void CogmindLauncher::openCogmindDirectory() {
    system(std::string("xdg-open file://" + cogmindBaseDirectory + " &").c_str());
}

void CogmindLauncher::openScreenshotsDirectory() {
    system(std::string("xdg-open file://" + cogmindBaseDirectory + "screenshots/ &").c_str());
}

void CogmindLauncher::openManual() {
    system(std::string("xdg-open " + cogmindBaseDirectory + "manual.txt &").c_str());
}

const std::string CogmindLauncher::getGameVersion() {
    return "";
}
