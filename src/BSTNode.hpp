#ifndef BSTNODE_HPP
#define BSTNODE_HPP

#include <functional>   //used for hashing
#include <vector>       //used to get all values in one vector

template<typename Val>
class BSTNode{
public:
    BSTNode(int hashedKey, Val value){
        m_hash = hashedKey;
        m_value = value;
    }
    ~BSTNode(){
        if (m_left){
            delete m_left;
        }
        if (m_right){
            delete m_right;
        }
    }
    Val * getValue(int hashedKey){
        if (m_hash == hashedKey){
            return &m_value;
        }else if (m_hash > hashedKey && m_left){
            return m_left->getValue(hashedKey);
        }else if(m_right){
            return m_right->getValue(hashedKey);
        }
        return nullptr;
    }

    void insert(int hashedKey, Val value){
        if (m_hash == hashedKey){
            m_value = value;
            return;
        }
        if (m_hash > hashedKey){
            if (m_left){
                m_left->insert(hashedKey, value);
                return;
            }
            m_left = new BSTNode<Val>(hashedKey, value);
        } else {
            if (m_right){
                m_right->insert(hashedKey, value);
                return;
            }
            m_right = new BSTNode<Val>(hashedKey, value);
        }
    }
    std::vector<Val> getAllValues(){
        std::vector<Val> allValues;
        if (m_left && !m_right){
            auto leftValues = m_left->getAllValues();
            allValues.insert(allValues.end(), leftValues.begin(), leftValues.end());
        }
        allValues.push_back(m_value);
        if (!m_left && m_right){
            auto rightValues = m_right->getAllValues();
            allValues.insert(allValues.end(), rightValues.begin(), rightValues.end());
        }
        return allValues;
    }

protected:
    int m_hash;
    Val m_value;
    BSTNode<Val> * m_left = nullptr;
    BSTNode<Val> * m_right = nullptr;
};






#endif