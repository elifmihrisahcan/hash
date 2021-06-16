#include <iostream>
using namespace std;
//diger kodun icerisinde yorum satiri bulundugu icin buradaki comment'leri sildim, ayni kod
//repl.it ile calistirildi
//vscode ile calistirildi.
class hashDugum
{
public:
    int anahtar;
    hashDugum *pSonraki;
    hashDugum(int anahtar)
    {
        this->anahtar = anahtar;
        pSonraki = NULL;
    }
};

class hashTable
{
public:
    int elemanSayisi;
    hashDugum *table[10];

    hashTable()
    {
        elemanSayisi = 0;
        for (int i = 0; i < 10; i++)
            table[i] = NULL;
    }
    void elemanlariGoster()
    {
        if (elemanSayisi > 0)
        {
            for (int i = 0; i < 10; i++)
            {
                hashDugum *pGecici = table[i];
                while (pGecici != NULL)
                {
                    cout << pGecici->anahtar << endl;
                    pGecici = pGecici->pSonraki;
                }
            }
        }
        else
            cout << "*** Tabloda eleman yok BOSTUR ***" << endl;
    }

    void ekle(int anahtar)
    {
        hashDugum *node = new hashDugum(anahtar);
        int mod = anahtar % 10;

        for (int i = 0; i < 10; i++)
        { // anahtarin kontrol edildigi
            hashDugum *pGecici = table[i];

            while (pGecici != NULL)
            {

                if (pGecici->anahtar == anahtar)
                {
                    cout << "***anahtar tabloda mevcut***" << endl;
                    return;
                }
                pGecici = pGecici->pSonraki;
            }
        }

        if (table[mod] == NULL)
        {
            table[mod] = node;
            cout << anahtar << " Tabloya Eklendi  " << endl;
            elemanSayisi++;
        }
        else
        {
            hashDugum *pGecici = table[mod];
            while (pGecici->pSonraki != NULL)
                pGecici = pGecici->pSonraki;
            pGecici->pSonraki = node;
            elemanSayisi++;
            cout << anahtar << " Tabloya Eklendi." << endl;
        }
    }

    void sil(int anahtar)
    {
        for (int i = 0; i < 10; i++)
        {
            hashDugum *Izleyen = NULL;
            hashDugum *TakipEden = NULL;

            if (table[i] != NULL)
            {
                Izleyen = table[i];
                TakipEden = Izleyen;

                while (Izleyen != NULL)
                {
                    if (Izleyen->anahtar == anahtar && Izleyen == table[i])
                    {
                        table[i] = table[i]->pSonraki;
                        elemanSayisi--;
                        cout << anahtar << " silindi" << endl;
                        return;
                    }
                    else if (Izleyen->anahtar == anahtar)
                    {
                        Izleyen = Izleyen->pSonraki;
                        TakipEden->pSonraki = Izleyen;
                        elemanSayisi--;
                        cout << anahtar << " silindi" << endl;
                        return;
                    }
                    TakipEden = Izleyen;
                    Izleyen = Izleyen->pSonraki;
                }
            }
        }
        cout << "listede " << anahtar << " Silemezsin, anahtar yok. " << endl;
    }

    void empty()
    {
        for (int i = 0; i < 10; i++)
            table[i] = NULL;
        elemanSayisi = 0;
    }

    int getElemanSayisi() { return elemanSayisi; }
};

bool hashOptions(hashTable &table)
{
    cout << "------Hash Tablosu icin Islem------" << endl;
    cout << "1: Tabloya Eleman Ekle             " << endl;
    cout << "2: Tablodan Eleman Cikar           " << endl;
    cout << "3: Tabloyu Temizle                 " << endl;
    cout << "4: Tablodaki Eleman Sayisini Goster" << endl;
    cout << "5: Tablodaki Elemanlari Goster     " << endl;
    cout << "6: Ana Menuye Don                  " << endl;
    cout << "Yapmak istediginiz islem:          ";
    int secim;
    cin >> secim;
    switch (secim)
    {
    case 1:
        cout << "tabloya eklemek istediginiz sayiyi girin: ";
        int girdi;
        cin >> girdi;
        table.ekle(girdi);
        break;
    case 2:
        cout << "silmek istediginiz anahtari girin: ";
        cin >> girdi;
        table.sil(girdi);
        break;
    case 3:
        cout << "tablo temizlendi..!" << endl;
        table.empty();
        break;
    case 4:
        cout << "tabloda " << table.getElemanSayisi() << " tane eleman var." << endl;
        break;
    case 5:
        table.elemanlariGoster();
        break;
    case 6:
        return true;
        break;
    default:
        cout << "***HATALI SECIM*** lutfen tekrar gir.. \n";
        break;
    }
    return false;
}
int main()
{
    hashTable table;
    bool exit = false;
    while (!exit)
    {
        exit = hashOptions(table);
    }
}
