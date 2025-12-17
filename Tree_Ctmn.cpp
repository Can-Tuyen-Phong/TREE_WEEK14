#include <iostream>
using namespace std;

typedef char DataType;

struct Node {
    DataType info;
    Node *LP;
    Node *RP;
};


typedef Node* Tree;

void initTree(Tree &T) {
    T = NULL;
}

int emptyTree(Tree T) {
    return T == NULL;
}

Node* taoNode(DataType x) {
    Node *p = new Node;
    p->info = x;
    p->LP = p->RP = NULL;
    return p;
}


void themTrai(Node *p, DataType x) {
    if (p != NULL && p->LP == NULL)
        p->LP = taoNode(x);
}

void themPhai(Node *p, DataType x) {
    if (p != NULL && p->RP == NULL)
        p->RP = taoNode(x);
}

void duyetTruoc(Tree T) {
    if (T == NULL) return;
    cout << T->info << " ";
    duyetTruoc(T->LP);
    duyetTruoc(T->RP);
}

void duyetGiua(Tree T) {
    if (T == NULL) return;
    duyetGiua(T->LP);
    cout << T->info << " ";
    duyetGiua(T->RP);
}

void duyetSau(Tree T) {
    if (T == NULL) return;
    duyetSau(T->LP);
    duyetSau(T->RP);
    cout << T->info << " ";
}
int main() {
    Tree T;
    initTree(T);

    T = taoNode('A');
    themTrai(T,'B');
    themPhai(T,'C');
    themTrai(T->LP,'D');
    themPhai(T->LP,'E');
    themTrai(T->RP,'F');
    themPhai(T->RP,'G');

    duyetTruoc(T); cout << endl;
    duyetGiua(T); cout << endl;
    duyetSau(T); cout << endl;
}
