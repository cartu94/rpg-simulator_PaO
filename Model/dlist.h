#ifndef DLIST_H
#define DLIST_H

template <class T>
class DList
{
    friend class Iterator;
private:
    class Node {
    public:
        T info;
        Node *prev, *next;

        Node(const T& data, Node* p = 0, Node* n = 0);
    };

    static void destroy(Node*& n);
    static void deep_copy(Node* src, Node*& fst, Node*& lst);

    Node *first, *last;
    int size;

public:
    DList();
    DList(const DList& l);
    ~DList();
    DList& operator=(const DList& l);

    void pushFront(const T& data);
    void pushBack(const T& data);
    void popFront();
    void popBack();
    void popIndex(int index);
    int findIndex(const T& data);

    int getSize() const;

    class Iterator {
        friend class DList<T>;
    private:
        Node* ptr;
        bool past_the_end;

        Iterator(Node* p, bool pte = false);

    public:
        Iterator();

        Iterator& operator++();
        Iterator operator++(int);
        Iterator& operator--();
        Iterator operator--(int);
        bool operator==(const Iterator& it) const;
        bool operator!=(const Iterator& it) const;
        T& operator*() const;
        T* operator->() const;
    };

    Iterator begin() const;
    Iterator end() const;
};

template <class T>
void DList<T>::destroy(Node*& n) {
    if(n) {
        destroy(n->next);
        delete n;
        n = nullptr;
    }
}

template <class T>
void DList<T>::deep_copy(Node* src, Node*& fst, Node*& lst) {
    if(src) {
        fst = lst = new Node(src->info);
        Node* src_sc = src->next;
        while(src_sc){
            lst = new Node(src_sc->info, lst);
            lst->prev->next = lst;
            src_sc = src_sc->next;
        }
    } else {
        fst = lst = nullptr;
    }
}

template <class T>
DList<T>::Node::Node(const T &data, Node *p, Node *n): info(data), prev(p), next(n) {}

template <class T>
DList<T>::DList(): first(nullptr), last(nullptr), size(0) {}

template <class T>
DList<T>::DList(const DList &l) {
    deep_copy(l, first, last);
    size = l.size;
}

template <class T>
DList<T>& DList<T>::operator=(const DList& l) {
    if(this != &l) {
        destroy(first);
        deep_copy(l.first, first, last);
    }
    return *this;
}

template <class T>
DList<T>::~DList() {
    destroy(first);
}

template <class T>
void DList<T>::pushFront(const T &data) {
    first = new Node(data, nullptr, first);
    if(first->next == nullptr) {
        last = first;
    } else {
        (first->next)->prev = first;
    }
    size++;
}

template <class T>
void DList<T>::pushBack(const T &data) {
    if(last){
        last = new Node(data, last, nullptr);
        (last->prev)->next = last;
    } else {
        first = last = new Node(data);
    }
    size++;
}

template <class T>
void DList<T>::popFront() {
    if(first) {
        if(first != last) {
            Node* n = first;
            first = first->next;
            first->prev = nullptr;
            n->next = nullptr;
            delete n;
        } else {
            delete first;
            first = last = nullptr;
        }
        size--;
    }
}

template <class T>
void DList<T>::popBack() {
    if(last) {
        if(last != first) {
            Node* n = last;
            last = last->prev;
            last->next = nullptr;
            delete n;
        } else {
            delete last;
            last = first = nullptr;
        }
        size--;
    }
}

template <class T>
void DList<T>::popIndex(int index) {
    if(index < size){
        if(index == 0) popFront();
        else if(index == size-1) popBack();
        else {
            Node* n = first->next;
            for(int i = 1; i < index; i++){
                n = n->next;
            }
            (n->prev)->next = n->next;
            (n->next)->prev = n->prev;
            n->next = nullptr;
            delete n;
            size--;
        }
    }
}

template <class T>
int DList<T>::findIndex(const T& data){
    if(first->info == data) return 0;
    if(last->info == data) return size-1;
    Node* n = first->next;
    for(int i = 1; i < size; ++i){
        if(n->info == data) return i;
        n = n->next;
    }
    return -1;
}

template <class T>
int DList<T>::getSize() const {
    return size;
}

// Iterator ---------------------------------------------
template <class T>
DList<T>::Iterator::Iterator(Node *p, bool pte): ptr(p), past_the_end(pte) {}

template <class T>
DList<T>::Iterator::Iterator(): ptr(nullptr), past_the_end(false) {}

template <class T>
typename DList<T>::Iterator& DList<T>::Iterator::operator++(){
    if(ptr != nullptr) {
        if(!past_the_end) {
            if(ptr->next != nullptr) {
                ptr = ptr->next;
            } else {
                ptr = ptr + 1;
                past_the_end = true;
            }
        }
    }
    return *this;
}

template <class T>
typename DList<T>::Iterator DList<T>::Iterator::operator++(int){
    Iterator aux(*this);
    if(ptr != nullptr) {
        if(!past_the_end) {
            if(ptr->next != nullptr) {
                ptr = ptr->next;
            } else {
                ptr = ptr + 1;
                past_the_end = true;
            }
        }
    }
    return aux;
}

template <class T>
typename DList<T>::Iterator& DList<T>::Iterator::operator--(){
    if(ptr != nullptr) {
        if(ptr->prev == nullptr){
            ptr = nullptr;
        } else if(!past_the_end) {
            ptr = ptr->prev;
        } else {
            ptr = ptr -1;
            past_the_end = false;
        }
    }
    return *this;
}

template <class T>
typename DList<T>::Iterator DList<T>::Iterator::operator--(int){
    Iterator aux(*this);
    if(ptr != nullptr) {
        if(ptr->prev == nullptr){
            ptr = nullptr;
        } else if(!past_the_end) {
            ptr = ptr->prev;
        } else {
            ptr = ptr -1;
            past_the_end = false;
        }
    }
    return aux;
}

template <class T>
bool DList<T>::Iterator::operator==(const Iterator& it) const {
    return ptr == it.ptr;
}

template <class T>
bool DList<T>::Iterator::operator!=(const Iterator& it) const {
    return ptr != it.ptr;
}

template <class T>
T& DList<T>::Iterator::operator*() const {
    return ptr->info;
}

template <class T>
T* DList<T>::Iterator::operator->() const {
    return &(ptr->info);
}

template <class T>
typename DList<T>::Iterator DList<T>::begin() const {
    return Iterator(first);
}

template <class T>
typename DList<T>::Iterator DList<T>::end() const {
    if(!last) return Iterator();
    return Iterator(last+1, true);
}

#endif // C_H
