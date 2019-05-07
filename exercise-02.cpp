#include <iostream>
using namespace std;

struct ElemtList{
    char info;
    ElemtList* next;
};
typedef ElemtList* pointer;
typedef pointer Stack;

void CreateStack(Stack& Top){
    Top = NULL;
}

void CreateElement(pointer& pBaru){
    pBaru = new ElemtList;
    cout << "Masukkan stack: "; cin >> pBaru->info;
    pBaru->next = NULL;
}

void push(Stack& Top, pointer pBaru){
    if (Top==NULL){
        Top = pBaru;
    }
    else {
        pBaru->next = Top;
        Top = pBaru;
    }
}

void Pop(Stack& Top, pointer& pHapus){
    if (Top==NULL){
        cout << "Stack Kosong" << endl;
        pHapus = NULL;
    }
    else if(Top->next==NULL){
        pHapus = Top;
        Top = NULL;
    }
    else{
        pHapus = Top;
        Top = Top->next;
        pHapus->next = NULL;
    }
}

void traversal(Stack Top){
    pointer pBantu;
    if(Top==NULL){
        cout << "Stack Kosong";
    }
    else{
        pBantu=Top;
        do{
            cout << pBantu->info << " ";
            pBantu = pBantu->next;
        } while(pBantu != NULL);
    }
    cout << endl;
}

int main()
{
    pointer p;
    Stack s1, s2;
    int n;

    CreateStack(s1);

    cout << "Masukkan jumlah stack: "; cin >> n;
    for(int i=0;i<n;i++){
        CreateElement(p);
        push(s1,p);
    }

    cout << endl;
    cout << "Push : ";
    traversal(s1);

    CreateStack(s2);
    for (int i=n;i>0;i--){
        Pop(s1,p);
        push(s2,p);
    }
    cout << endl;
    cout << "Reverse Stack: ";
    traversal(s2);
}
