#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo
{
    int dato;
    struct _nodo *izq;
    struct _nodo *der;
} nodo;

void inorder(nodo *n);
void preorder(nodo *n);
void postorder(nodo *n);
void agregarNodo(nodo **n, int value);
void agregar (nodo **n, nodo *tmp);

int main(void)
{
    nodo *arbol = NULL;
    agregarNodo(&arbol, 12);
    agregarNodo(&arbol, 20);
    agregarNodo(&arbol, 7);
    printf("Inorder\n");
    inorder(arbol);
    printf("Preorder\n");
    preorder(arbol);
    printf("Postorder\n");
    postorder(arbol);
    return EXIT_SUCCESS;
}

void inorder(nodo *n)
{
    if (n->izq)
    {
        inorder(n->izq); // RAMA IZQUIERDA
    }
    printf("%d\n", n->dato);
    if (n->der)
    {
        inorder(n->der); // RAMA DERECHA
    }
}

void preorder(nodo *n)
{
    printf("%d\n", n->dato);
    if (n->izq)
    {
        preorder(n->izq); // RAMA IZQUIERDA
    }
    if (n->der)
    {
        preorder(n->der); // RAMA DERECHA
    }
}

void postorder(nodo *n)
{
    if (n->izq)
    {
        postorder(n->izq); // RAMA IZQUIERDA
    }
    if (n->der)
    {
        postorder(n->der); // RAMA DERECHA
    }
    printf("%d\n", n->dato);
}

void agregarNodo(nodo **n, int value)
{
    nodo *tmp = malloc(sizeof(nodo));
    tmp->dato = value;
    tmp->izq = NULL;
    tmp->der = NULL;
    agregar(n, tmp);
}

void agregar(nodo **n, nodo *tmp)
{
    if ((*n) == NULL)
    {
        (*n) = tmp;
        return;
    }
    if ((*n)->dato < tmp->dato)
    {
        // VOY A LA DERECHA
        agregar(&((*n)->der), tmp);
    }
    else if ((*n)->dato > tmp->dato)
    {
        // VOY A LA IZQUIERDA

        agregar(&((*n)->izq), tmp);
    }
    else
    {
        free(tmp);
    }
}
