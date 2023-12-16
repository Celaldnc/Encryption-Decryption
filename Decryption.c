#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void metniDosyadanOku(char dosyaYolu[], char metin[]);
void writetext(char dosyaAdi[], char icerik[]);
void caesarCipher(char *Text, int key);

int main(void) {
    int key =3;
    char Text[1001];

    metniDosyadanOku("unencrypted.txt", Text);

    caesarCipher(Text, key);
    writetext("encrypted.txt", Text);

    return 0;
}

void metniDosyadanOku(char dosyaYolu[], char metin[]) {
    FILE *dosya = fopen(dosyaYolu, "r");
    fgets(metin,1000, dosya);

    fclose(dosya);
}

void writetext(char dosyaAdi[], char icerik[]) {
    FILE *dosya = fopen(dosyaAdi, "w");

    fprintf(dosya, "%s", icerik);

    fclose(dosya);
}

void caesarCipher(char *plainText, int key) {
    int i = 0;
    int cypherValue;
    char cypher;
    while (plainText[i] != '\0' && strlen(plainText) - 1 > i) {
        if (plainText[i] >= 'a' && plainText[i] <= 'z') {
            cypherValue = ((int)plainText[i] - 'a' + key + 26 ) % 26 + 'a';
            cypher = (char)(cypherValue);
            plainText[i] = cypher;
        } else if (plainText[i] >= 'A' && plainText[i] <= 'Z') {
            cypherValue = ((int)plainText[i] - 'A' + key + 26 ) % 26 + 'A';
            cypher = (char)(cypherValue);
            plainText[i] = cypher;
        } else {
            // If the character is not a letter, leave it as is
        }
        i++;
    }
}
