// cd programming\GitHub\IZP-Projekt2\main
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void help_call(){
    printf("--test <filename.txt> | --rpath <row> <col> <filename.txt> | --lpath <row> <col> <filename.txt>\n");
}

// 1.poduloha
typedef struct {
    int rows;
    int cols;
    unsigned char *cells;
} Map;

bool fcheck(char *fname){
    FILE *file;
    file = fopen(fname, "r");

    if(file == NULL)
        return false;
    
    fclose(file);
    return true;
}

void loadMap(Map *map, const char *filename) {
    
}

bool mazetest(Map *map) {
    
}

bool mazetest_values(Map *map) {
    
}

// 2.poduloha
bool isborder(Map *map, int r, int c, int border) {}

// RETURN DOWNWARD trojuhelnik dolu
// RETURN UPWARD trojuhelnik nahoru
int orientation(int row, int col){}

// TRUE mozno vstoupit do blusdiste pres trojuhelnik [r; c]
// FALSE(1) mozno vstoupit a okamzite vystoupit (napise jenom vstupni souradnice)
// FALSE(2) nelze vstoupit
bool first_cell_checkup(Map map, int *r, int *c){}

//3.poduloha
int start_border(Map *map, int r, int c, int leftright);


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

    // Zpracování argumentů
    if ((strcmp(argv[1], "--help") == 0) && argc == 2) {
        // Vytiskněte nápovědu
        help_call();
    } else if ((strcmp(argv[1], "--test") == 0) && argc == 3) {
        // Testování, např. ./maze --test bludiste.txt
        if(fcheck(argv[2])){
            
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