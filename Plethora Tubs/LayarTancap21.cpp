#include "LayarTancap21.h"

/**FUNGSI DAN PROCEDURE FILM*/
void createListFilm(mllFilm &L) {
    first(L) = NULL;
    last(L) = NULL;
}

film newDataFilm(string judul, string rating, string durasi,string jam, int teater) {
    film data;

    data.judul = judul;
    data.rating = rating;
    data.durasi = durasi;
    data.jam = jam;
    data.teater = teater;

    return data;
}

adrFilm createElemenFilm(film dataBaru, adrFilm P) {
    P = new elmFilm;

    info(P).judul = dataBaru.judul;
    info(P).rating = dataBaru.rating;
    info(P).durasi = dataBaru.durasi;
    info(P).jam = dataBaru.jam;
    info(P).teater = dataBaru.teater;
    next(P) = NULL;
    prev(P) = NULL;
    nextPenonton(P) = NULL;

    return P;
}
void showDataFilm(mllFilm L) {
    adrFilm P = first(L);

    cout << "--------------------------------------------------------"<< endl;
    cout << "\t \t \tDATA FILM" << endl;
    cout << "--------------------------------------------------------"<< endl;
    if (P != NULL){
        int i=1;
        do {
            cout << "[Film "<<i<<"]" << endl;
            cout << "Judul      : " << info(P).judul  << endl;
            cout << "Rating     : " << info(P).rating << endl;
            cout << "Durasi     : " << info(P).durasi << endl;
            cout << "Jam Tayang : " << info(P).jam    << endl;
            cout << "Teater     : " << info(P).teater << endl;
            cout << "--------------------------------------------------------"<< endl;
            P = next(P);
            i+=1;
        } while (P != first(L));
    } else {
        cout << "\t \t   Tidak Ada Data Film!" << endl;
        cout << "--------------------------------------------------------"<< endl;
    }
}

void insertLastFilm(mllFilm &L, adrFilm P) {
    if (first(L) == NULL) {
        first(L) = P;
        last(L) = P;
        next(P) = P;
        prev(P) = P;
    } else {
        next(last(L)) = P;
        prev(P) = last(L);
        next(P) = first(L);
        prev(first(L)) = P;
        last(L) = P;
    }
}

adrFilm deleteFirstFilm(mllFilm &L) {
    adrFilm P;

    if (first(L) != NULL) {
        P = first(L);
        if (P == last(L)) {
            next(P) = NULL;
            prev(P) = NULL;
            first(L) = NULL;
            last(L) = NULL;
        } else {
            first(L) = next(P);
            next(last(L)) = first(L);
            prev(first(L)) = last(L);
            next(P) = NULL;
            prev(P) = NULL;
        }
    }
}

adrFilm deleteLastFilm(mllFilm &L) {
    adrFilm P;

    if (first(L) != NULL) {
        P = last(L);
        if (P == last(L)) {
            next(P) = NULL;
            prev(P) = NULL;
            first(L) = NULL;
            last(L) = NULL ;
        } else {
            last(L) = prev(P);
            next(last(L)) = first(L);
            prev(first(L)) = last(L);
            next(P) = NULL;
            prev(P) = NULL;
        }
    }
}

adrFilm deleteAfterFilm(adrFilm prec) {
    prev(next(prec)) = prev(prec);
    next(prev(prec)) = next(prec);
    next(prec) = NULL;
    prev(prec) = NULL;
}

void deleteFilm(mllFilm &L, adrFilm prec) {
    adrFilm P;

    P = first(L);
    do {
        if (P == prec) {
            if (P != NULL) {
                if (P == first(L)) {
                    deleteFirstFilm(L);
                } else if (next(P) == NULL) {
                    deleteLastFilm(L);
                } else {
                    deleteAfterFilm(prec);
                }
            }
            cout << endl;
            cout << "Delete Berhasil!" << endl << endl;
            break;
        }
        P = next(P);
    } while (P != first(L));
}

adrFilm findFilm(mllFilm L, string judul) {
    adrFilm P = first(L);
    do {
        if (info(P).judul == judul){
            return P;
        }
        P = next(P);
    } while(P != first(L));
    return P;
}

