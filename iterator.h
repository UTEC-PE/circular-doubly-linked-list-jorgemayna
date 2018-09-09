#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class Iterator {
    private:
        Node<T>* current;

    public:
        Iterator();
        Iterator(Node<T>* node);

        Iterator<T> operator=(Iterator<T> node);
        bool operator!=(Iterator<T> cmp);
        Iterator<T> operator++();
        Iterator<T> operator--();
        T operator*();
};

template<class T> Iterator<T>::Iterator()
{
    //contructor
    current=NULL;
}
template<class T> Iterator<T>::Iterator(Node<T>* node)
{
    //constructor 2 xd
    current=node;

}
template<typename T> Iterator<T> Iterator<T>::operator=(Iterator<T> node)
{
    //sobrecargar de igual
    Iterator<T> temp;
    temp.current=node.current; // Estás creando un nuevo iterador, está mal
    return temp;
}
template<typename T> bool Iterator<T>::operator!=(Iterator<T> node)
{
    //sobrecarga
    
    if (current==node.current) // Podría ser return current != node.current;
    {
        return false;
        
        
        
    }
    else{
        return true;
        
        
        
    }

}


template<typename T> Iterator<T> Iterator<T>::operator++()
{
    //sobrecarga de sumador
    current=current->next;
    
    
    return *this;
}
template<typename T> Iterator<T> Iterator<T>::operator--()
{
    //sobrecargar de gg
    current=current->prev;
    
    
    return *this;
}
template<typename T> T Iterator<T>::operator*()
{
    //1+1=2
    return current->data;
}

#endif
