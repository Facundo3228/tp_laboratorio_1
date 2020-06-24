#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int tam, i;

    if(this != NULL)
    {
        tam = this->size;

        if(this != NULL && nodeIndex >= 0 && nodeIndex < tam)
        {
            pNode = this->pFirstNode;

            for(i = 0; i < nodeIndex; i++)
            {
                pNode = pNode->pNextNode;
            }
        }
    }

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    int returnAux = -1;

    Node* pNuevoNode = malloc(sizeof(Node));
    Node* pActualNode = NULL;
    pNuevoNode->pElement = pElement;

    int tam;

    if(this != NULL && pNuevoNode != NULL)
    {
        tam = ll_len(this);
        if(nodeIndex >= 0 && nodeIndex <= tam)
        {
            if(nodeIndex == 0)
            {
                pNuevoNode->pNextNode = this->pFirstNode;
                this->pFirstNode = pNuevoNode;
            }
            else
            {
                pActualNode = getNode(this, nodeIndex-1);
                pNuevoNode->pNextNode = pActualNode->pNextNode;
                pActualNode->pNextNode = pNuevoNode;
            }
            returnAux = 0;
            this->size++;
        }
    }

    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex, void* pElement)
{
    return addNode(this, nodeIndex, pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int indice = ll_len(this);
    Node* pActualNode = addNode(this, indice, pElement);

    if(this != NULL)
    {

        returnAux = pActualNode;
    }

    return returnAux;
}


//  ******* OJO CORREGIR *******************
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNuevoNode;
    int tam;

    if(this != NULL)
    {
        tam = ll_len(this);
        if(index >= 0 && index < tam)
        {
            pNuevoNode = getNode(this, index);
            if(pNuevoNode != NULL)
            {
                returnAux = pNuevoNode->pElement;
            }
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    Node* pNuevoNode;
    int tam;

    if(this != NULL)
    {
        tam = ll_len(this);
        if(index >= 0 && index < tam)
        {
            pNuevoNode = getNode(this, index);
            if(pNuevoNode != NULL)
            {
                pNuevoNode->pElement = pElement;
                returnAux = 0;
            }
        }
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this, int index)
{
    int returnAux = -1;
    Node* pActualNode;
    Node* pSigienteNode;

    if(this != NULL)
    {

        if(index >= 0 && index < this->size)
        {
            returnAux = 0;
            if(this->size == 1)
            {
                this->pFirstNode = NULL;
                free(getNode(this, index));
            }
            else if(index == 0)
            {
                pActualNode = getNode(this, index);
                this->pFirstNode = pActualNode->pNextNode;
                free(pActualNode);
            }
            else
            {
                pActualNode = getNode(this, index);
                if(pActualNode != NULL)
                {
                    pSigienteNode = getNode(this, index-1);
                    pSigienteNode->pNextNode = pActualNode->pNextNode;
                    free(pActualNode);
                }
            }
        }

        this->size--;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int tam;
    int i;

    if(this != NULL)
    {
        tam = ll_len(this);
        for(i = 0; i < tam; i++)
        {
            ll_remove(this, i);
        }
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(ll_clear(this) == 0)
        {
            free(this);
            returnAux= 0;
        }
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;
    int i;
    int tam;

    if(this != NULL)
    {
        tam = ll_len(this);
        for(i = 0; i < tam; i++)
        {
            pNode = getNode(this, i);
            if(pNode->pElement == pElement)
            {
                returnAux= i;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(ll_len(this))
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int tam;

    if(this != NULL)
    {
        tam = ll_len(this);
        if(index >= 0 && index <= tam)
        {
            returnAux = addNode(this, index, pElement);
        }
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int tam;

    if(this != NULL)
    {
        tam = ll_len(this);
        if(index >= 0 && index <= tam)
        {
            returnAux= ll_get(this, index);
            ll_remove(this, index);
        }
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if (ll_indexOf(this, pElement) == -1)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }

    return returnAux;
}


/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this, LinkedList* this2)
{
    int i;
    int tamUno;
    int tamDos;
    int contador = 0;
    int returnAux = -1;

    void* pElementAux;

    if(this!=NULL && this2!=NULL)
    {
        tamUno= ll_len(this);
        tamDos= ll_len(this2);

        returnAux = 0;

        if(tamUno >= tamDos)
        {
            for(i = 0 ; i < tamDos; i++)
            {
                pElementAux = ll_get(this2, i);
                if(ll_contains(this, pElementAux) == 1)
                {
                    contador++;
                }
            }
            if(contador == tamUno)
            {
                returnAux = 1;
            }
        }
    }

    return returnAux;
}


/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this, int from, int to)
{
    LinkedList* cloneArray = NULL;

    int i;
    int tam;
    int nuevaLista = 0;


    Node* pNode;
    Node* pElemento = NULL;

    if(this != NULL)
    {
        tam = ll_len(this);
        if(from >= 0 && from <= tam && to >= 0 && to <= tam)
        {
            cloneArray = ll_newLinkedList();
            for(i = from; i < to; i++)
            {
                pNode = getNode(this, i);
                if(pNode != NULL)
                {
                    pElemento = pNode->pElement;
                    addNode(cloneArray, nuevaLista, pElemento);
                    nuevaLista++;
                }
            }
        }
    }

    return cloneArray;
}


/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    Node* tam = NULL;

    if(this != NULL)
    {
        tam = this->size;
        cloneArray = ll_subList(this, 0, tam);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;
    int i;
    int tam;
    int bandera;

    void* pAux;
    void* pDatoA;
    void* pDatoB;

    if(this != NULL)
    {
        if(pFunc != NULL)
        {
            if(order == 0 || order == 1)
            {
                tam = ll_len(this);
                if(tam > 0)
                {
                    do
                    {
                        bandera = 0;
                        for(i = 0; i < tam-1; i++)
                        {
                            pDatoA = ll_get(this, i);
                            pDatoB = ll_get(this, i+1);
                            if((pFunc(pDatoA, pDatoB) < 0 && order == 0) ||
                               (pFunc(pDatoA, pDatoB) > 0 && order == 1))
                            {
                                pAux= pDatoA;
                                ll_set(this, i, pDatoB);
                                ll_set(this, i+1, pAux);
                                bandera = 1;
                            }
                            returnAux = 0;
                        }
                    }
                    while(bandera);
                }
            }
        }
    }

    return returnAux;
}

