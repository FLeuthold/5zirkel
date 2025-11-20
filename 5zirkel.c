#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// liest genau ein Zeichen
char prompt_read_char(const char* message) {
    printf("%s", message);
    char buffer[64];
    if (!fgets(buffer, sizeof(buffer), stdin)) {
        fprintf(stderr, "Input failed\n");
        exit(1);
    }
    size_t len = strlen(buffer);
    if (len == 0 || (len == 1 && buffer[0] == '\n')) {
        fprintf(stderr, "Expected a single character\n");
        exit(1);
    }
    // erstes Zeichen, ignoriert evtl. newline
    char c = buffer[0];
    if (len > 2 || (len == 2 && buffer[1] != '\n')) {
        fprintf(stderr, "Expected a single character\n");
        exit(1);
    }
    return c;
}

// liest eine ganze Zahl (nur Ziffern, optional führendes '-')
int prompt_read_int(const char* message) {
    printf("%s", message);
    char buffer[128];
    if (scanf("%127s", buffer) != 1) {
        fprintf(stderr, "Input failed\n");
        exit(1);
    }
    int neg = 0;
    int acc = 0;
    for (size_t i = 0; i < strlen(buffer); ++i) {
        char c = buffer[i];
        if (i == 0 && c == '-') {
            neg = 1;
            continue;
        }
        if (c < '0' || c > '9') {
            fprintf(stderr, "not an integer\n");
            exit(1);
        }
        acc = acc * 10 + (c - '0');
    }
    return neg ? -acc : acc;
}

int main(void) {
    char ton = 'c';
    int mode = 0; // 0 = dur/ionisch, 1 = dorisch, ...
    int halb = 0;

    ton = prompt_read_char("Stammton \n c, d, e, f, g, a oder b \n"
        "(ja, h geht nicht, bitte b...) \n"
        "bitte kleinbuchstabe \n ohne 'is' oder 'es'\n :");
    if (ton < 'a' || ton > 'g') {
        printf("ton nicht verfügbar\n");
        return 2;
    }

    mode = prompt_read_int("mode \n 0 = dur/ionisch \n 1 = dorisch \n 2 = phrygisch \n"
        " 3 = lydisch \n 4 = mixolydisch \n 5 = moll/aeolisch \n 6 = lokrisch \n : ");
    if (mode < 0 || mode > 6) {
        printf("modus nicht verfügbar\n");
        return 3;
    }

    halb = prompt_read_int("um wieviele halbtöne erhöhen \n"
        "(vertiefen ist einfach negativ erhöhen)\n:");

    int wurst = 2 * ((ton - 1) % 7);
    wurst -= (int)(wurst > 4);
    wurst += halb - (2 * mode);
    wurst += (int)(mode > 2);
    wurst += 12 * (int)(wurst < 0);
    wurst = (wurst + 6 * (int)(wurst % 2 != 0)) % 12;

    printf("kreuz: %d b: %d\n", wurst, 12 - wurst);
    return 0;
}
