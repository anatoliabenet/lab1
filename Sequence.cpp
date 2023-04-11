#include "Sequence.h"
#include <iostream>

using namespace std;

template <typename Key, typename Info>
Sequence<Key, Info>::Sequence()
{
    this->head = nullptr;
    this->size = 0;
}

template <typename Key, typename Info>
Sequence<Key, Info>::~Sequence()
{
    this->clear();
}

template <typename Key, typename Info>
void Sequence<Key, Info>::pushBack(Key key, Info info)
{
    Node *newNode = new Node;
    newNode->key = key;
    newNode->info = info;
    newNode->next = nullptr;

    if (this->head == nullptr)
    {
        this->head = newNode;
    }
    else
    {
        Node *current = this->head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    this->size++;
}
template <typename Key, typename Info>
void Sequence<Key, Info>::pushFront(Key key, Info info)
{
    Node *newNode = new Node;
    newNode->key = key;
    newNode->info = info;
    newNode->next = this->head;
    this->head = newNode;
    this->size++;
}

template <typename Key, typename Info>
void Sequence<Key, Info>::remove(Key key, int occurrence)
{
    if (occurrence < 0)
    {
        cout << "Occurrence cannot be negative." << endl;
        return;
    }
    if (this->head == nullptr)
    {
        return;
    }
    Node *current = this->head;
    Node *prev = nullptr;
    while (current != nullptr)
    {
        if (current->key == key)
        {
            if (occurrence == 0)
            {
                if (prev == nullptr)
                {
                    this->head = current->next;
                    delete current;
                    this->size--;
                    return;
                }
                prev->next = current->next;
                delete current;
                this->size--;
                return;
            }
            occurrence--;
        }
        prev = current;
        current = current->next;
    }
}
template <typename Key, typename Info>
void Sequence<Key, Info>::removeByPos(int position)
{
    if (position < 0)
    {
        cout << "Position cannot be negative." << endl;
        return;
    }
    if (this->head == nullptr)
    {
        return;
    }
    Node *current = this->head;
    Node *prev = nullptr;
    while (current != nullptr)
    {
        if (position == 0)
        {
            if (prev == nullptr)
            {
                this->head = current->next;
                delete current;
                this->size--;
                return;
            }
            prev->next = current->next;
            delete current;
            this->size--;
            return;
        }
        position--;
        prev = current;
        current = current->next;
    }
}
template <typename Key, typename Info>
void Sequence<Key, Info>::add(Key key, Info info, Key prevKey, int prevOccurrence)
{
    if (prevOccurrence < 0)
    {
        cout << "Previous occurrence cannot be negative." << endl;
        return;
    }
    Node *newNode = new Node;
    newNode->key = key;
    newNode->info = info;
    newNode->next = nullptr;
    if (this->head == nullptr)
    {
        this->head = newNode;
        this->size++;
        return;
    }
    Node *current = this->head;
    while (current != nullptr)
    {
        if (current->key == prevKey)
        {
            if (prevOccurrence == 0)
            {
                newNode->next = current->next;
                current->next = newNode;
                this->size++;
                return;
            }
            prevOccurrence--;
        }
        current = current->next;
    }
}
template <typename Key, typename Info>
Info Sequence<Key, Info>::get(Key key, int occurrence) const
{
    if (occurrence < 0)
    {
        throw "Occurrence cannot be negative.";
    }
    if (this->head == nullptr)
    {
        throw "Sequence is empty";
    }
    Node *current = this->head;
    while (current != nullptr)
    {
        if (current->key == key)
        {
            if (occurrence == 0)
            {
                return current->info;
            }
            occurrence--;
        }
        current = current->next;
    }
    throw "No such key";
}

template <typename Key, typename Info>
int Sequence<Key, Info>::getPosition(Key key, int occurrence) const
{
    if (occurrence < 0)
    {
        throw "Occurrence cannot be negative.";
    }
    if (this->head == nullptr)
    {
        throw "Sequence is empty";
    }
    Node *current = this->head;
    int position = 0;
    while (current != nullptr)
    {
        if (current->key == key)
        {
            if (occurrence == 0)
            {
                return position;
            }
            occurrence--;
        }
        position++;
        current = current->next;
    }
    throw "No such key";
}

template <typename Key, typename Info>
bool Sequence<Key, Info>::contains(Key key, int occurrence) const
{
    if (this->head == nullptr)
    {
        return false;
    }
    Node *current = this->head;
    while (current != nullptr)
    {
        if (current->key == key)
        {
            if (occurrence == 0)
            {
                return true;
            }
            occurrence--;
        }
        current = current->next;
    }
    return false;
}

template <typename Key, typename Info>
int Sequence<Key, Info>::numOfOccurrences(Key key) const
{
    if (this->head == nullptr)
    {
        return 0;
    }
    int counter = 0;
    Node *current = this->head;
    while (current != nullptr)
    {
        if (current->key == key)
        {
            counter++;
        }
        current = current->next;
    }
    return counter;
}

template <typename Key, typename Info>
bool Sequence<Key, Info>::isEmpty() const
{
    return this->head == nullptr;
}

template <typename Key, typename Info>
void Sequence<Key, Info>::clear()
{
    if (this->head == nullptr)
    {
        return;
    }
    Node *current = this->head;
    Node *next;
    while (current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
    }
    this->head = nullptr;
    this->size = 0;
}

template <typename Key, typename Info>
int Sequence<Key, Info>::getSize() const
{
    return this->size;
}

template <typename Key, typename Info>
void Sequence<Key, Info>::displayAll() const
{
    cout << "Sequence: " << endl;
    if (this->head == nullptr)
    {
        cout << "end" << endl;
        return;
    }
    Node *current = this->head;
    while (current != nullptr)
    {
        cout << current->key << " " << current->info << endl;
        current = current->next;
    }
    cout << "end" << endl;
}

template <typename Key, typename Info>
void Sequence<Key, Info>::showNode(Key key, int occurrence) const
{
    if (occurrence < 0)
    {
        cout << "Occurrence cannot be negative." << endl;
        return;
    }
    if (this->head == nullptr)
    {
        return;
    }
    Node *current = this->head;
    while (current != nullptr)
    {
        if (current->key == key)
        {
            if (occurrence == 0)
            {
                cout << current->key << " " << current->info << endl;
                return;
            }
            occurrence--;
        }
        current = current->next;
    }
}

template <typename Key, typename Info>
Sequence<Key, Info>::Sequence(const Sequence<Key, Info> &other)
{
    this->head = nullptr;
    this->size = 0;
    Node *current = other.head;
    while (current != nullptr)
    {
        this->pushBack(current->key, current->info);
        current = current->next;
    }
}

template <typename Key, typename Info>
Sequence<Key, Info> &Sequence<Key, Info>::operator=(const Sequence<Key, Info> &other)
{
    if (this == &other)
    {
        return *this;
    }
    this->clear();
    Node *current = other.head;
    while (current != nullptr)
    {
        this->pushBack(current->key, current->info);
        current = current->next;
    }
    return *this;
}

template <typename Key, typename Info>
Sequence<Key, Info> Sequence<Key, Info>::operator+(const Sequence<Key, Info> &other)
{
    Sequence<Key, Info> result(*this);
    Node *current = other.head;
    while (current != nullptr)
    {
        result.pushBack(current->key, current->info);
        current = current->next;
    }
    return result;
}

template <typename Key, typename Info>
Sequence<Key, Info> Sequence<Key, Info>::operator-(const Sequence<Key, Info> &other)
{
    Sequence<Key, Info> result(*this);
    Node *current = other.head;
    while (current != nullptr)
    {
        result.remove(current->key, 0);
        current = current->next;
    }
    return result;
}

template <typename Key, typename Info>
typename Sequence<Key, Info>::Iterator Sequence<Key, Info>::begin() const
{
    return Iterator(head);
}

template <typename Key, typename Info>
Sequence<Key, Info>::Iterator::Iterator(Node *node)
{
    this->current = node;
}

template <typename Key, typename Info>
Sequence<Key, Info>::Iterator::Iterator(Iterator &other)
{
    this->current = other.current;
}

template <typename Key, typename Info>
typename Sequence<Key, Info>::Iterator &Sequence<Key, Info>::Iterator::operator++()
{
    if (this->current->next == nullptr)
    {
        throw "End of sequence";
    }
    else
    {
        this->current = this->current->next;
        return *this;
    }
}

template <typename Key, typename Info>
typename Sequence<Key, Info>::Iterator &Sequence<Key, Info>::Iterator::operator++(int)
{
    if (this->current->next == nullptr)
    {
        throw "End of sequence";
    }
    else
    {
        auto *temp = new Iterator(*this);
        this->current = this->current->next;
        return *temp;
    }
}

template <typename Key, typename Info>
bool Sequence<Key, Info>::Iterator::operator==(const Iterator &other) const
{
    return this->current == other.current;
}

template <typename Key, typename Info>
bool Sequence<Key, Info>::Iterator::operator!=(const Iterator &other) const
{
    return this->current != other.current;
}

template <typename Key, typename Info>
bool Sequence<Key, Info>::Iterator::isLast() const
{
    return this->current->next == nullptr;
}

template <typename Key, typename Info>
typename Sequence<Key, Info>::Iterator &Sequence<Key, Info>::Iterator::operator=(const Iterator &other)
{
    this->current = other.current;
    return *this;
}

template <typename Key, typename Info>
std::pair<Key, Info> Sequence<Key, Info>::Iterator::operator*() const
{
    return make_pair(this->current->key, this->current->info);
}

template <typename Key, typename Info>
void split_by_pos(const Sequence<Key, Info> &seq, int start_pos, int len1, int len2, int count, Sequence<Key, Info> &seq1, Sequence<Key, Info> &seq2)
{
    if (start_pos < 0 || start_pos > seq.getSize() - 1 || len1 < 0 || len2 < 0 || count < 0)
    {
        return;
    }
    int i = 1;
    typename Sequence<Key, Info>::Iterator it = seq.begin();
    while (i < start_pos)
    {
        i++;
        it++;
    }
    while (count > 0)
    {
        for (int j = 0; j < len1; j++)
        {
            seq1.pushBack((*it).first, (*it).second);
            if (it.isLast())
            {
                return;
            }
            it++;
        }
        for (int j = 0; j < len2; j++)
        {
            seq2.pushBack((*it).first, (*it).second);
            if (it.isLast())
            {
                return;
            }
            it++;
        }
        count--;
    }
}

template <typename Key, typename Info>
void split_by_key(const Sequence<Key, Info> &seq, const Key &start_key, int start_occ, int len1, int len2, int count, Sequence<Key, Info> &seq1, Sequence<Key, Info> &seq2)
{
    if (len1 < 0 || len2 < 0 || count < 0)
    {
        return;
    }
    int i = 0;
    typename Sequence<Key, Info>::Iterator it = seq.begin();
    while (i < start_occ)
    {
        if ((*it).first == start_key)
        {
            i++;
        }
        if (it.isLast())
        {
            return;
        }
        it++;
    }
    while (count > 0)
    {
        for (int j = 0; j < len1; j++)
        {
            seq1.pushBack((*it).first, (*it).second);
            if (it.isLast())
            {
                return;
            }
            it++;
        }
        for (int j = 0; j < len2; j++)
        {
            seq2.pushBack((*it).first, (*it).second);
            if (it.isLast())
            {
                return;
            }
            it++;
        }
        count--;
    }
}
