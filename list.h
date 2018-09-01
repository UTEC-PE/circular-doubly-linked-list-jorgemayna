#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* start;
        int nodes;

    public:
        List();

        T front();
        T back();
        void push_front(T value);
        void push_back(T value);
        void pop_front();
        void pop_back();
        T get(int position);
        void concat(List<T> &other);
        bool empty();
        int size();
        void clear();
        Iterator<T> begin();
        Iterator<T> end();



        ~List();
};

template<class T> List<T>::List()
{

    start=NULL;
    nodes=0;

}

template<typename T> T List<T>::front()
{

    return(start->data);

}

template<typename T> T List<T>::back()
{

    return(start->prev->data);

}

template<typename T> void List<T>::push_front(T value)
{
    Node<T>* temp = new Node<T>;
    temp->data=value;

    if (start==NULL)
    {

        start=temp;
        start->next=start;
        start->prev=start;

    }
    temp->prev=start->prev;
    temp->next=start;
    start->prev=temp;
    start=temp;
    nodes++;
    temp=NULL;




}

template<typename T> void List<T>::push_back(T value)
{
    //  INCOMPLETO
    Node<T>* temp = new Node<T>;
    temp->data=value;
    temp->next=start;

    nodes++;
    if (start==NULL)
    {

        start=temp;
        temp->prev=start;
    }else{
        start->prev->next=temp;
        temp->prev=start->prev;
        start->prev=temp;
    }


    temp=NULL;



}
template<typename T> void List<T>::pop_front()
{
    if(nodes!=1)
    {
        Node<T>* temp=start->next;
        temp->prev=start->prev;
        start->prev->next=temp;
        delete start;
        start=temp;
        temp=NULL;

        nodes--;


    }else{


        delete start;
        nodes=0;

    }
}

template<typename T> void List<T>::pop_back()
{

    if(nodes!=1)
    {
        Node<T>* temp=start->prev->prev;

        temp->next=start;

        delete start->prev;
        start->prev=temp;

        temp=NULL;

        nodes--;


    }else{

        delete start;
        nodes=0;
    }
}

template<typename T> void List<T>::concat(List<T> &other)
{

    if(!empty())
    {
        Node<T>* temp=start->prev;
        start->prev->next=other.start;
        other.start->prev->next=start;
        start->prev=other.start->prev;
        other.start->prev=temp;
        temp=NULL;



    }
    else{
        start=other.start;
        start->prev=other.start->prev;
    }
    nodes=nodes+other.nodes;

}

template<typename T> int List<T>::size()
{
    return nodes;
}

template<typename T> bool List<T>::empty()
{
    bool a=true;
    if(start==NULL)
    {
        return a;
    }else{
        return !a;
    }

}

template<typename T> T List<T>::get(int position)
{
    Node<T>* temp=start;
    T rpta;
    for(int x=0;x!=position;x++)
    {

        rpta=temp->data;
        temp=temp->next;
    }
    temp= NULL;

    return rpta;

}

template<typename T> void List<T>::clear()
{
    if(!empty())
    {
        while(start!=start->prev)
        {
            pop_front();

        }


        delete start;
        start=NULL;
        nodes--;



    }
}

template<typename T> Iterator<T> List<T>::begin()
{
    Iterator<T> temp(start);


    return temp;

}

template<typename T> Iterator<T> List<T>::end()
{
    Iterator<T> temp(start->prev);


    return temp;

}

template<class T> List<T>::~List()
{

    clear();


}



#endif
