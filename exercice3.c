#include <allegro5/allegro.h>            // Core Allegro functions
#include <allegro5/allegro_primitives.h> // For drawing shapes (rectangle, circle, triangle, etc.)
#include <stdio.h>

// Fonction pour dessiner la matrice de morpion 3x3 avec les bords fermés
void draw_tic_tac_toe_grid(int x, int y, int cell_size)
{
}

int main()
{
    // Initialiser Allegro et les add-ons
    if (!al_init())
    {
        fprintf(stderr, "Erreur : Impossible d'initialiser Allegro.\n");
        return -1;
    }
    al_init_primitives_addon(); // Initialise les primitives Allegro

    // Crée la fenêtre d'affichage
    ALLEGRO_DISPLAY *display = al_create_display(640, 480);
    if (!display)
    {
        fprintf(stderr, "Erreur : Impossible de créer l'affichage.\n");
        return -1;
    }

    // Efface l'écran
    al_clear_to_color(al_map_rgb(0, 0, 0)); // Fond noir

    // Dessiner la matrice de morpion (3x3)
    int cell_size = 100;                        // Taille des cellules du morpion
    draw_tic_tac_toe_grid(220, 140, cell_size); // Dessine la grille 3x3 à la position (220, 140)

    // Met à jour l'affichage
    al_flip_display();

    // Attendre 5 secondes avant de fermer
    al_rest(5.0);

    // Détruire l'affichage
    al_destroy_display(display);

    return 0;
}
