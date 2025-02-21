

#ifndef SLLIST_H
#define SLLIST_H

#include <stdexcept>
#include <iostream>

template <typename Key, typename Info>
class SinglyLinkedList {
private:
    struct Node {
            Key key;
            Info info;
            Node* nxt;
            Node(const Key& k, const Info& i) : key(k), info(i), nxt(nullptr) {}
        };
    Node* head;
    Node*tail=nullptr;
    void copy(const SinglyLinkedList& src) {
        Node* curr = src.head;
        
        if(curr==nullptr){
            head=nullptr;
            tail=nullptr;
            return;}
        else{
            head=new Node(curr->key,curr->info);
            tail=head;
            curr=curr->nxt;
            while(curr!=nullptr){
                tail->nxt = new Node(curr->key,curr->info);
                tail=tail->nxt;
                curr=curr->nxt;}}
    }  
    friend class SinglyLinkedListTest; 

public:
    

    SinglyLinkedList() : head(nullptr), tail(nullptr) {}

    SinglyLinkedList(const SinglyLinkedList& src) : head(nullptr), tail(nullptr) {
        copy(src);
    }

    ~SinglyLinkedList() {
        clear();
    }

    SinglyLinkedList& operator=(const SinglyLinkedList& src) {
        if (this == &src) {
            return *this;
        }
        clear();
        copy(src);
        return *this;
    }

    unsigned int size() const {
        int size = 0;
        Node* current = head;
        while (current != nullptr) {
            size += 1;
            current = current->nxt;
        }
        return size;
    }

    void push_front(const Key& key, const Info& info) {
        Node* added = new Node(key, info);
        added->nxt = head;
        head = added;
        if (tail == nullptr) { 
            tail = head;}
    }

    bool pop_front() {
        if (head == nullptr) {
            return false;
        }
        Node* curr = head;
        head = head->nxt;
        delete curr;
        if (head == nullptr) {
            tail = nullptr;
        }
        return true;
    }
    Node* get_last(){
        return tail;
    }

    bool is_Empty() const{
        return (head == nullptr);
    }
    bool exists_node(const Key& key, const Info& info){
        
        Node* current = head;
        while(current!=nullptr){
            if(current->key==key && current->info==info){
                return true;
            }
            current=current->nxt;
        }
        return false;


    }

    void clear() {
        while (head != nullptr) {
            Node* current = head;
            head = head->nxt;
            delete current;
            
        }
        tail=nullptr;
    }

    void push_back(const Key& key, const Info& info) {
        Node* added = new Node(key, info);
        if (head == nullptr) {
            head = added;
            tail=added;
        } else {
            
            tail->nxt = added;
            tail=added;
        }
    }

