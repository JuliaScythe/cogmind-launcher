//
// Created by jake on 13/12/18.
//

#include "LauncherWindow.h"
#include "CogmindLauncher.h"

void connectWindow(Glib::RefPtr<Gtk::Builder> builder, CogmindLauncher* launcher) {
    Gtk::Button* button;
    builder->get_widget("launchButton", button);

    button->signal_clicked().connect(sigc::mem_fun(launcher, &CogmindLauncher::launchGame));

    builder->get_widget("cogmindDirectoryButton", button);
    button->signal_clicked().connect(sigc::mem_fun(launcher, &CogmindLauncher::openCogmindDirectory));

    builder->get_widget("screenshotsDirectoryButton", button);
    button->signal_clicked().connect(sigc::mem_fun(launcher, &CogmindLauncher::openScreenshotsDirectory));
}
