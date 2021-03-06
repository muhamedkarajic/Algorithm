#pragma once

#include "Cvor.h"
#include "Stek.h"

template <class Type>
class StackLinked : public Stack<Type>
{
  private:
    Node<Type> *node;

  public:
    StackLinked()
    {
        node = nullptr;
    }
    void add(Type v)
    {
        Node<Type> *n = new Node<Type>(v, node);
        node = n;
    }

    Type remove()
    {
        if (isEmpty())
            throw exception("Greska. Nije moguce ukloniti elemenat iz praznog steka.");

        Node<Type> *t = node;

        node = node->next;
        Type x = t->info;
        delete t;
        return x;
    }

    Type top()
    {
        if (isEmpty())
            throw exception("Greska. Nije moguce uzeti elemenat iz praznog steka.");

        return node->info;
    }

    bool isEmpty()
    {
        return node == nullptr;
    }

    void print(string pre = "", string post = ", ")
    {
        Node<Type> *t = node;
        while (t != nullptr)
        {
            cout << pre << t->info << post;
            t = t->next;
        }
    }

    virtual bool contains(Type value)
    {
        Node<Type> *t = node;
        while (t != nullptr)
        {
            if (isEqual(t->info, value))
                return true;
        }
        return false;
    }
};
