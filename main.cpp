#include "defs.h"
#define extern_
#include "data.h"
#undef extern_
#include "decl.h"
#include <errno.h>
#include<iostream>
using namespace std;
static void init()
{
    Line = 1;
    Putback = '\n';
}

string tokstr[] = {"+", "-", "*", "/", ";", "int", "double", "char", "EOF", "display"};

static void scanfile()
{
    struct token T;
    while (scan(&T))
    {
        cout<<"Token "<<tokstr[T.token];
        if (T.token == T_INT)
            cout<<", value "<<T.intvalue;
        cout<<endl;
    }
}


int  main(int argc, char *argv[])
{
    struct ASTnode *n;
    if (argc != 2)
    {
        cout<<"Usage: "<<argv[0]<<" infile"<<endl;
        exit(1);
    }
        

    init();

    if ((Infile = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
        exit(1);
    }

    scan(&Token);
    n= compound_statement();
    // int value=interpretAST(n);
    // cout<<"value is "<<value<<endl;


    exit(0);
}