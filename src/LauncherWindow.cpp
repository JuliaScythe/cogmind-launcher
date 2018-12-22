//
// Created by jake on 13/12/18.
//

#include "LauncherWindow.h"
#include "CogmindLauncher.h"
#include <iostream>

void connectWindow(Glib::RefPtr<Gtk::Builder> builder, CogmindLauncher* launcher) {

    Gtk::Button* button;

    builder->get_widget("launchButton", button);
    button->signal_clicked().connect(sigc::mem_fun(launcher, &CogmindLauncher::launchGame));

    builder->get_widget("cogmindDirectoryButton", button);
    button->signal_clicked().connect(sigc::mem_fun(launcher, &CogmindLauncher::openCogmindDirectory));

    builder->get_widget("screenshotsDirectoryButton", button);
    button->signal_clicked().connect(sigc::mem_fun(launcher, &CogmindLauncher::openScreenshotsDirectory));

    builder->get_widget("openManualButton", button);
    button->signal_clicked().connect(sigc::mem_fun(launcher, &CogmindLauncher::openManual));

    updateStatsInformation(builder, launcher);
}

/**
 * This function updates the statistics panel of the ui with the latest version information.
 * Should be called at startup, and whenever a state change is applied
 * @param builder
 * The builder for the application to update the stats for. Must have the appropriate ui features.
 * @param launcher
 * The backend application to get the latest version information from.
 *
 * Why did I spend part of my life writing this
 */
void updateStatsInformation(Glib::RefPtr<Gtk::Builder> builder, CogmindLauncher* launcher) {
    Gtk::Label* label;

    builder->get_widget("gameVersionLabel", label);

    auto version = launcher->getGameVersion();
    auto networkVersion = launcher->getLatestVersion();

    label->set_text(version);

    builder->get_widget("remoteVersionLabel", label);
    label->set_text(networkVersion);
}
