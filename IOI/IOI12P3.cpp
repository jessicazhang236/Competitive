#include <bits/extc++.h>
using namespace std;
const int MAXQ = 1000004;
int ind;

typedef __gnu_cxx::rope<char> rc;

rc R[MAXQ];

void Init() {
    ind=1;
}

void TypeLetter(char L) {
    R[ind]=rc(R[ind-1]);
    R[ind].push_back(L);
    ++ind;
}

void UndoCommands(int U) {
    R[ind]=rc(R[ind - U - 1]);
    ++ind;
}

char GetLetter(int P) {
    return R[ind-1][P];
}
