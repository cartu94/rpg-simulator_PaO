#ifndef DEEPPTR_H
#define DEEPPTR_H

template <class T>
class DeepPtr
{
public:
    DeepPtr(const DeepPtr &dp);
    DeepPtr(T* p = 0);
    ~DeepPtr();

    T* get() const;
    void swap(DeepPtr& dp);

    T* release();
    void reset(T* ptr = 0);

    T& operator*() const;
    T* operator->() const;
    DeepPtr& operator=(const DeepPtr& dp);
    bool operator!() const;
    bool operator ==(const DeepPtr& dp) const;
    bool operator !=(const DeepPtr& dp) const;
    operator bool() const;

private:
    T* ptr;
};

template <class T>
DeepPtr<T>::DeepPtr(T* p): ptr(p ? p->clone() : nullptr) {}

template <class T>
DeepPtr<T>::DeepPtr(const DeepPtr& dp) {
    if(dp.get()){
        ptr = dp.get()->clone();
    } else {
        ptr = nullptr;
    }
}

template <class T>
DeepPtr<T>::~DeepPtr(){
    if(ptr){
        delete ptr;
    }
}

template <class T>
T* DeepPtr<T>::get() const {
    return ptr;
}

template <class T>
T* DeepPtr<T>::release() {
    T* tmp = ptr;
    ptr = nullptr;
    return tmp;
}

template <class T>
void DeepPtr<T>::reset(T *p) {
    if(ptr){
        delete this;
    }
    ptr = p;
}

template <class T>
void DeepPtr<T>::swap(DeepPtr &dp) {
    T* tmp = ptr;
    ptr = dp.ptr;
    dp.ptr = tmp;
}

template <class T>
T& DeepPtr<T>::operator*() const {
    return *ptr;
}

template <class T>
T* DeepPtr<T>::operator->() const {
    return ptr;
}

template <class T>
DeepPtr<T>& DeepPtr<T>::operator=(const DeepPtr &dp){
    if(this != &dp){
        if(!dp){
            reset();
        } else {
            reset(dp.get()->clone());
        }
    }
    return *this;
}

template <class T>
bool DeepPtr<T>::operator!() const{
    return !ptr;
}

template <class T>
bool DeepPtr<T>::operator==(const DeepPtr &dp) const {
    return *ptr == *(dp.ptr);
}

template <class T>
bool DeepPtr<T>::operator !=(const DeepPtr& dp) const {
    return !(*this == dp);
}

template <class T>
DeepPtr<T>::operator bool() const {
    return ptr;
}

#endif // DEEPPTR_H
