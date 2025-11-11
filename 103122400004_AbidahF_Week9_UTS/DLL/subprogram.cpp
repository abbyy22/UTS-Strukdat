#include "header.h" //sesuaikan dengan file header yang dibuat
//103122400004 Abidah Fatimatuzzahrah


address createElement (infotype data){ 
    address p = allocate(data);
    return p;
} //fungsi untuk membuat elemen baru

address allocate(infotype data){
    address p = new element; //alokasi memori
    info(p) = data; //mengisi info elemen dengan data
    next(p) = NIL; //inisialisasi next elemen dengan NIL
    prev(p) = NIL; //inisialisasi prev elemen dengan NIL
    return p; //mengembalikan alamat elemen yang telah dialokasikan
} //fungsi untuk mengalokasikan memori elemen baru

void createList(List &L) {
    first(L) = NIL; //inisialisasi list kosong
    last(L) = NIL; //inisialisasi list kosong
} //fungsi untuk membuat list kosong


List createNewList(){
    List a; //membuat variabel list baru
    createList(a); //menginisialisasi list baru tersebut
    return a; //mengembalikan list baru
} //fungsi untuk membuat list baru dan mengembalikan list tersebut

bool isEmpty (List a){
   return first(a) == NIL && last(a) == NIL; //mengembalikan true jika list kosong
} //fungsi untuk mengecek apakah list kosong

//silahkan uncomment untuk NIM ganjil
void insertFirst (List &a, address p){
    if (isEmpty(a)){
        first(a) = p; //jika list kosong, first dan last sama dengan p
        last(a) = p; //karena hanya ada 1 elemen
    }else{
        next(p) = first(a); //jika list tidak kosong, next p menunjuk ke first
        prev(first(a)) = p; //prev first menunjuk ke p
        first(a) = p; //first diupdate menjadi p
    }
} //fungsi untuk memasukkan elemen di awal list

void insertAfter(List &a, infotype x, address p){
    address Q = findElement(a, x); //mencari elemen dengan info x
    if (Q != NIL){ //jika elemen ditemukan
        if (Q == last(a)){ //jika elemen adalah last
            insertLast(a, p); //p dimasukkan di akhir list
        }else{
            next(p) = next(Q); //next p menunjuk ke next Q
            prev(next(Q)) = p; //prev next Q menunjuk ke p
            next(Q) = p; //next Q diupdate menjadi p
            prev(p) = Q; //prev p diupdate menjadi Q
        }
    } else {
        cout << "elemen dengan info " << x.id << " tidak ditemukan" << endl;
    } //jika elemen tidak ditemukan
} //fungsi untuk memasukkan elemen setelah elemen dengan info x


void insertLast(List &a, address p){
    if (isEmpty(a)){ //jika list kosong
        first(a) = p;
        last(a) = p; //first dan last sama dengan p
    }else{
        prev(p) = last(a); //jika list tidak kosong, prev p menunjuk ke last
        next(last(a)) = p; //next last menunjuk ke p
        last(a) = p; //last diupdate menjadi p
    }
} //fungsi untuk memasukkan elemen di akhir list

void insertSorted(List &L, address P) {
    if (isEmpty(L)) { //jika list kosong
        insertFirst(L, P); //masukkan di awal
    } else if (info(P).id < info(first(L)).id) { //jika id P lebih kecil dari first
        insertFirst(L, P); //masukkan di awal
    } else if (info(P).id > info(last(L)).id) { //jika id P lebih besar dari last
        insertLast(L, P); //masukkan di akhir
    } else { 
        address Q = first(L); //mulai dari first
        while (Q != NIL && info(P).id > info(Q).id) { //cari posisi yang tepat
            Q = next(Q); //lanjut ke next
        }
        address before = prev(Q); //elemen sebelum Q
        next(before) = P; //sisipkan P di antara before dan Q
        prev(P) = before; //atur prev P
        next(P) = Q; //atur next P
        prev(Q) = P; //atur prev Q
    } 
} //fungsi untuk memasukkan elemen secara terurut berdasarkan id

void showByUsername(List L, string uname) {
    address P = first(L); //mulai dari first
    bool found = false; //flag untuk menandai apakah ada postingan ditemukan
    while (P != NIL) {
        if (info(P).username == uname) { //jika username cocok
            cout << "ID: " << info(P).id  //tampilkan info postingan 
                 << ", Konten: " << info(P).konten
                 << ", Like: " << info(P).like
                 << ", User: " << info(P).username << endl;
            found = true; //tandai bahwa ada postingan ditemukan
        } //jika username tidak cocok
        P = next(P); //lanjut ke next
    }
    if (!found) {
        cout << "Tidak ada postingan dari " << uname << endl;
    } //jika tidak ada postingan ditemukan
} //fungsi untuk menampilkan semua post berdasarkan username

