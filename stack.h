#ifndef STACK_H
#define STACK_H
#include "sllist.h"

template <typename Key, typename Info>
class Stack {
public:
    Stack(){};
    ~Stack(){};
    bool pop(){
        return stack.pop_front();
    };
    void push(const Key& key, const Info& info){
        stack.push_back(key,info);

    };
    const Info& first() const {
        return stack.get_first()->info;
    };

    unsigned int size() const {
        return stack.size();}
    
    bool empty(){
        return stack.is_Empty();
    }


private:
    SinglyLinkedList<Key, Info> stack;
    
};

#endif