bool cariFilm(mllFilm L, string judul) {
    adrFilm P = first(L);
    bool ketemu;

    ketemu = false;

    do {
        if (info(P).judul == judul){
            ketemu = true;
            return ketemu;
        }
        P = next(P);
    } while(P != first(L));
    return ketemu;
}

void findParent(mllFilm L) {
    adrFilm P = first(L);
    string judul;
    bool ketemu;

    ketemu = false;

    cout << "Judul Film : "; cin.ignore(); getline(cin, judul);
    ketemu = cariFilm(L, judul);

    if (ketemu) {
        do {
            if (info(P).judul == judul){
                cout << "--------------------------------------------------------" << endl;
                cout << "\t \tData berhasil ditemukan!"                            << endl;
                cout << "--------------------------------------------------------" << endl;
                cout << "Judul      : " << info(P).judul                           << endl;
                cout << "Rating     : " << info(P).rating                          << endl;
                cout << "Durasi     : " << info(P).durasi                          << endl;
                cout << "Jam Tayang : " << info(P).jam                             << endl;
                cout << "Teater     : " << info(P).teater                          << endl;
                cout << "--------------------------------------------------------" << endl;
            }
            P = next(P);
        } while(P != first(L));
    } else {
        cout << "------------------------------------------" << endl;
        cout << "\tData Film tidak ada!"                    << endl;
        cout << "------------------------------------------" << endl;

    }
}

adrPenonton deleteRelasi(mllFilm &L, mllPenonton &temp, adrFilm Pfilm) {
    adrPenonton P, R;
    adrFilm Q = first(L);

    do {
        if (Q == Pfilm) {
            R = first(temp);
            P = nextPenonton(Q);
            R = P;
            nextPenonton(Q) = NULL;
        }
        Q = next(Q);
    } while (Q != first(L));
    cout << endl;
    cout << "------------------------------------------" << endl;
    cout << "\tRelasi Berhasil Dihapus."                << endl;
    cout << "------------------------------------------" << endl;
    return R;
}

void createRelasi(mllFilm &L, adrPenonton Ppenonton, adrFilm Pfilm) {
    adrFilm Q;

    Q = first(L);
    do {
        if (Q == Pfilm) {
            nextPenonton(Q) = Ppenonton;
        }
        Q = next(Q);
    } while (Q != first(L));
    cout << endl;
    cout << "------------------------------------------" << endl;
    cout << "\tRelasi Berhasil Ditambahkan."            << endl;
    cout << "------------------------------------------" << endl;
}

/**FUNGSI DAN PROCEDURE PENONTON*/

void createListPenonton(mllPenonton &L) {
    first(L) = NULL;
    last(L) = NULL;
}

penonton newDataPenonton(string nama, string email, int umur) {
    penonton data;

    data.nama = nama;
    data.email = email;
    data.umur = umur;

    return data;
}

adrPenonton createElemenPenonton(penonton dataBaru, adrPenonton P) {
    P = new elmPenonton;

    info(P).nama = dataBaru.nama;
    info(P).email = dataBaru.email;
    info(P).umur = dataBaru.umur;
    next(P) = NULL;
    prev(P) = NULL;

    return P;
}

void InsertNewPenonton(mllFilm &L, adrFilm F, adrPenonton P){
    adrPenonton Ppenonton;

    Ppenonton = nextPenonton(F);
    if (nextPenonton(F) == NULL){
        nextPenonton(F) = P;
    }else{
        while (next(Ppenonton) != NULL){
            Ppenonton = next(Ppenonton);
        }
        next(Ppenonton) = P;
    }
}

void deleteFirstPenonton(mllFilm &L, adrPenonton prec) {
    adrPenonton P;
    adrFilm Q;

    Q = first(L);
    do {
        P = nextPenonton(Q);
        while (P != NULL){
            if (P == prec) {
                nextPenonton(Q) = next(P);
                next(P) = NULL;
                prev(P) = NULL;
            }
            P = next(P);
        }
        Q = next(Q);
    } while (Q != first(L));
}

void deleteLastPenonton(mllFilm &L, adrPenonton prec) {
    adrPenonton P, Q;
    adrFilm Pfilm;

    Pfilm = first(L);
    do {
        P = nextPenonton(Pfilm);
        do {
            if (P != prec) {
                if (next(P) == prec) {
                    Q = next(P);
                    next(P) = NULL;
                    prev(Q) = NULL;
                    next(Q) = NULL;
                }
            }
            P = next(P);
        } while (P != NULL);
        Pfilm = next(Pfilm);
    } while (Pfilm != first(L));
}

