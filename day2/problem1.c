#include <stdio.h>

char buf[10];
int sum;

int get_points(char a, char b) {
    int shape_points = 0;
    int outcome_points = 0;
    switch (b) {
        case 'X': {
            shape_points = 1; 
            if (a == 'A') outcome_points = 3;
            else if (a == 'C') outcome_points = 6;
        } break;

        case 'Y': {
            shape_points = 2; 
            if (a == 'B') outcome_points = 3;
            else if (a == 'A') outcome_points = 6;
        } break;

        case 'Z': {
            shape_points = 3; 
            if (a == 'C') outcome_points = 3;
            else if (a == 'B') outcome_points = 6;
        } break;
    }

    return shape_points + outcome_points;
}

int main() {
    while(fgets(buf, sizeof(buf), stdin)) {
        sum += get_points(buf[0], buf[2]);
    }
    printf("Total score: %d\n", sum);
}