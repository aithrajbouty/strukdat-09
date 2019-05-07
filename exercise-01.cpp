#include <iostream>
using namespace std;

const int maxElemen = 255;
struct Stack{
    char isi[maxElemen];
    char TOP;
};
Stack S;

void createStack (Stack& S){
    S.TOP = -1;
}

void push(Stack& S, char elemenBaru){
    if(S.TOP == maxElemen-1){
        cout << "Tumpukan sudah penuh" << endl;
    }
    else{
        S.TOP = S.TOP + 1;
        S.isi[S.TOP] = elemenBaru;
    }
}

void pop(Stack& S, char& elemenHsl){
    if(S.TOP < 0){
        cout << "Tumpukan sudah kosong" << endl;
    }
    else{
        elemenHsl = S.isi[S.TOP];
        S.TOP = S.TOP - 1;
    }
}

void output(Stack& S){
    for(int i=S.TOP;i>=0;i--){
        cout << S.isi[i];
    }
}

int main()
{
    Stack s1, s2;
    int n;
    char x;

    cout << "Masukkan jumlah huruf : "; cin >> n;
    createStack(s1);

    cout << "Input: ";
    for(int i=0;i<n;i++){
        cin >> x;
        push(s1,x);
    }

    cout << "push: ";
    output(s1);

    createStack(s2);
    for (int i=s1.TOP;i>=0;i--){
        pop(s1,x);
        push(s2,x);
    }
    cout << endl;
    cout << "Reverse Stack: ";
    output(s2);
}