void deleteAfterPenonton(mllFilm &L, adrPenonton prec) {
    adrPenonton P, Q;
    adrFilm Pfilm;

    Pfilm = first(L);
    do {
        P = nextPenonton(Pfilm);
        while (P != NULL){
            if (P != prec) {
                if (next(P) == prec) {
                    Q = next(P);
                    prev(next(P)) = prev(P);
                    next(P) = next(Q);
                    prev(Q) = NULL;
                    next(Q) = NULL;
                }
            }
            P = next(P);
        }
        Pfilm = next(Pfilm);
    } while (Pfilm != first(L));
}

void deletePenonton(mllFilm &L ,adrPenonton prec) {
    adrPenonton P;
    adrFilm Q;

    Q = first(L);
    do {
        P = nextPenonton(Q);
        while (P != NULL) {
            if (P == prec) {
                if (P != NULL) {
                    if (P == nextPenonton(Q)) {
                        deleteFirstPenonton(L, prec);
                    } else if (next(P) == NULL) {
                        deleteLastPenonton(L, prec);
                    } else {
                        deleteAfterPenonton(L, prec);
                    }
                }
                cout << endl;
                cout << "------------------------------------------" << endl;
                cout << "\tDelete Berhasil!"                         << endl;
                cout << "------------------------------------------" << endl;
                break;
            }
            P = next(P);
        }
        Q = next(Q);
    } while (Q != first(L));
}

adrPenonton findPenonton(mllFilm L, string email) {
    adrPenonton P, Pfind;
    adrFilm Q;

    Q = first(L);
    do {
        P = nextPenonton(Q);
        while (P != NULL){
            if (info(P).email == email) {
                Pfind = P;
            }
            P = next(P);
        }
        Q = next(Q);
    } while (Q != first(L));
    return Pfind;
}

bool cariPenonton(mllFilm L, string email) {
    adrPenonton P;
    adrFilm Q;
    bool ketemu;

    ketemu = false;

    Q = first(L);
    do {
        P = nextPenonton(Q);
        while (P != NULL){
            if (info(P).email == email) {
                ketemu = true;
                return ketemu;
            }
            P = next(P);
        }
        Q = next(Q);
    } while (Q != first(L));
    return ketemu;
}

void findChild(mllFilm L) {
    adrPenonton P;
    adrFilm Q;
    bool ketemu;
    string email;

    ketemu = false;

    cout << "Email : "; cin >> email;
    ketemu = cariPenonton(L, email);

    if (ketemu) {
        Q = first(L);
        do {
            P = nextPenonton(Q);
            while (P != NULL){
                if (info(P).email == email) {
                    cout << "------------------------------------------"<< endl;
                    cout << "\tData berhasil ditemukan!"               << endl;
                    cout << "------------------------------------------"<< endl;
                    cout << "Nama  : " << info(P).nama                 << endl;
                    cout << "Email : " << info(P).email                << endl;
                    cout << "Umur  : " << info(P).umur << " tahun."    << endl;
                    cout << "------------------------------------------"<< endl;
                }
                P = next(P);
            }
            Q = next(Q);
        } while (Q != first(L));
    } else {
        cout << "------------------------------------------" << endl;
        cout << "\tData Penonton tidak ada!"                << endl;
        cout << "------------------------------------------" << endl;
    }
}


void ShowDataPenonton(mllFilm L) {
    adrPenonton P;
    adrFilm Q;
    int i = 1;

    Q = first(L);
    cout << "------------------------------------------"<< endl;
    cout << "\t \tDATA PENONTON" << endl;
    cout << "------------------------------------------"<< endl;
    if (Q != NULL) {
        do {
            P = nextPenonton(Q);
            while (P != NULL){
                cout << "["<<i<<"]";
                cout << "\tNama  : " << info(P).nama  << endl;
                cout << "\tEmail : " << info(P).email << endl;
                cout << "\tUmur  : " << info(P).umur  << " tahun." << endl;
                P = next(P);
                i++;
            }

            Q = next(Q);
        } while(Q != first(L));
        cout << endl;
    }
}

