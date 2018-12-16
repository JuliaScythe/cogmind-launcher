#include <iostream>
#include <gtkmm.h>

#include "LauncherWindow.h"
#include "CogmindLauncher.h"

void loadStyles();

int main(int argc, char** argv) {

    auto launcher = CogmindLauncher();

    auto app = Gtk::Application::create(argc, argv, "com.kernelpanic.cogmind.lanucher");

    Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("res/glade/mockup.glade");

    Gtk::Window* window = nullptr;

    builder->get_widget("Cogmind Launcher", window);

    loadStyles();

    connectWindow(builder, &launcher);

    return app -> run(*window);
}

void loadStyles() {
    auto screen = Gdk::Screen::get_default();
    auto provider = Gtk::CssProvider::create();
    auto context = Gtk::StyleContext::create();

    provider->load_from_path("res/css/main.css");

    context->add_provider_for_screen(screen, provider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}
