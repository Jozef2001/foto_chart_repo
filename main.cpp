/////////////////////////////////////////////////////////////////////////////////
// ASPENsoft
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <gtkmm.h>

#include "wykres.h"

int main(int argc, char *argv[]) 
{   
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");
    auto screen = Gdk::Screen::get_default();
    Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create_from_file("wykres.glade");
    wykres_win* hw;
    refBuilder->get_widget_derived("window", hw);
    app->run(*hw);
    
    return 0;
}
