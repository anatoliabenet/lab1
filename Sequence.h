#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>

template <typename Key, typename Info>
class Sequence
{
    struct Node
    {
        Node *next;
        Key key;
        Info info;
    };
    Node *head;
    int size;

public:
    Sequence();
    ~Sequence();                                                   // destructor which deletes all nodes by calling clear()
    bool isEmpty() const;                                          // returns true if the sequence is without nodes
    int numOfOccurrences(Key key) const;                           // returns the number of occurrences of key in the sequence
    int getSize() const;                                           // returns the number of nodes in the sequence
    void pushBack(Key key, Info info);                             // add to the end
    void pushFront(Key key, Info info);                            // add to the beginning
    void add(Key key, Info info, Key prevKey, int prevOccurrence); // add after prevKey at occurrence prevOccurrence
    void remove(Key key, int occurrence = 0);                      // remove the occurrence-th node with key key
    void removeByPos(int position);                                     // remove node at position
    Info get(Key key, int occurrence = 0) const;                   // returns the info of the occurrence-th node with key key
    bool contains(Key key, int occurrence = 0) const;              // returns true if the occurrence-th node with key key exists
    int getPosition(Key key, int occurrence = 0) const;            // returns the position of the occurrence-th node with key key

    void clear(); // deletes all nodes

    void displayAll() const;                           // displays all nodes in the sequence
    void showNode(Key key, int occurrence = 0) const;  // displays the occurrence-th node with key key
    Sequence<Key, Info>(const Sequence<Key, Info> &x); // copy constructor
    Sequence<Key, Info> &operator=(const Sequence<Key, Info> &other);
    Sequence<Key, Info> operator+(const Sequence<Key, Info> &other);
    Sequence<Key, Info> operator-(const Sequence<Key, Info> &other);

    class Iterator
    {
    private:
        Node *current;
        Iterator(Node *node);

    public:
        Iterator(Iterator &other);
        Iterator &operator++();
        Iterator &operator++(int);
        bool operator==(const Iterator &other) const;
        bool operator!=(const Iterator &other) const;
        bool isLast() const; // returns true if the iterator points to the last node
        Iterator &operator=(const Iterator &other);
        std::pair<Key, Info> operator*() const;

        friend class Sequence;
    };

    Iterator begin() const; // returns an iterator pointing to the first node
};

#endif // SEQUENCE_H
