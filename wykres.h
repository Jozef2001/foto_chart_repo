#pragma once

#include <iostream>
#include <gtkmm.h>
#include <vector>
#include <cmath>
#include <tuple>
#include <map>
#include "matplotlibcpp.h"

namespace plt = matplotlibcpp;

class wykres_win : public Gtk::Window
{
private:
    Glib::RefPtr<Gtk::Builder> ui;
    Gtk::Window *window;
    Gtk::Image *wykres_image;
    
public:
    wykres_win(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);
    ~wykres_win();

    //wektor<wektor<dane_kat, dane_promien>, wektor<dane_kat1, dane_promien1>, wektor<dane_kat2, dane_promien2>>
    //dane_katn, dane_promienn to rowniez wektory (floatow)
    void draw_foto_chart(std::vector<std::vector<std::vector<float>>>, std::vector<std::string> data_names);

};

