#include "euler.h"

int score_word(char* word);
int main(int argc, char** argv);

int score_word(char* word) {
    int score = 0;
    for (int i = 0; i < strlen(word); ++i)
        score += word[i] - 64;
    return score;
}

int main(int argc, char** argv) {
    char word_buf[30];
    FILE *datafile = fopen("e42.dat","r");
    char c = fgetc(datafile);
    int i = 0, count = 0;
    int score;
    while (c != EOF) {
        if (c == ',') {
            word_buf[i] = '\0';
            score = score_word(word_buf);
            if (is_triangular(score)) {
                printf("%s is triangle\n", word_buf);
                ++count;
            }
            i = 0;
        }
        else if (c != '\"')
            word_buf[i++] = c;
        c = fgetc(datafile);
    }
    fclose(datafile);
    printf("%d triangle words found\n", count);
    return 0;
}
