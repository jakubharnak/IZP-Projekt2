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

void next_border(Map map, int r, int c, int from, int leftright) {
	if (r < 1 || r > map.rows || c < 1 || c > map.cols)  {
		return;
	}
	printf("%d,%d\n",r,c);
	//fprintf(stderr, "%d,%d     %d\n",r,c,from);
	int first = -1;
	int second = -1;
	int third = -1;

	if (((r%2 == 0)&& (c%2 == 1)) || ((r%2 == 1) && (c%2 == 0)))  {
		if (from == 0)  {
			if (leftright == 0) {
				first = 2;
				second = 1;
				third = 0;
			} else {
				first = 1;
				second = 2;
				third = 0;
			}
		} else if (from == 1)  {
			if (leftright == 0) {
				first = 0;
				second = 2;
				third = 1;
			} else {
				first = 2;
				second = 0;
				third = 1;
			}
		} else  {
			if (leftright == 0) {
				first = 1;
				second = 0;
				third = 2;
			} else {
				first = 0;
				second = 1;
				third = 2;
			}
		}
		bool isBorder = isborder(map, r, c, first);
		if (isBorder == true)  {
			bool isBorder = isborder(map, r, c, second);
			if (isBorder == true)  {
				bool isBorder = isborder(map, r, c, third);
				if (isBorder == true)  {
				} else  {
					int nextR = r;
					int nextC = c;
					if (third == 0) {
						nextC = c - 1;
					}
					if (third == 1) {
						nextC = c + 1;
					}
					if (third == 2) {
						nextR = r + 1;
					}
					int nextFrom = third;
					if (third == 0)  {
						nextFrom = 1;
					} else if (third == 1)  {
						nextFrom = 0;
					}
					//fprintf(stderr, "%d %d\n",third,nextFrom);
					next_border(map,nextR,nextC,nextFrom,leftright);
				}
			} else  {
				int nextR = r;
				int nextC = c;
				if (second == 0) {
					nextC = c - 1;
				}
				if (second == 1) {
					nextC = c + 1;
				}
				if (second == 2) {
					nextR = r + 1;
				}
				int nextFrom = second;
				if (second == 0)  {
					nextFrom = 1;
				} else if (second == 1)  {
					nextFrom = 0;
				}
				//fprintf(stderr, "%d %d\n",second,nextFrom);
				next_border(map,nextR,nextC,nextFrom,leftright);
			}
		} else  {
			int nextR = r;
			int nextC = c;
			if (first == 0) {
				nextC = c - 1;
			}
			if (first == 1) {
				nextC = c + 1;
			}
			if (first == 2) {
				nextR = r + 1;
			}
			int nextFrom = first;
			if (first == 0)  {
				nextFrom = 1;
			} else if (first == 1)  {
				nextFrom = 0;
			}
			//fprintf(stderr, "%d %d\n",first,nextFrom);
			next_border(map,nextR,nextC,nextFrom,leftright);
		}
	} else {
		if (from == 0)  {
			if (leftright == 1) {
				first = 2;
				second = 1;
				third = 0;
			} else {
				first = 1;
				second = 2;
				third = 0;
			}
		} else if (from == 1)  {
			if (leftright == 1) {
				first = 0;
				second = 2;
				third = 1;
			} else {
				first = 2;
				second = 0;
				third = 1;
			}
		} else  {
			if (leftright == 1) {
				first = 1;
				second = 0;
				third = 2;
			} else {
				first = 0;
				second = 1;
				third = 2;
			}
		}
		bool isBorder = isborder(map, r, c, first);
		if (isBorder == true)  {
			bool isBorder = isborder(map, r, c, second);
			if (isBorder == true)  {
				bool isBorder = isborder(map, r, c, third);
				if (isBorder == true)  {
				} else  {
					int nextR = r;
					int nextC = c;
					if (third == 0) {
						nextC = c - 1;
					}
					if (third == 1) {
						nextC = c + 1;
					}
					if (third == 2) {
						nextR = r - 1;
					}
					int nextFrom = third;
					if (third == 0)  {
						nextFrom = 1;
					} else if (third == 1)  {
						nextFrom = 0;
					}
					//fprintf(stderr, "%d %d\n",third,nextFrom);
					next_border(map,nextR,nextC,nextFrom,leftright);
				}
			} else  {
				int nextR = r;
				int nextC = c;
				if (second == 0) {
					nextC = c - 1;
				}
				if (second == 1) {
					nextC = c + 1;
				}
				if (second == 2) {
					nextR = r - 1;
				}
				int nextFrom = second;
				if (second == 0)  {
					nextFrom = 1;
				} else if (second == 1)  {
					nextFrom = 0;
				}
				//fprintf(stderr, "%d %d\n",second,nextFrom);
				next_border(map,nextR,nextC,nextFrom,leftright);
			}
		} else  {
			int nextR = r;
			int nextC = c;
			if (first == 0) {
				nextC = c - 1;
			}
			if (first == 1) {
				nextC = c + 1;
			}
			if (first == 2) {
				nextR = r - 1;
			}
			int nextFrom = first;
			if (first == 0)  {
				nextFrom = 1;
			} else if (first == 1)  {
				nextFrom = 0;
			}
			//fprintf(stderr, "%d %d\n",first,nextFrom);
			next_border(map,nextR,nextC,nextFrom,leftright);
		}
	}
}

int pocetKrokov = 0;

// 2.poduloha

//3.poduloha
void start_border(Map map, int r, int c, int leftright) {
	int from = 0;
	bool isBorder0 = isborder(map, r, c, 0);
	if (isBorder0 == false) {
		if (c-1 == 0)  {
			from = 0;
		}
	}
	bool isBorder1 = isborder(map, r, c, 1);
	if (isBorder1 == false) {
		if (c+1 > map.cols) {
			from = 1;
		}
	}
	bool isBorder2 = isborder(map, r, c, 2);
	if (isBorder2 == false) {
		if (r+1 > map.rows || r-1 == 0) {
			from = 2;
		}
	}

	next_border(map, r, c, from, leftright);
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
				fprintf(stderr,"Invalid\n");
                printf("Invalid\n");
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
	start_border(map,startRow,startCol,0);
}

void findPathL(Map map, int startRow, int startCol) {
	start_border(map,startRow,startCol,1);
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
        	findPathL(map, atoi(argv[2]), atoi(argv[3]));
        }
    }  else {
        fprintf(stderr, "Invalid option: %s\n", argv[1]);
        return 1;
    }

    return 0;
}