/**FUNGSI DAN PROCEDURE UMUM*/

void ShowAllData(mllFilm L) {
    adrPenonton P;
    adrFilm Q;
    int i, j;

    Q = first(L);
    i = 1;

    if (Q != NULL) {
        cout << "________________________________________________________" << endl;
        cout << "\t \t DATABASE LAYARTANCAP21"   << endl;
        cout << "________________________________________________________" << endl;
        do {
            cout << "["<<i<<"]"                     << endl;
            cout <<"Judul      : "<< info(Q).judul  << endl;
            cout <<"Rating     : "<< info(Q).rating << endl;
            cout <<"Durasi     : "<< info(Q).durasi << endl;
            cout <<"Jam Tayang : "<< info(Q).jam    << endl;
            cout <<"Teater     : "<< info(Q).teater << endl;
            cout << "________________________________________________________" << endl;
            P = nextPenonton(Q);
            i++;
            if (P!=NULL) {
                j = 1;
                while (P != NULL){
                    cout << "Penonton ke: " << j << endl;
                    cout <<"\tNama  : " << info(P).nama << endl;
                    cout <<"\tEmail : " << info(P).email << endl;
                    cout <<"\tUmur  : " << info(P).umur << " tahun." << endl;
                    cout << "________________________________________________________" << endl;
                    P = next(P);
                    j++;
                }
            } else {
                    cout << "\t \t Tidak ada penonton!" << endl;
                    cout << "________________________________________________________" << endl;
            }
            cout << endl;
            Q = next(Q);
        } while (Q != first(L));
    } else {
        cout << "------------------------------------------" << endl;
        cout << "\tTidak ada Data!"                         << endl;
        cout << "------------------------------------------" << endl;
    }
}

void showSumFilm(mllFilm DataFilm) {
    adrFilm P = first(DataFilm);
    int i, j;
    i = 0;
    j = 1;

    if (P != NULL){
        cout << "--------------------------------------------------------" << endl;
        do {
            cout << "["<<j<<"]";
            cout <<" Judul Film : "<< info(P).judul << endl;
            P = next(P);
            i+=1;
            j+=1;
        } while (P != first(DataFilm));
    }
    cout << "--------------------------------------------------------" << endl;
    cout << "\t Jumlah Film yang ditayangkan: " << i << " Film" << endl;
    cout << "--------------------------------------------------------" << endl;
}

void ShowSumPenonton(mllFilm L) {
    adrPenonton P;
    adrFilm Q;
    int i = 0;

    Q = first(L);
    if (Q != NULL) {
        do {
            P = nextPenonton(Q);
            if (P != NULL) {
                while (P != NULL){
                    P = next(P);
                    i++;
                }
                Q = next(Q);
            }
        } while(Q != first(L));
    }
    cout << "------------------------------------------"      << endl;
    cout << "  Jumlah Penonton Hari ini: " << i << " Penonton" << endl;
    cout << "------------------------------------------"      << endl;
}

int Max(mllFilm L) {
    adrPenonton P;
    adrFilm Q;
    int max = 0;

    Q = first(L);
    if (Q != NULL) {
        do {
            P = nextPenonton(Q);
            if (P != NULL) {
                while (P != NULL){
                    if (max < info(P).umur) {
                        max = info(P).umur;
                    }
                    P = next(P);
                }
                Q = next(Q);
            }
        } while(Q != first(L));
    }
    return max;
}

int Min(mllFilm L) {
    adrPenonton P;
    adrFilm Q;
    int min = 100;

    Q = first(L);
    if (Q != NULL) {
        do {
            P = nextPenonton(Q);
            if (P != NULL) {
                while (P != NULL){
                    if (min > info(P).umur) {
                        min = info(P).umur;
                    }
                    P = next(P);
                }
                Q = next(Q);
            }
        } while(Q != first(L));
    }
    return min;
}

