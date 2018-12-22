//
// Created by jake on 16/12/18.
//

#ifndef COGMINDLAUNCHER_COGMINDLAUNCHER_H
#define COGMINDLAUNCHER_COGMINDLAUNCHER_H

#include <string>
#include <libconfig.h++>

// This is instantiated at launch, and serves as the "model" and "controller" in the MVC model
// All signals connect to functions in instances of this class
class CogmindLauncher {
public:
    CogmindLauncher();
    ~CogmindLauncher() = default;

    void launchGame();
    void openCogmindDirectory();
    void openScreenshotsDirectory();
    void openManual();

    const std::string getGameVersion();

    const std::string getLatestVersion();

private:
    std::string cogmindBaseDirectory;

    libconfig::Config configurationManager;

    bool fileExists(const std::string file);


};


#endif //COGMINDLAUNCHER_COGMINDLAUNCHER_H
