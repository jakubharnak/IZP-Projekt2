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

int pocetKrokov = 0;

// 2.poduloha
bool getBit(unsigned char byte, int p)
{
     for (int i = 2; i >= 0; i--) {
        int b = byte >> i;
        if ( i == p )  {
			if (b & 1)
				return true;
			else
				return false;
        }
    }
     return false;
}

bool isborder(Map map, int r, int c, int border) {
	//if border 0 kontrolujeme lavu hranicu
	//if border 1 kontrolujeme pravu hranicu
	//if border 2 kontrolujeme hornu
	//if border 3 kontrolujeme dolnu
	int cellValue = map.cells[(r-1)*map.cols+(c-1)];
	if (border > 2) {
		return getBit(cellValue,2);
	} else {
		return getBit(cellValue,border);
	}


}

void next_border(Map map, int r, int c, int leftright, int from) {

	int first = -1;
	int second = -1;
	int third = -1;

	if (from == 1) {
		if (c % 2 == 0 && r % 2 == 0) {
			first = 1;
			second = 2;
			third = 0;
		} else if (c % 2 == 0 && r % 2 == 1) {
			first = 3;
			second = 1;
			third = 0;
		} else if (c % 2 == 1 && r % 2 == 0) {
			first = 3;
			second = 1;
			third = 0;
		} else if (c % 2 == 1 && r % 2 == 1) {
			first = 1;
			second = 2;
			third = 0;
		}
	} else if (from == 0) {
		if (c % 2 == 0 && r % 2 == 0) {
			first = 2;
			second = 0;
			third = 1;
		} else if (c % 2 == 0 && r % 2 == 1) {
			first = 0;
			second = 3;
			third = 1;
		} else if (c % 2 == 1 && r % 2 == 0) {
			first = 2;
			second = 1;
			third = 0;
		} else if (c % 2 == 1 && r % 2 == 1) {
			first = 2;
			second = 0;
			third = 1;
		}
	} else if (from == 3) {
		if (c % 2 == 0 && r % 2 == 0) {
			first = 0;
			second = 1;
			third = 2;
		} else if (c % 2 == 0 && r % 2 == 1) {
			first = 0;
			second = 1;
			third = 2;
		} else if (c % 2 == 1 && r % 2 == 0) {
			first = 0;
			second = 1;
			third = 2;
		} else if (c % 2 == 1 && r % 2 == 1) {
			first = 0;
			second = 1;
			third = 2;
		}
	} else if (from == 2) {
		if (c % 2 == 0 && r % 2 == 0) {
			first = 1;
			second = 0;
			third = 3;
		} else if (c % 2 == 0 && r % 2 == 1) {
			first = 1;
			second = 0;
			third = 3;
		} else if (c % 2 == 1 && r % 2 == 0) {
			first = 1;
			second = 0;
			third = 3;
		} else if (c % 2 == 1 && r % 2 == 1) {
			first = 1;
			second = 0;
			third = 3;
		}
	}
	//fprintf(stderr,"%d,%d - %d - %d %d %d\n",r,c,from, first, second, third);

	int nextRow = r;
	int nextCol = c;

	int fromNext = -1;

	bool isBorder = isborder(map, r, c, first);
	if (isBorder == true) {
		isBorder = isborder(map, r, c, second);
		if (isBorder == true) {
			isBorder = isborder(map, r, c, third);
			if (isBorder == true) {
			} else  {
				//fprintf(stderr,"third %d\n",third);
				fromNext = third;
				if (third == 0) {
					nextCol = nextCol - 1;
				} else if (third == 1) {
					nextCol = nextCol + 1;
				} else if (third == 2) {
					nextRow = nextRow - 1;
				} else {
					nextRow = nextRow + 1;
				}
			}
		} else  {
			//fprintf(stderr,"second %d\n",second);
			fromNext = second;
			if (second == 0) {
				nextCol = nextCol - 1;
			} else if (second == 1) {
				nextCol = nextCol + 1;
			} else if (second == 2) {
				nextRow = nextRow - 1;
			} else {
				nextRow = nextRow + 1;
			}
		}
	} else {
		//fprintf(stderr,"first %d\n",first);
		fromNext = first;
		if (first == 0) {
			nextCol = nextCol - 1;
		} else if (first == 1) {
			nextCol = nextCol + 1;
		} else if (first == 2) {
			nextRow = nextRow - 1;
		} else {
			nextRow = nextRow + 1;
		}
	}
	if (nextRow < 1 || nextCol < 1 || nextRow > map.rows || nextCol > map.cols || (r == nextRow && c == nextCol)) {
		//fprintf(stderr,"Koniec dalsieho hladania");
	} else {
		pocetKrokov = pocetKrokov + 1;
		fprintf(stderr,"%d,%d\n",nextRow, nextCol);
		//if (pocetKrokov < 25) {
			next_border(map,nextRow,nextCol,leftright,fromNext);
		//} else {

		//}
	}
}