void showMinMax(mllFilm L, int muda, int tua) {
    adrPenonton P;
    adrFilm Q;
    int i;

    if (Q != NULL) {
        do {
            P = nextPenonton(Q);
            if (P != NULL) {
                while (P != NULL){
                    if (tua == info(P).umur) {
                        cout << "------------------------------------------------"<< endl;
                        cout << "Umur Penonton Tertua  : " << tua << " tahun." << endl;
                        cout << "\tNama          : " << info(P).nama  << endl;
                        cout << "\tEmail         : " << info(P).email << endl;
                        cout << "\tUmur          : " << info(P).umur  << " tahun." << endl;
                        cout << "\tMenonton Film : " << info(Q).judul << endl;
                        cout << "------------------------------------------------"<< endl;
                    }
                    if (muda == info(P).umur) {
                        cout << "Umur Penonton Termuda : " << muda << " tahun." << endl;
                        cout << "\tNama          : " << info(P).nama  << endl;
                        cout << "\tEmail         : " << info(P).email << endl;
                        cout << "\tUmur          : " << info(P).umur  << " tahun." << endl;
                        cout << "\tMenonton Film : " << info(Q).judul << endl;
                        cout << "------------------------------------------------"<< endl;
                    }
                    P = next(P);
                    i++;
                }
                Q = next(Q);
            }
        } while(Q != first(L));
    }
}