    bool insert_After(const Key& key, const Key& newkey, const Info& newinfo) {
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                Node* added = new Node(newkey, newinfo);
                added->nxt = current->nxt;
                current->nxt = added;
                if (current == tail) {
                    tail = added;}
                return true;
            }
            current = current->nxt;
        }
        return false;
    }
    int count_key(const Key& key){
        int count = 0;
        for (Node* current = head; current; current = current->nxt)
           { if (current->key == key){ count++;}}
        return count;
    }
     int count_info(const Info& info){
        int count = 0;
        for (Node* current = head; current; current = current->nxt)
            {if (current->info == info)
             {count++;}}
        return count;
    }
    Info& get(const Key& key, int occurrence = 1) {
        Node* current = head;
        int count = 0;
        while (current != nullptr) {
            if (current->key == key) {
                count += 1;
                if (count == occurrence) {
                    return current->info;
                }
            }
            current = current->nxt;
        }
        throw std::out_of_range("Key not found.");
    }

    bool front(const Key& key, const Info& info) {
        if (head != nullptr && head->key == key && head->info == info) {
            return true;}
        return false;
    }
    void remove(const Key& key){
        if (head == nullptr) {
            throw std::out_of_range("List is empty.");}
        if (head->key == key) {
        Node* temp = head;
        head = head->nxt;
        delete temp;
        if (head == nullptr) {
            tail = nullptr;
        }
        return;
    }
    Node* current = head;
     while (current->nxt) {
        if (current->nxt->key == key) {
            Node* temp = current->nxt;
            current->nxt = current->nxt->nxt;
            delete temp;
            if (!current->nxt) {
                tail = current;
            }
        } else {
            current = current->nxt;
        }
    }
}
    void print(){
        Node* current=head;
        while(current!=nullptr){
            std::cout<< "info:"<<current->info << "key" <<current->key <<std::endl;
            current=current->nxt;
        }
    }
    
    bool info_exists(const Info& info){
        Node* current=head;
        while (current != nullptr) {
            if (current->info == info) {
                return true;}
            current=current->nxt;
        }
        return false;


    }
    bool key_exists(const Key& key){
        Node* current=head;
        while (current != nullptr) {
            if (current->key == key) {
                return true;}
            current=current->nxt;
        }
        return false;


    }
    Node* get_first() const {
        return head;
    }
    Node* find_key(const Key& key){
        Node*current=head;
        while(current!=nullptr){
            if(current->key==key){
                return current;
            }
            current=current->nxt;
        }
        return nullptr;
    }
    Node* find_info(const Info& info){
        Node*current=head;
        while(current!=nullptr){
            if(current->info==info){
                return current;
            }
            current=current->nxt;
        }
        return nullptr;
    }


    
    bool operator==(const SinglyLinkedList& src) const{
        if(this->size()!=src.size()){
            return false;}
        if(is_Empty()&&src.is_Empty()){
            return true;}
        Node* current=this->head;
        Node* other = src.get_first();
        while(current!=nullptr){
            if(current->key != other->key || current->info != other->info){
                return false;}
            current=current->nxt;
            other=other->nxt;}
        return true;
    }
    bool operator!=(const SinglyLinkedList& src) const{
         return !(*this == src);}
    // bool pop_back(){
    //     if(is_Empty()){
    //         return false;
    //     }
    //     if(head->nxt==nullptr){
    //         delete head;
    //         head=nullptr;
    //         return true;
    //     }
    //     Node* current=head->nxt;
    //     Node* before=head;

    //     while(current->nxt!=nullptr){
    //         current=current->nxt;
    //         before=before->nxt;
    //     }
    //     delete current;
    //     before->nxt=nullptr;
    //     return true;

    // }
    void reverse_list(){
       
        Node*current = head;
        Node* before=nullptr;
        Node* after=nullptr;
        tail=head;
        while(current!=nullptr){
            after=current->nxt;
            current->nxt=before;
            before=current;
            current=after;
        }
        head=before;
    }
    void remove_all_key(const Key& key){
    //     int count= count_key(key);
    //     for(int i=0;i<count;i++){
    //         remove(key);
    //     }
    // }
    //smaller complexity
    while (head && head->key == key) {
        Node* temp = head;
        head = head->nxt;
        delete temp;}
    if (!head) {
        tail = nullptr;
        return;}
    Node* current = head;
    while (current->nxt) {
        if (current->nxt->key == key) {
            Node* temp = current->nxt;
            current->nxt = current->nxt->nxt;
            delete temp;
            if (!current->nxt) {
                tail = current;}} 
            else {
            current = current->nxt;}}
}


    void testCopy(const SinglyLinkedList& src) {
        copy(src);
    }


    
};



template <typename Key, typename Info>
void concatenate(SinglyLinkedList<Key, Info>& seq1, SinglyLinkedList<Key, Info>& seq2,
                 unsigned int len1, unsigned int len2, SinglyLinkedList<Key, Info>& seq) {
    if (len1 == 0 && len2 == 0) {
         while (!seq1.is_Empty()) {
            seq1.pop_front();
        }
        while (!seq2.is_Empty()) {
            seq2.pop_front();
        }
        return; 
    }                 
    while (!seq1.is_Empty() || !seq2.is_Empty()) {
        int count = 0;
        while (!seq1.is_Empty() && count < len1) {
            seq.push_back(seq1.get_first()->key, seq1.get_first()->info);
            seq1.pop_front();
            count++;
        }

        count = 0;
        while (!seq2.is_Empty() && count < len2) {
            seq.push_back(seq2.get_first()->key, seq2.get_first()->info);
            seq2.pop_front();
            count++;
        }
    }
}

#endif // SLLIST_H
