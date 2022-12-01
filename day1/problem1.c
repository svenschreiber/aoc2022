#include <stdio.h>

#define N 10000
unsigned int calories[N];
unsigned int max[3];

void check_new_max(unsigned int val) {
    if (val > max[0]) {
        max[2] = max[1];
        max[1] = max[0];
        max[0] = val;
    } else if (val > max[1]) {
        max[2] = max[1];
        max[1] = val;
    } else if (val > max[2]) {
        max[2] = val;
    }
}

int main() {
    int elf_idx = 0;
    unsigned int cal;
    char buf[10];
    while(fgets(buf, sizeof(buf), stdin)) {
        if (sscanf(buf, "%u", &cal) == 1) {
            calories[elf_idx] += cal;
        } else if (buf[0] == '\n') {
            check_new_max(calories[elf_idx]);
            elf_idx++;
        }
    }
    
    unsigned int sum = 0;
    printf("Top 3:\n");
    for (int i = 0; i < 3; i++) {
        sum += max[i];
        printf("%d. %u\n", i + 1, max[i]);
    }
    printf("Sum: %u\n", sum);
}