void LoadDataBioskop(mllFilm &Lfilm, mllPenonton &LPenonton) {
    adrFilm dataFilm;

    adrPenonton dataPenonton;

    film infotypeFilm;
    penonton infotypePenonton;

    createListFilm(Lfilm);
    createListPenonton(LPenonton);

    infotypeFilm = newDataFilm("Spencer", "R Rated", "01:51:00", "11:30-13:30 | 14:00-16:00 | 16:30-18:30", 1);
    dataFilm = createElemenFilm(infotypeFilm, dataFilm);
    insertLastFilm(Lfilm, dataFilm);

    infotypePenonton = newDataPenonton("Aisha Aileen Nathania", "aisha@gmail.com", 18);
    dataPenonton = createElemenPenonton(infotypePenonton, dataPenonton);
    InsertNewPenonton(Lfilm, dataFilm, dataPenonton);

    infotypePenonton = newDataPenonton("Astrid Rahdian Amanda", "astrid@gmail.com", 34);
    dataPenonton = createElemenPenonton(infotypePenonton, dataPenonton);
    InsertNewPenonton(Lfilm, dataFilm, dataPenonton);

    infotypePenonton = newDataPenonton("Fabian Mikko Labib", "fabian@gmail.com", 29);
    dataPenonton = createElemenPenonton(infotypePenonton, dataPenonton);
    InsertNewPenonton(Lfilm, dataFilm, dataPenonton);

    infotypePenonton = newDataPenonton("Gabino Arthur Rajendra", "gabino@gmail.com", 21);
    dataPenonton = createElemenPenonton(infotypePenonton, dataPenonton);
    InsertNewPenonton(Lfilm, dataFilm, dataPenonton);

    infotypePenonton = newDataPenonton("Galen Baim Pratama", "galen@gmail.com", 21);
    dataPenonton = createElemenPenonton(infotypePenonton, dataPenonton);
    InsertNewPenonton(Lfilm, dataFilm, dataPenonton);

    infotypeFilm = newDataFilm("Venom: Let There Be Carnage", "PG-13", "01:37:00", "12:30-14:30 | 15:00-17:00 | 17:30-19:30", 2);
    dataFilm = createElemenFilm(infotypeFilm, dataFilm);
    insertLastFilm(Lfilm, dataFilm);

    infotypePenonton = newDataPenonton("Aubrey Fathia Pelangi", "aubrey@gmail.com", 26);
    dataPenonton = createElemenPenonton(infotypePenonton, dataPenonton);
    InsertNewPenonton(Lfilm, dataFilm, dataPenonton);

    infotypePenonton = newDataPenonton("Kafeel Hafizhan Syahreza", "kafeel@gmail.com", 23);
    dataPenonton = createElemenPenonton(infotypePenonton, dataPenonton);
    InsertNewPenonton(Lfilm, dataFilm, dataPenonton);

    infotypePenonton = newDataPenonton("Arya Fikriansyah", "arya@gmail.com", 19);
    dataPenonton = createElemenPenonton(infotypePenonton, dataPenonton);
    InsertNewPenonton(Lfilm, dataFilm, dataPenonton);

    infotypePenonton = newDataPenonton("Kavindra Aydin Rafeyfa", "kavindra@gmail.com", 19);
    dataPenonton = createElemenPenonton(infotypePenonton, dataPenonton);
    InsertNewPenonton(Lfilm, dataFilm, dataPenonton);

    infotypePenonton = newDataPenonton("Afra Rainey Keysa", "afra@gmail.com", 14);
    dataPenonton = createElemenPenonton(infotypePenonton, dataPenonton);
    InsertNewPenonton(Lfilm, dataFilm, dataPenonton);

    infotypeFilm = newDataFilm("Eternals", "PG-13", "02:36:00", "12:00-15:00 | 15:30-17:30 | 18:30-20:30", 3);
    dataFilm = createElemenFilm(infotypeFilm, dataFilm);
    insertLastFilm(Lfilm, dataFilm);

    infotypePenonton = newDataPenonton("Citra Laila Zanna", "laila@gmail.com", 20);
    dataPenonton = createElemenPenonton(infotypePenonton, dataPenonton);
    InsertNewPenonton(Lfilm, dataFilm, dataPenonton);

    infotypePenonton = newDataPenonton("Satria Aji PS", "satria@gmail.com", 19);
    dataPenonton = createElemenPenonton(infotypePenonton, dataPenonton);
    InsertNewPenonton(Lfilm, dataFilm, dataPenonton);

    infotypePenonton = newDataPenonton("Deswita Bratarini Nathania", "deswita@gmail.com", 23);
    dataPenonton = createElemenPenonton(infotypePenonton, dataPenonton);
    InsertNewPenonton(Lfilm, dataFilm, dataPenonton);

    infotypePenonton = newDataPenonton("Merekon Arlo Galal", "arlo@gmail.com", 29);
    dataPenonton = createElemenPenonton(infotypePenonton, dataPenonton);
    InsertNewPenonton(Lfilm, dataFilm, dataPenonton);

    infotypePenonton = newDataPenonton("Naufal Altezza Raditya", "naufal@gmail.com", 26);
    dataPenonton = createElemenPenonton(infotypePenonton, dataPenonton);
    InsertNewPenonton(Lfilm, dataFilm, dataPenonton);

    infotypeFilm = newDataFilm("Spider-Man: No Way Home", "PG-13", "02:28:00", "11:30-14:30 | 15:00-18:00 | 18:30-20:30",4);
    dataFilm = createElemenFilm(infotypeFilm, dataFilm);
    insertLastFilm(Lfilm, dataFilm);

    infotypePenonton = newDataPenonton("Adyatma Mahavir Bagaskara", "mahavir@gmail.com", 22);
    dataPenonton = createElemenPenonton(infotypePenonton, dataPenonton);
    InsertNewPenonton(Lfilm, dataFilm, dataPenonton);

    infotypePenonton = newDataPenonton("Ghali Daniyal Bramantio", "ghali@gmail.com", 13);
    dataPenonton = createElemenPenonton(infotypePenonton, dataPenonton);
    InsertNewPenonton(Lfilm, dataFilm, dataPenonton);

    infotypePenonton = newDataPenonton("Akalanka Mirza Zahair", "mirza@gmail.com", 16);
    dataPenonton = createElemenPenonton(infotypePenonton, dataPenonton);
    InsertNewPenonton(Lfilm, dataFilm, dataPenonton);

    infotypePenonton = newDataPenonton("Pamungkas Bagas Dhefin", "pamungkas@gmail.com", 30);
    dataPenonton = createElemenPenonton(infotypePenonton, dataPenonton);
    InsertNewPenonton(Lfilm, dataFilm, dataPenonton);

    infotypeFilm = newDataFilm("No Time to Die", "PG-13", "02:43:00", "13:00-16:00 | 16:30-19:30 | 20:00-23:00",5);
    dataFilm = createElemenFilm(infotypeFilm, dataFilm);
    insertLastFilm(Lfilm, dataFilm);

    infotypePenonton = newDataPenonton("Arzan Ravindra Malik", "arzan@gmail.com", 15);
    dataPenonton = createElemenPenonton(infotypePenonton, dataPenonton);
    InsertNewPenonton(Lfilm, dataFilm, dataPenonton);

    infotypePenonton = newDataPenonton("Barra Rafeyfa Maulana", "barra@gmail.com", 26);
    dataPenonton = createElemenPenonton(infotypePenonton, dataPenonton);
    InsertNewPenonton(Lfilm, dataFilm, dataPenonton);

    infotypePenonton = newDataPenonton("Elvan Rafisqy Fathaan", "elvan@gmail.com", 28);
    dataPenonton = createElemenPenonton(infotypePenonton, dataPenonton);
    InsertNewPenonton(Lfilm, dataFilm, dataPenonton);

    infotypePenonton = newDataPenonton("Zabdan Nuri Faeyza", "zabdan@gmail.com", 31);
    dataPenonton = createElemenPenonton(infotypePenonton, dataPenonton);
    InsertNewPenonton(Lfilm, dataFilm, dataPenonton);

    cout << "------------------------------------------" << endl;
    cout << "\tData berhasil ditambahkan!"              << endl;
    cout << "------------------------------------------" << endl;
}

