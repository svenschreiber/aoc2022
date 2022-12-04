#include <stdio.h>

char buf[10];
int sum;

char get_play(char a, char b) {
    switch (b) {
        case 'X': {
            if (a == 'A') return 'C';
            if (a == 'B') return 'A';
            if (a == 'C') return 'B';
        }
        case 'Y': {
            return a;
        }
        case 'Z': {
            if (a == 'A') return 'B';
            if (a == 'B') return 'C';
            if (a == 'C') return 'A';
        }
    }
}

int get_points(char a, char b) {
    int shape_points = 0;
    int outcome_points = 0;
    switch (b) {
        case 'A': {
            shape_points = 1; 
            if (a == 'A') outcome_points = 3;
            else if (a == 'C') outcome_points = 6;
        } break;

        case 'B': {
            shape_points = 2; 
            if (a == 'B') outcome_points = 3;
            else if (a == 'A') outcome_points = 6;
        } break;

        case 'C': {
            shape_points = 3; 
            if (a == 'C') outcome_points = 3;
            else if (a == 'B') outcome_points = 6;
        } break;
    }

    return shape_points + outcome_points;
}

int main() {
    while(fgets(buf, sizeof(buf), stdin)) {
        char b = get_play(buf[0], buf[2]);
        sum += get_points(buf[0], b);
    }
    printf("Total score: %d\n", sum);
}