#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
using namespace std;
//103122400004 Abidah Fatimatuzzahrah

#define first(L) (L).first
#define last(L) (L).last
#define next(P) (P)->next
#define prev(P) (P)->prev
#define info(P) (P)->info
#define NIL NULL

struct element;
typedef element* address;

struct infotype {
    int id;
    string konten;
    int like;
    string username;
};

struct element {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void createList(List &L);
List createNewList();
address allocate(infotype data);
bool isEmpty(List a);
void insertFirst(List &a, address p);
void insertLast(List &a, address p);
void deleteFirst(List &a, address p);
void deleteLast(List &a, address p);
address findElement(List a, infotype x);
void printList(List a);
int length(List a);

void insertSorted(List &a, address P); //masukin terurut berdasarkan id
void showByUsername(List a, string uname); //tampilkan semua post berdasarkan username
void showMostLiked(List a); //tampilkan post dengan like terbanyak
void updateLike(List &a, int id, bool like); //like = true untuk like, false untuk unlike

#endif
