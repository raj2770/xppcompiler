#include "defs.h"
#include "data.h"
#include "decl.h"
#include<iostream>
using namespace std;
// List of AST operators

int interpretAST(struct ASTnode *n)
{
    int value;
    switch (n->op)
    {
        case T_PLUS:
            value = interpretAST(n->left) + interpretAST(n->right);
            break;
        case T_MINUS:
            value = interpretAST(n->left) - interpretAST(n->right);
            break;
        case T_STAR:
            value = interpretAST(n->left) * interpretAST(n->right);
            break;
        case T_SLASH:
            value = interpretAST(n->left) / interpretAST(n->right);
            break;
        case T_INT:
            value = n->v.intvalue;
            break;
        default:
            fatal("Unknown AST operator");
    }
    return value;
}