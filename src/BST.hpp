#ifndef BST_HPP
#define BST_HPP

#include "BSTNode.hpp"

template<typename Key, typename Val>
class BST{
private:
    int m_size = 0;
    BSTNode<Val> * m_root = nullptr;

public:
    BST(){}
    ~BST(){
        if (m_root){
            delete m_root;
        }
    }

    Val getValue(Key key){
        int hashedKey = std::hash<Key>()(key);
        auto returnValue = m_root->getValue(hashedKey);
        if (returnValue){
            return *returnValue;
        }
        throw "keyError";
    }
    void insert(Key key, Val value){
        m_size++;
        int hashedKey = std::hash<Key>()(key);
        if (m_root){
            m_root->insert(hashedKey, value);
            return;
        }
        m_root = new BSTNode<Val>(hashedKey, value);
    }
    std::vector<Val> getAllValues(){
        if (m_root){
            return m_root->getAllValues();
        }
        return std::vector<Val>();
    }
};





#endif