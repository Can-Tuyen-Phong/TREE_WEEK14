#include <iostream>
using namespace std;

#define MAX 100
#define NIL -1

typedef char DataType;
typedef int Node;

typedef struct {
    DataType Data[MAX];
    int MaxNode;
} Tree;


void initTree(Tree &T) {
    T.MaxNode = 0;
}

int emptyTree(Tree T) {
    return T.MaxNode == 0;
}

Node Root(Tree T) {
    if (!emptyTree(T)) return 0;
    return NIL;
}

void Them(Tree &T, DataType x) {
    if (T.MaxNode >= MAX) return;
    T.Data[T.MaxNode++] = x;
}


Node Trai(Node p, Tree T) {
    int i = 2*p + 1;
    return (i < T.MaxNode) ? i : NIL;
}

Node Phai(Node p, Tree T) {
    int i = 2*p + 2;
    return (i < T.MaxNode) ? i : NIL;
}


void duyetTruoc(Tree T, Node p) {
    if (p == NIL) return;
    cout << T.Data[p] << " ";
    duyetTruoc(T, Trai(p,T));
    duyetTruoc(T, Phai(p,T));
}

void duyetGiua(Tree T, Node p) {
    if (p == NIL) return;
    duyetGiua(T, Trai(p,T));
        cout << T.Data[p] << " ";
    duyetGiua(T, Phai(p,T));
}

void duyetSau(Tree T, Node p) {
    if (p == NIL) return;
    duyetSau(T, Trai(p,T));
    duyetSau(T, Phai(p,T));
    cout << T.Data[p] << " ";
}
int main() {
    Tree T;
    initTree(T);

    Them(T,'A');
    Them(T,'B');
    Them(T,'C');
    Them(T,'D');
    Them(T,'E');
    Them(T,'F');
    Them(T,'G');

    duyetTruoc(T, Root(T)); cout << endl;
    duyetGiua(T, Root(T)); cout << endl;
    duyetSau(T, Root(T)); cout << endl;
}