//3.poduloha
void start_border(Map map, int r, int c, int leftright) {
	//leftRight = 1 pre vyhladavanie podla pravej ruky
	//leftRight = 0 pre vyhladavanie podla lavej ruky;

	int nextRow = r;
	int nextCol = c;

	int from = -1;

	if (r % 2 == 1) {
		//fprintf(stderr, "Neparny riadok\n");
		if (c % 2 == 1)  {
			//fprintf(stderr, "Neparny stlpec\n");
			bool isBorder = isborder(map, r, c, 2);
			if (isBorder == true) {
				//fprintf(stderr, "Dole je hranica\n");
				isBorder = isborder(map, r, c, 0);
				if (isBorder == true) {
					//fprintf(stderr, "Vpravo je hranica\n");
					isBorder = isborder(map, r, c, 1);
					if (isBorder == true) {
						//fprintf(stderr, "Bunka je uzavreta\n");
					} else  {
						//fprintf(stderr, "Ideme vlavo\n");
						nextCol = nextCol-1;
					}
				} else  {
					//fprintf(stderr, "Ideme vpravo\n");
					nextCol = nextCol + 1;
				}
			} else  {
				//fprintf(stderr, "Ideme dole\n");
				nextRow = nextRow+1;
			}
		} else  {
			//fprintf(stderr, "Parny stlpec\n");
			bool isBorder = isborder(map, r, c, 1);
			if (isBorder == true) {
				//fprintf(stderr, "Vpravo je hranica\n");
				isBorder = isborder(map, r, c, 0);
				if (isBorder == true) {
					//fprintf(stderr, "Vlavo je hranica\n");
					isBorder = isborder(map, r, c, 2);
					if (isBorder == true) {
						//fprintf(stderr, "Bunka je uzavreta\n");
					} else  {
						//fprintf(stderr, "Ideme dole\n");
						nextRow = nextRow + 1;
					}
				} else  {
					//fprintf(stderr, "Ideme vlavo\n");
					nextCol = nextCol - 1;
				}
			} else  {
				//fprintf(stderr, "Ideme vpravo\n");
				nextCol = nextCol + 1;
			}
		}
	} else {
		//fprintf(stderr, "Parny riadok\n");
		if (c % 2 == 1)  {
			//fprintf(stderr, "Neparny stlpec\n");
			bool isBorder = isborder(map, r, c, 2);
			if (isBorder == true) {
				//fprintf(stderr, "Dole je hranica\n");
				isBorder = isborder(map, r, c, 1);
				if (isBorder == true) {
					//fprintf(stderr, "Vpravo je hranica\n");
					isBorder = isborder(map, r, c, 0);
					if (isBorder == true) {
						//fprintf(stderr, "Bunka je uzavreta\n");
					} else  {
						//fprintf(stderr, "Ideme vlavo\n");
						nextRow = nextRow-1;
					}
				} else  {
					//fprintf(stderr, "Ideme vpravo\n");
					nextCol = nextCol + 1;
					from = 1;
				}
			} else  {
				//fprintf(stderr, "Ideme dole\n");
				nextRow = nextRow+1;
			}
		} else  {
			//fprintf(stderr, "Parny stlpec\n");
			bool isBorder = isborder(map, r, c, 1);
			if (isBorder == true) {
				//fprintf(stderr, "Vpravo je hranica\n");
				isBorder = isborder(map, r, c, 2);
				if (isBorder == true) {
					//fprintf(stderr, "Hore je hranica\n");
					isBorder = isborder(map, r, c, 0);
					if (isBorder == true) {
						//fprintf(stderr, "Bunka je uzavreta\n");
					} else  {
						//fprintf(stderr, "Ideme vlavo\n");
						nextCol = nextCol-1;
					}
				} else  {
					//fprintf(stderr, "Ideme hore\n");
					nextRow = nextRow - 1;
				}
			} else  {
				//fprintf(stderr, "Ideme vparvo\n");
				nextCol = nextCol+1;
			}
		}
	}
	if (nextRow < 1 || nextCol < 1 || nextRow > map.rows || nextCol > map.cols || (r == nextRow && c == nextCol)) {
		//fprintf(stderr,"Koniec hladania");
	} else {
		pocetKrokov = pocetKrokov + 1;
		fprintf(stderr,"%d,%d\n",nextRow, nextCol);
		next_border(map,nextRow,nextCol,leftright,from);
	}
}

int getMapValue(Map *map, int r, int c) {
	return map->cells[(r-1)*map->cols+c];
}

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
        	int charakter;
            if (fscanf(file, "%d",&charakter) != 1) {
                fprintf(stderr, "Chyba nacitani bunky mapy na pozici [%d, %d]\n", i, j);
                free(map->cells);
                fclose(file);
                exit(EXIT_FAILURE);
            } else {
            	map->cells[i * map->cols + j] = (char)charakter;
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

void findPathR(Map map, int startRow, int startCol) {
	fprintf(stderr,"%d,%d\n",startRow, startCol);
	start_border(map, startRow, startCol, 1);
}

void findPathL(Map map, int startRow, int startCol) {
	fprintf(stderr,"%d,%d\n",startRow, startCol);
	start_border(map, startRow, startCol, 0);
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <options>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Map map;

    if (strcmp(argv[1], "--help") == 0) {

        printf("Usage: %s --help | --test <filename> | --rpath <row> <col> <filename> | --lpath <row> <col> <filename> | --shortest <row> <col> <filename>\n", argv[0]);
    } else if (strcmp(argv[1], "--test") == 0) {

        if (argc != 3) {
            fprintf(stderr, "Invalid number of arguments for --test\n");
            return EXIT_FAILURE;
        }
        loadMap(&map, argv[2]);

        printf("Valid\n");
        freeMap(&map);
    } else if (strcmp(argv[1], "--rpath") == 0 || strcmp(argv[1], "--lpath") == 0) {
        if (argc != 5) {
            fprintf(stderr, "Invalid number of arguments for %s\n",argv[1]);
            return EXIT_FAILURE;
        }
        loadMap(&map, argv[4]);
        if (strcmp(argv[1], "--rpath") == 0) {
        	findPathR(map, atoi(argv[2]), atoi(argv[3]));
        } else {
        	findPathL(map, (int)argv[2], (int)argv[3]);
        }
    }  else {
        fprintf(stderr, "Invalid option: %s\n", argv[1]);
        return 1;
    }

    return 0;
}