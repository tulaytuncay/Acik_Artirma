#include <stdio.h>
#include <stdlib.h>


// Açık artırma için struct tanımı
typedef struct {
    int mevcutTeklif;
} AcikArtirma;

// Açık artırmayı başlatan fonksiyon
void baslatAcikArtirma(AcikArtirma *oturum, int baslangicTeklif) {
    oturum->mevcutTeklif = baslangicTeklif;
}

// Yeni teklifi işleyen fonksiyon
int verilenTeklif(AcikArtirma *oturum, int yeniTeklif) {
    if (yeniTeklif > oturum->mevcutTeklif) {
        oturum->mevcutTeklif = yeniTeklif;
        return 1; // Başarılı teklif
    }
    return 0; // Başarısız teklif
}

// Ana fonksiyon
int main() {
    AcikArtirma ilk_AcikArtirma;
    int baslangicTeklif, teklif;

    printf("Acik artirmanin baslangic teklifini girin: ");
    scanf("%d", &baslangicTeklif);
    baslatAcikArtirma(&ilk_AcikArtirma, baslangicTeklif);

    do {
        printf("Yeni teklif girin (teklifi bitirmek icin -1 girin): ");
        scanf("%d", &teklif);

        if (teklif != -1 && !verilenTeklif(&ilk_AcikArtirma, teklif)) {
            printf("Teklif, mevcut en yuksek tekliften yuksek olmalidir.\n");
        }
    } while (teklif != -1);

    printf("Acik artirma sona erdi. Kazanan teklif: %d\n", ilk_AcikArtirma.mevcutTeklif);
    return 0;
}
