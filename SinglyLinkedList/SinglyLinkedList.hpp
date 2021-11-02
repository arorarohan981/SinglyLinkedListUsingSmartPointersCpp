//
//  SinglyLinkedList.hpp
//  SinglyLinkedList
//
//  Created by Rohan Arora on 31/10/21.
//

#ifndef SinglyLinkedList_hpp
#define SinglyLinkedList_hpp

#include <stdio.h>
#include <iostream>
#include <memory>
namespace mylib{

template <typename T>
class List{
    private :
    struct Node{
        T data;
        std::unique_ptr<Node> next;
        Node(T userdata){
            data=userdata;
        }
    };
    std::unique_ptr<Node> head;
    size_t numberOfNodes;
    
public:
    /* Appends the T type of element at the end of List*/
    void append(const T &data);
    
    //Prints the Entire List.
    void print();

    //Check whether the List is Empty.Returns true if list is Empty
    bool isEmpty();
    
    //Removes the Element from the Specified Position in the List and return true or else false.
    bool remove(size_t position);
    
    //Removes the First element from the List which matches the Param and return true or else false.
    bool remove(const T &elementToRemove);
    
    
    
    //Searches the data passed in Parameter.Returns True if the data is found or else false.
    bool search(T userData);
    
    //Resets the list.
    void resetList();
    
    
};
template <typename T>
void List<T>::resetList(){
    head.reset();
}

template <typename T>
bool List<T>::search(T userData){
    if(isEmpty()){
        std::cout<<"List is Empty "<<std::endl;
        return false;
    }
    Node *iterptr=head.get();
    if(iterptr->data==userData){
        return true;
    }
    while(iterptr->next!=nullptr){
        iterptr=iterptr->next.get();
        if(iterptr->data==userData){
            return true;
        }
    }
    if(iterptr->data==userData){
        return true;
    }
    return false;
}



template <typename T>
void List<T>::append(const T &data){
    std::unique_ptr<Node> newNode=std::make_unique<Node>(data);
    if(isEmpty()){
        head=std::move(newNode);
        numberOfNodes++;
    }else{
        Node *temp=head.get();
        while(temp->next!=nullptr){
            temp=temp->next.get();
        }
        temp->next=std::move(newNode);
        numberOfNodes++;
    }
}
template <typename T>
void List<T>::print(){
    if(isEmpty()){
        throw std::range_error("List is Empty ");
    }else{
    std::cout<<"Elements in the List are as Follows \n";
    Node *iterateNode=head.get();
    while(iterateNode->next!=nullptr){
        std::cout<<iterateNode->data<<std::endl;
        iterateNode=iterateNode->next.get();
    }
        std::cout<<iterateNode->data<<std::endl;
    
    }

}

template <typename T>
bool List<T>::isEmpty(){
    if(head==nullptr){
        return true;
    }
    return false;
}

template <typename T>
bool List<T>::remove(size_t position){
   
    if(isEmpty()){
        std::cout<<"List is Empty "<<std::endl;
        return false;
    }
    else{
    if(position>=numberOfNodes){
        std::cout<<"Position Entered is out of the List ";
        return false;
    }else{
        size_t counter{0};
        Node *iterptr= head.get();
        if(position==0){
            head=std::move(iterptr->next);
            numberOfNodes--;
            return true;
        }
        counter++;
        while(counter<=position-1){
            iterptr=iterptr->next.get();
            counter++;
        }
        iterptr->next=std::move(iterptr->next->next);
        numberOfNodes--;
        return true;
    }
}
}

template <typename T>
bool List<T>::remove(const T &elementToRemove){
    if(isEmpty()){
        std::cout<<"List is Empty "<<std::endl;
        return false;
    }else{
        Node* iterptr=head.get();

        //if the element to remove is the First Node
        if(iterptr->data==elementToRemove){
            if(numberOfNodes>1){
                head=std::move(iterptr->next);
            }else{
                head.reset();
            }
            numberOfNodes--;
            return true;
        }
        while (iterptr->next!=nullptr) {
            if(iterptr->next->data==elementToRemove){
                iterptr->next=std::move(iterptr->next->next);
                numberOfNodes--;
                return true;
            }
            iterptr=iterptr->next.get();

        }
        return false;
    }
}

}
#endif /* SinglyLinkedList_hpp */