void showMostLiked(List L) {
    if (isEmpty(L)) { //jika list kosong
        cout << "List kosong" << endl; //tampilkan pesan
        return;
    } //jika list tidak kosong
    address P = first(L);  //mulai dari first
    address maxP = P; //inisialisasi maxP dengan first
    while (P != NIL) { 
        if (info(P).like > info(maxP).like) { //jika like P lebih besar dari maxP
            maxP = P; //update maxP
        }
        P = next(P); //lanjut ke next
    }
    cout << "Post Terpopuler:" << endl; //tampilkan info post dengan like terbanyak
    cout << "ID: " << info(maxP).id 
         << ", Konten: " << info(maxP).konten
         << ", Like: " << info(maxP).like
         << ", User: " << info(maxP).username << endl;
} //fungsi untuk menampilkan post dengan like terbanyak

void updateLike(List &L, int id, bool like) { //like = true untuk like, false untuk unlike
    address P = first(L);
    while (P != NIL && info(P).id != id) { //cari elemen dengan id
        P = next(P); //lanjut ke next
    }
    if (P != NIL) { //jika elemen ditemukan
        if (like) info(P).like++; //jika like true, tambahkan like
        else info(P).like--; //jika like false, kurangi like
    } else {
        cout << "Post ID " << id << " tidak ditemukan" << endl; //jika elemen tidak ditemukan
    }
} //fungsi untuk mengupdate like atau unlike pada post dengan id tertentu



void deleteFirst(List &a, address p){
    if (isEmpty(a)) { //jika list kosong
        cout << "list kosong" << endl; //tampilkan pesan
    } else if (first(a) != last(a)){ //jika lebih dari 1 elemen
        p = first(a); //simpan alamat first ke p
        first(a) = next(p); //update first ke next p
        prev(first(a)) = NIL; //menghapus link prev first
        next(p) = NIL; //menghapus link next p
    } else { //tinggal 1 elemen
        p = first(a); //simpan alamat first ke p
        first(a) = NIL; //update first dan last ke NIL 
        last(a) = NIL;
        next(p) = NIL;
        prev(p) = NIL;
    }
} //fungsi untuk menghapus elemen pertama list


void deleteLast(List &a, address p){
    if (isEmpty(a)) {
        cout << "list kosong" << endl; //jika list kosong
    } else if (next(first(a))==NIL){ //jika tinggal 1 elemen
        p = first(a); //simpan alamat first ke p
        first(a) = NIL; //update first dan last ke NIL
        last(a) = NIL;
        next(p) = NIL;
        prev(p) = NIL;
    }else{ //jika lebih dari 1 elemen
        p = last(a); //simpan alamat last ke p
        last(a) = prev(p); //update last ke prev p
        prev(p) = NIL; //menghapus link prev p
        next(last(a)) = NIL; //menghapus link next last
    }

} //fungsi untuk menghapus elemen terakhir list

int length(List a) {
    int jml = 1; //inisialisasi jumlah elemen
    address p = first(a); //mulai dari first
    if(p == NIL){ //jika list kosong
       return 0;
    }else {
       while(p != last(a)){ //iterasi sampai last
           jml++;
           p = next(p);
       }
       return jml; //mengembalikan jumlah elemen
    }
}


address findElement(List a, infotype x) { //mencari elemen dengan info x
    if (isEmpty(a)) { //jika list kosong
        return NIL;
    } else { //jika list tidak kosong
        address Q = first(a); //mulai dari first
        while (Q != NIL && info(Q).id != x.id) { //cari elemen dengan info x
            Q = next(Q); //lanjut ke next
        }
        return Q;
    }
} //fungsi untuk mencari elemen dengan info x


void printList(List a) {
    address p = first(a); //mulai dari first 
    if (isEmpty(a)) { //jika list kosong
        cout << "List kosong" << endl;
    } else { //jika list tidak kosong
        cout << "Daftar Postingan:" << endl;
        while (p != NIL) { //iterasi sampai akhir list
            cout << "ID: " << info(p).id
                 << ", Konten: " << info(p).konten
                 << ", Like: " << info(p).like
                 << ", Username: " << info(p).username
                 << endl;
            p = next(p);
        }
    }
} //fungsi untuk menampilkan semua elemen dalam list
