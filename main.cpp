#include<iostream>
#include<string>
#include<stdlib.h>
#include<new>
#include<locale.h>
#include<time.h>

using namespace std;

#include "functions.h"

int main (void) {

    srand((unsigned)time(NULL));

    setlocale(LC_ALL,"");

    menuInicial();

    return 0;
}
