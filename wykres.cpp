#include "wykres.h"

wykres_win::wykres_win(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder) : Gtk::Window(cobject), ui(refBuilder)
{
    if(ui)
    {   

        set_title("wykres danych fotometru");
        ui->get_widget("window", window);
        ui->get_widget("wykres_image", wykres_image);
        

        // przyklad
        std::vector<std::vector<std::vector<float>>> data;
        std::vector<std::vector<float>> single_data;
        
        //jeden pomiar 
        std::vector<float> data_kat;
        std::vector<float> data_promien;
        //generowanie polkola z prawej strony
        for(int i = 0; i <= 180; i += 5)
        {
            data_kat.push_back(i);
            data_promien.push_back(200 + (std::rand() % 30));
        }
        single_data.push_back(data_kat);
        single_data.push_back(data_promien);
        data.push_back(single_data);

        //drugi pomiar 
        std::vector<float> data_kat_2;
        std::vector<float> data_promien_2;
        //generowanie polkola z lewej strony
        for(int i = 0; i <= 180; i += 5)
        {
            data_kat_2.push_back(i - (2*i));
            data_promien_2.push_back(600 + (std::rand() % 40));
        }
        single_data.clear();
        single_data.push_back(data_kat_2);
        single_data.push_back(data_promien_2);
        data.push_back(single_data);

        std::vector<std::string> data_names = {"p_1", "p_2"};

        draw_foto_chart(data, data_names);

        show_all_children();
    }
    else
    {
        std::cerr << "ERROR>ustawienia: blad 'wykres.glade'" << std::endl;
    }
}

wykres_win::~wykres_win()
{
}