void menu() {
    mllFilm Lfilm;

    mllPenonton Lpenonton;
    mllPenonton Ltemp;

    adrFilm Pfilm;
    adrFilm AdrcariF;
    adrPenonton Ppenonton;
    adrPenonton AdrtempP;

    film dataF;
    penonton dataP;

    string judul, rating, durasi, jam, nama, email;
    int teater, umur, muda, tua;

    createListFilm(Lfilm);
    createListPenonton(Ltemp);
    createListPenonton(Lpenonton);

    bool loop = true;
    char n;
    string x;

    while(loop){
        cout << "------------------------------------------" << endl;
        cout << "\t   Bioskop LayarTancap21"                 << endl;
        cout << "------------------------------------------" << endl;
        cout << " A. Insert Data Film."                      << endl;
        cout << " B. Delete Film."                           << endl;
        cout << " C. Show Data Film."                        << endl;
        cout << " D. Find Film."                             << endl;
        cout << " E. Insert Data Penonton."                  << endl;
        cout << " F. Delete Penonton."                       << endl;
        cout << " G. Show Data Penonton."                    << endl;
        cout << " H. Find Penonton."                         << endl;
        cout << " I. Show Data All."                         << endl;
        cout << " J. Menghapus relasi."                      << endl;
        cout << " K. Menentukan relasi."                     << endl;
        cout << " L. Jumlah Film yang ditayangkan."          << endl;
        cout << " M. Jumlah Penonton Hari ini."              << endl;
        cout << " N. Penonton termuda dan tertua yang hadir."<< endl;
        cout << " O. Load Data film."                        << endl;
        cout << " X. Exit."                                  << endl;
        cout << "------------------------------------------" << endl;
        cout << "Pilihan: "; cin >> n;
        switch(n){
        case 'A':
            cout << "Judul Film : "; cin.ignore(); getline(cin, judul);
            cout << "Rating     : "; getline(cin, rating);
            cout << "Durasi     : "; cin >> durasi;
            cout << "Jam Tayang : "; cin.ignore();getline(cin, jam);
            cout << "Teater     : "; cin >> teater;

            dataF = newDataFilm(judul, rating, durasi, jam, teater);
            Pfilm = createElemenFilm(dataF, Pfilm);
            insertLastFilm(Lfilm, Pfilm);

            cout << "tekan enter untuk kembali ke menu utama.";_getch();system("cls");break;
        case 'B' :
            cout << "Judul Film : ";cin.ignore(); getline(cin, judul);

            if (cariFilm(Lfilm, judul) == false) {
                cout << "------------------------------------------" << endl;
                cout << "\tData Film tidak ada!"                    << endl;
                cout << "------------------------------------------" << endl;
                cout << "tekan enter untuk kembali ke menu utama";_getch();system("cls");break;
            }

            Pfilm = findFilm(Lfilm, judul);
            deleteFilm(Lfilm, Pfilm);

            cout << "tekan enter untuk kembali ke menu utama";_getch();system("cls");break;
        case 'C':
            showDataFilm(Lfilm);
            cout << "tekan enter untuk kembali ke menu utama";_getch();system("cls");break;
        case 'D':
            findParent(Lfilm);
            cout << "tekan enter untuk kembali ke menu utama";_getch();system("cls");break;
        case 'E' :
            cout << "Judul Film : "; cin.ignore(); getline(cin, judul);

            if (cariFilm(Lfilm, judul) == false) {
                cout << "------------------------------------------" << endl;
                cout << "\tData Film tidak ada!"                    << endl;
                cout << "------------------------------------------" << endl;
                cout << "tekan enter untuk kembali ke menu utama";_getch();system("cls");break;
            }

            Pfilm = findFilm(Lfilm, judul);

            cout << "Nama       : "; getline(cin, nama);
            cout << "Email      : "; cin >> email;
            cout << "Umur       : "; cin >> umur;

            dataP = newDataPenonton(nama, email , umur);
            Ppenonton = createElemenPenonton(dataP, Ppenonton);
            InsertNewPenonton(Lfilm, Pfilm, Ppenonton);

            ShowDataPenonton(Lfilm);

            cout << "tekan enter untuk kembali ke menu utama";_getch();system("cls");break;
        case 'F' :
            cout << "Email : "; cin >> x;

            if (cariPenonton(Lfilm, x) == false) {
                cout << "------------------------------------------" << endl;
                cout << "\tData Penonton tidak ada!"                << endl;
                cout << "------------------------------------------" << endl;
                cout << "tekan enter untuk kembali ke menu utama";_getch();system("cls");break;
            }

            Ppenonton = findPenonton(Lfilm, x);
            deletePenonton(Lfilm, Ppenonton);

            ShowDataPenonton(Lfilm);

            cout << "tekan enter untuk kembali ke menu utama";_getch();system("cls");break;
        case 'G' :
            ShowDataPenonton(Lfilm);
            cout << "tekan enter untuk kembali ke menu utama";_getch();system("cls");break;
        case 'H':
            findChild(Lfilm);
            cout << "tekan enter untuk kembali ke menu utama";_getch();system("cls");break;
        case 'I' :
            ShowAllData(Lfilm);
            cout << "tekan enter untuk kembali ke menu utama";_getch();system("cls");break;
        case 'J':
            cout <<"Judul Film : "; cin.ignore(); getline(cin, x);\

            if (cariFilm(Lfilm, x) == false) {
                cout << "------------------------------------------" << endl;
                cout << "\tData Film tidak ada!"                    << endl;
                cout << "------------------------------------------" << endl;
                cout << "tekan enter untuk kembali ke menu utama";_getch();system("cls");break;
            }

            AdrcariF = findFilm(Lfilm, x);
            AdrtempP = deleteRelasi(Lfilm, Ltemp, AdrcariF);

            cout << "tekan enter untuk kembali ke menu utama";_getch();system("cls");break;
        case 'K' :
            cout << "Judul Film : "; cin.ignore(); getline(cin, judul);

            if (cariFilm(Lfilm, judul) == false) {
                cout << "------------------------------------------" << endl;
                cout << "\tData Film tidak ada!"                    << endl;
                cout << "------------------------------------------" << endl;
                cout << "tekan enter untuk kembali ke menu utama";_getch();system("cls");break;
            }

            AdrcariF = findFilm(Lfilm, judul);
            createRelasi(Lfilm, AdrtempP, AdrcariF);

            cout << "tekan enter untuk kembali ke menu utama";_getch();system("cls");break;
        case 'L':
            showSumFilm(Lfilm);
            cout << "tekan enter untuk kembali ke menu utama";_getch();system("cls");break;
        case 'M':
            ShowSumPenonton(Lfilm);
            cout << "tekan enter untuk kembali ke menu utama";_getch();system("cls");break;
        case 'N':
            muda = Min(Lfilm);
            tua = Max(Lfilm);
            showMinMax(Lfilm, muda, tua);
            cout << "tekan enter untuk kembali ke menu utama";_getch();system("cls");break;
        case 'O':
            LoadDataBioskop(Lfilm, Lpenonton);
            cout << "tekan enter untuk kembali ke menu utama";_getch();system("cls");break;
        case 'X' :
            cout << "------------------------------------------" << endl;
            cout << " Anda Telah Keluar dari Program. Sayonara!" << endl;
            cout << "------------------------------------------" << endl;
            loop = false; break;
        default :
            cout << "------------------------------------------" << endl;
            cout << " Pilihan Salah" << endl;
            cout << "tekan enter untuk kembali ke menu utama" ;_getch();system("cls");break;
        }
    }
}
