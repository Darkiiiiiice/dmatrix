#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int random_int(int min, int max) {

    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    srand(ts.tv_nsec);
    return rand() % (max - min + 1) + min;
}

char **init_matrix(int row, int col) {
    char **matrix = calloc(col, sizeof(char) * col);
    for (int i = 0; i < col; i++) {
        matrix[i] = calloc(row, sizeof(char) * row);
    }
    return matrix;
}

void moveline(char *line, int size) {
    for (int i = size - 1; i > 0; i--) {
        line[i] = line[i - 1];
    }
}

int main(int argc, char **argv) {
    int row, col;
    char ch;

    initscr();
    getmaxyx(stdscr, row, col);
    curs_set(0);
    refresh();

    char **matrix = init_matrix(row, col);

    while (true) {
        for (int i = 0; i < col; i+=2) {
            char *line = matrix[i];

            moveline(line, row);
            int show = random_int(0, 2);
            if (show == 0) {
                char ch = (char) random_int(33, 126);
                line[0] = ch;
            } else {
                line[0] = ' ';
            }


            for (int j = 0; j < row; j++)
                mvprintw(j, i, "%c", line[j]);
            refresh();
        }


        refresh();
        napms(6 * 10);
    }

    endwin();
    return 0;
}
