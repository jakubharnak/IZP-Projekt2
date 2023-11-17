#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


// 1.poduloha
typedef struct {
    int rows;
    int cols;
    unsigned char *cells;
} Map;

// 2.poduloha
bool isborder(Map *map, int r, int c, int border) {
    
}

//3.poduloha
int start_border(Map *map, int r, int c, int leftright);


void loadMap(Map *map, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Chyba pri otvarani suboru\n");
        exit(EXIT_FAILURE);
    }

    // Nacitanie velkosti mapy
    if (fscanf(file, "%d %d", &map->rows, &map->cols) != 2) {
        fprintf(stderr, "Chyba nacitania velikosti mapy\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Alokace pamati pre bunky mapy
    map->cells = (unsigned char *)malloc(map->rows * map->cols * sizeof(unsigned char));
    if (map->cells == NULL) {
        fprintf(stderr, "Chyba pri alokacii pamati pro mapu\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Nacitanie hodnot jednotlivych buniek
    for (int i = 0; i < map->rows; i++) {
        for (int j = 0; j < map->cols; j++) {
            if (fscanf(file, "%s",&map->cells[i * map->cols + j]) != 1) {
                fprintf(stderr, "Chyba nacitani bunky mapy na pozici [%d, %d]\n", i, j);
                free(map->cells);
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(file);
}

// Uvolnenie pamati alokovanej pre mapu
void freeMap(Map *map) {
    if (map->cells != NULL) {
        free(map->cells);
        map->cells = NULL; 
    }
}

// Hledání cesty pravidlem pravé ruky
void findPathR(Map *map, int startRow, int startCol) {
    
}

// Hledání cesty pravidlem levé ruky
void findPathL(Map *map, int startRow, int startCol) {

}

// Hlavní funkce pro zpracování argumentů
int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <options>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Map map;
    int startRow, startCol;

    // Zpracování argumentů
    if (strcmp(argv[1], "--help") == 0) {
        // Vytiskněte nápovědu
        printf("Usage: %s --help | --test <filename> | --rpath <row> <col> <filename> | --lpath <row> <col> <filename> | --shortest <row> <col> <filename>\n", argv[0]);
    } else if (strcmp(argv[1], "--test") == 0) {
        // Testování, např. ./maze --test bludiste.txt
        if (argc != 3) {
            fprintf(stderr, "Invalid number of arguments for --test\n");
            return EXIT_FAILURE;
        }
        loadMap(&map, argv[2]);
        // Zde můžete přidat kontrolu validity mapy
        printf("Valid\n");
        freeMap(&map);
    }  else {
        fprintf(stderr, "Invalid option: %s\n", argv[1]);
        return 1;
    }

    return 0;
}