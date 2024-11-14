#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h> // For drawing shapes (rectangle, circle, triangle, etc.)
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <stdio.h>
#include <stdbool.h>

ALLEGRO_DISPLAY *menu_display;

int main()
{
    // variables
    bool is_text_visible = false;

    // Initialiser Allegro et les add-ons
    al_init();                                                          // Initialise la bibliothèque Allegro
    al_install_mouse();                                                 // Installe la gestion de la souris
    ALLEGRO_DISPLAY *display = al_create_display(640, 480);             // Crée la fenêtre d'affichage
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();         // Crée une file d'événements
    al_register_event_source(event_queue, al_get_mouse_event_source()); // Enregistre les événements de souris
    if (!display)
    {
        fprintf(stderr, "Erreur : Impossible de créer l’affichage.\n");
        return -1;
    }

    // Charger la police de caractères
    ALLEGRO_FONT *font = al_create_builtin_font();
    if (!font)
    {
        fprintf(stderr, "Erreur : Impossible de charger la police.\n");
        return -1;
    }

    double start_time = 0; // Temps de début pour le chronomètre

    while (true)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        // Vérifie si un clic de souris a eu lieu
        if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            if (ev.mouse.button == 1)
            {
                is_text_visible = !is_text_visible;
                start_time = al_get_time(); // Démarre ou redémarre le chronomètre
            }
        }

        // Efface l'écran
        al_clear_to_color(al_map_rgb(0, 0, 0));

        // Affiche du texte si is_text_visible est vrai
        if (is_text_visible)
        {
            al_draw_text(font, al_map_rgb(255, 255, 255), 320, 240, ALLEGRO_ALIGN_CENTRE, "Clic détecté !");
        }

        // ===========================
        // Code pour dessiner les formes géométriques ici
        // ===========================

        al_draw_filled_circle(320, 240, 50, al_map_rgb(255, 0, 0)); // Cercle rouge au centre

        // ===========================
        // Code pour dessiner les formes géométriques ici
        // ===========================

        // Met à jour l'affichage
        al_flip_display();

        // Si 10 secondes se sont écoulées, fermez la fenêtre
        if (al_get_time() - start_time > 10)
        {
            break; // Sort de la boucle
        }
    }

    // Détruire l'affichage et la file d'événements
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;
}
