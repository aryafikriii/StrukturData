#ifndef LAYARTANCAP21_H_INCLUDED
#define LAYARTANCAP21_H_INCLUDED

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define nextPenonton(P) (P)->nextPenonton
#define first(L) ((L).first)
#define last(L) ((L).last)

/**DEKLARASI TIPE DATA PENONTON*/
typedef struct elmPenonton *adrPenonton;

struct penonton {
    string nama;
    string email;
    int umur;
};

struct elmPenonton {
    penonton info;
    adrPenonton next;
    adrPenonton prev;
};

struct mllPenonton {
    adrPenonton first;
    adrPenonton last;
};

/**DEKLARASI TIPE DATA FILM*/
typedef struct elmFilm *adrFilm;

struct film {
    string judul;
    string rating;
    string durasi;
    string jam;
    int teater;
};

struct elmFilm {
    film info;
    adrFilm next;
    adrFilm prev;
    adrPenonton nextPenonton;
};

struct mllFilm {
    adrFilm first;
    adrFilm last;
};

/**PRIMITIF FILM*/
void createListFilm(mllFilm &L);
film newDataFilm(string judul, string rating, string durasi, string jam, int teater);
adrFilm createElemenFilm(film dataBaru, adrFilm P);
void insertLastFilm(mllFilm &L, adrFilm P);
void showDataFilm(mllFilm DataFilm);
adrFilm deleteFirstFilm(mllFilm &L);
adrFilm deleteLastFilm(mllFilm &L);
adrFilm deleteAfterFilm(adrFilm prec);
void deleteFilm(mllFilm &L, adrFilm prec);
adrFilm findFilm(mllFilm L, string judul);
void findParent(mllFilm L);
bool cariFilm(mllFilm L, string judul);
void deleteRelation(adrFilm &Pfilm);
void insertRelation(adrFilm Pfilm, adrPenonton Ppenonton);

/**PRIMITIF PENONTON*/
void createListPenonton(mllPenonton &L);
penonton newDataPenonton(string nama, string email, int umur);
adrPenonton createElemenPenonton(penonton dataBaru, adrPenonton P);
void InsertNewPenonton(mllFilm &L, adrFilm S, adrPenonton J);
void deleteFirstPenonton(mllFilm &L, adrPenonton prec);
void deleteLastPenonton(mllFilm &L, adrPenonton prec);
void deleteAfterPenonton(mllFilm &L, adrPenonton prec);
void deletePenonton(mllFilm &S ,adrPenonton prec);
adrPenonton findPenonton(mllFilm L, string email);
bool cariPenonton(mllFilm L, string email);
void findChild(mllFilm L);
void ShowDataPenonton(mllFilm L);

/**PENGOLAHAN DATA*/
void showSumFilm(mllFilm L);
void ShowSumPenonton(mllFilm L);
int Min(mllFilm L);
int Max(mllFilm L);
void showMinMax(mllFilm L, int muda, int tua);

/**PRIMITIF UMUM*/
void LoadDataBioskop(mllFilm &Lfilm, mllPenonton &LPenonton);
void ShowAllData(mllFilm L);
void menu();

#endif // LAYARTANCAP21_H_INCLUDED