// dodatnie wartosci katow po prawej stronie wykresu 
// ujemne po lewej
// podany bedzie kat i promien
// trzeba przeliczyc promien na wartosci x i y, zeby narysowac na wykresie
void wykres_win::draw_foto_chart(std::vector<std::vector<std::vector<float>>> data, std::vector<std::string> data_names) {
    // Rysowanie okręgów
    for (float r = 250; r <= 1000.0; r += 250) {
        std::vector<float> cx, cy;
        for (float theta = 0.0; theta < 2 * M_PI; theta += 0.01) {
            cx.push_back(r * cos(theta));
            cy.push_back(r * sin(theta));
        }
        plt::plot(cx, cy, {{"color", "lightgray"}, {"linestyle", "dotted"}});
    }

    // Rysowanie oznaczeń kątów w prawej półkuli
    for (float angle = 0; angle <= 180; angle += 15) {
        float rad = angle * M_PI / 180.0;
        float x_text = 1000 * sin(rad); // Use sin for x
        float y_text = -1000 * cos(rad); // Use -cos for y to place 0 at the bottom
        plt::text(x_text, y_text, std::to_string(static_cast<int>(angle))); // Convert angle to int for full degrees

        // rysowanie linii promieniujących
        if(angle != 90.0 && angle != 0 && angle != 180) {
            plt::plot(std::vector<float>{0, x_text}, std::vector<float>{0, y_text}, {{"color", "lightgray"}, {"linestyle", "dotted"}});
        }
    }

    // Rysowanie oznaczeń kątów zgodnie ze wskazówkami zegara
    for (float angle = 0; angle < 180; angle += 15) {
        float rad = angle * M_PI / 180.0;
        float x_text = 1000 * sin(-rad); // Use sin for x with -rad to go clockwise
        float y_text = -1000 * cos(-rad); // Use cos for y with -rad to go clockwise
        plt::text(x_text, y_text, std::to_string(static_cast<int>(angle))); // Convert angle to int for full degrees

        // rysowanie linii promieniujących
        if(angle != 90.0 && angle != 0) {
            plt::plot(std::vector<float>{0, x_text}, std::vector<float>{0, y_text}, {{"color", "lightgray"}, {"linestyle", "dotted"}});
        }
    }

    // Ustawienia osi
    plt::xlim(-1000, 1000);
    plt::ylim(-1000, 1000);

    // Ustawienie własnych wartości na osiach
    std::vector<float> x_ticks = {-1000, -750, -500, -250, 0, 250, 500, 750, 1000};
    std::vector<float> y_ticks = {-1000, -750, -500, -250, 0, 250, 500, 750, 1000};
    std::vector<std::string> x_labels = {"1000", "750", "500", "250", "0", "250", "500", "750", "1000"};
    std::vector<std::string> y_labels = {"1000", "750", "500", "250", "0", "250", "500", "750", "1000"};

    plt::xticks(x_ticks, x_labels);
    plt::yticks(y_ticks, y_labels);

    // Rysowanie osi
    plt::plot(std::vector<float>{-1000, 1000}, std::vector<float>{0, 0}, "k-");
    plt::plot(std::vector<float>{0, 0}, std::vector<float>{-1000, 1000}, "k-");

    // Dodanie strzałek do osi X
    plt::plot(std::vector<float>{950, 1000}, std::vector<float>{10, 0}, "k-");
    plt::plot(std::vector<float>{950, 1000}, std::vector<float>{-10, 0}, "k-");
    plt::plot(std::vector<float>{-950, -1000}, std::vector<float>{10, 0}, "k-");
    plt::plot(std::vector<float>{-950, -1000}, std::vector<float>{-10, 0}, "k-");

    // Dodanie strzałek do osi Y
    plt::plot(std::vector<float>{-10, 0}, std::vector<float>{950, 1000}, "k-");
    plt::plot(std::vector<float>{10, 0}, std::vector<float>{950, 1000}, "k-");
    plt::plot(std::vector<float>{-10, 0}, std::vector<float>{-950, -1000}, "k-");
    plt::plot(std::vector<float>{10, 0}, std::vector<float>{-950, -1000}, "k-");

    // dodanie podzialek na osiach 
    // X
    plt::plot(std::vector<float>{250, 250}, std::vector<float>{-15, 15}, "k-");
    plt::plot(std::vector<float>{500, 500}, std::vector<float>{-15, 15}, "k-");
    plt::plot(std::vector<float>{750, 750}, std::vector<float>{-15, 15}, "k-");
    plt::plot(std::vector<float>{-250, -250}, std::vector<float>{-15, 15}, "k-");
    plt::plot(std::vector<float>{-500, -500}, std::vector<float>{-15, 15}, "k-");
    plt::plot(std::vector<float>{-750, -750}, std::vector<float>{-15, 15}, "k-");
    // Y
    plt::plot(std::vector<float>{-15, 15}, std::vector<float>{-250, -250}, "k-");
    plt::plot(std::vector<float>{-15, 15}, std::vector<float>{-500, -500}, "k-");
    plt::plot(std::vector<float>{-15, 15}, std::vector<float>{-750, -750}, "k-");
    plt::plot(std::vector<float>{-15, 15}, std::vector<float>{250, 250}, "k-");
    plt::plot(std::vector<float>{-15, 15}, std::vector<float>{500, 500}, "k-");
    plt::plot(std::vector<float>{-15, 15}, std::vector<float>{750, 750}, "k-");

    

    for(size_t i = 0; i < data.size(); i++) {
        // Przeliczenie wartości kątów i promieni na współrzędne x i y
        std::vector<float> angles = data[i][0]; // kąty
        std::vector<float> radii = data[i][1];  // promienie
        std::vector<float> x_coords, y_coords;

        for(size_t j = 0; j < angles.size(); j++) {
            float theta = (angles[j] + 90.0) * M_PI / 180.0; // Przesunięcie kątów, aby 0 stopni było na dole
            float x = radii[j] * cos(theta);
            float y = radii[j] * sin(theta);

            x_coords.push_back(-x); // Dodatnie kąty - prawa strona osi y
            y_coords.push_back(-y);
        }

        // Rysowanie danych
        plt::plot(x_coords, y_coords, {{"label", data_names[i]}});
    }
    
    plt::legend({{"loc", "upper right"}});


    // Wyświetlenie wykresu
    plt::save("./wykres.png");

    // Wyświetlenie wykresu w Image w gtkmm
    wykres_image->set("./wykres.png");
}