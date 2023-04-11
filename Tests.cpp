#include "Sequence.h"
#include "Sequence.cpp"
#include <iostream>

using namespace std;

int main()
{
    cout << endl
         << endl
         << "GENERAL TESTS ONE SEQUENCE##################################################################" << endl
         << endl; 
    cout << "######################TEST 1######################" << endl;
    Sequence <int, int> seq1;
    cout << "sequence is empty: " << seq1.isEmpty() << endl;
    seq1.displayAll();
    cout << endl << endl << endl << endl;

    cout << "######################TEST 2######################" << endl;
    cout << "add key 1, info 1" << endl;
    seq1.pushBack(1, 1);
    cout << "add key 2, info 2" << endl;
    seq1.pushBack(2, 2);
    cout << "add key 3, info 3, after key 1, occurrence 0" << endl;
    seq1.add(3, 3, 1, 0);
    cout << "add key 3, info 3, after key 1, occurrence -1" << endl;
    seq1.add(3, 3, 1, -1);
    cout << "add key 2, info 10" << endl;
    seq1.pushBack(2, 10);
    seq1.displayAll();
    cout << endl << endl << endl << endl;

    cout << "######################TEST 3######################" << endl;
    seq1.displayAll();
    cout << "print node key 2 occurrence 0: " << endl;
    seq1.showNode(2, 0);
    cout << "print node key 2 occurrence 1: " << endl;
    seq1.showNode(2, 1);
    cout << "print node key 44 occurrence 0: " << endl;
    seq1.showNode(44, 0);
    cout << "print node key 1 occurrence 44: " << endl;
    seq1.showNode(1, 44);
    cout << endl << endl << endl << endl;

    cout << "######################TEST 4######################" << endl;
    cout << "seq1 remove key 1, occurrence 0" << endl;
    seq1.remove(1, 0);
    cout << "seq1 remove key 44, occurrence 0" << endl;
    seq1.remove(44, 0);
    seq1.displayAll();
    cout << endl << endl << endl << endl;

    cout << "#######################TEST 5######################" << endl;
    seq1.displayAll();
    cout << "seq` get key 2, occurrence 0: " << seq1.get(2, 0) << endl;
    cout << "seq` get key 2, occurrence 1: " << seq1.get(2, 1) << endl;
    try {
        cout << "seq` get key 44, occurrence 0: " << seq1.get(44, 0) << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    }
    cout << endl << endl << endl << endl;

    cout << "######################TEST 6######################" << endl;
    seq1.displayAll();
    cout << "sequence contains key 2, occurrence 3: " << seq1.contains(2, 3) << endl;
    cout << "sequence contains key 2, occurrence 0: " << seq1.contains(2, 0) << endl;
    cout << endl << endl << endl << endl;

    cout << "######################TEST 7######################" << endl;
    seq1.displayAll();
    cout << "number of occurrences of key 43: " << seq1.numOfOccurrences(43) << endl;
    cout << "number of occurrences of key 2: " << seq1.numOfOccurrences(2) << endl;
    cout << endl << endl << endl << endl;

    cout << "######################TEST 8######################" << endl;
    seq1.displayAll();
    cout << "sequence is empty: " << seq1.isEmpty() << endl;
    cout << endl << endl << endl << endl;

    cout << "######################TEST 9######################" << endl;
    seq1.displayAll();
    cout << "length of sequence: " << seq1.getSize() << endl;
    cout << endl << endl << endl << endl;

    cout << "######################TEST 10######################" << endl;
    seq1.displayAll();
    seq1.clear();
    cout << "clear sequence:" << endl;
    seq1.displayAll();



    cout << endl
         << endl
         << "GENERAL TESTS SEVERAL SEQUENCES#########################################################" << endl
         << endl;

    Sequence<int, string> seq2;
    seq2.pushBack(1, "a");
    seq2.pushBack(2, "b");
    seq2.pushBack(3, "c");
    seq2.pushBack(4, "d");
    cout << "seq2: " << endl;
    seq2.displayAll();
    cout << endl
         << endl
         << endl
         << endl;

    cout << "#####################TEST 1######################" << endl;
    Sequence<int, string> seq3 = Sequence(seq2);
    cout << "copy constructor seq3 from seq2:" << endl;
    cout << "seq3: " << endl;
    seq3.displayAll();
    cout << endl
         << endl
         << endl
         << endl;

    cout << "######################TEST 2######################" << endl;
    cout << "seq3 remove key 1, occurrence 0" << endl;
    seq3.remove(1, 0);
    cout << "seq3: " << endl;
    seq3.displayAll();
    cout << "assignment operator seq3 from seq2:" << endl;
    seq2 = seq3;
    cout << "seq2: " << endl;
    seq2.displayAll();
    cout << endl
         << endl
         << endl
         << endl;

    cout << "######################TEST 3######################" << endl;
    cout << "seq3 remove key 2, occurrence 0" << endl;
    seq3.remove(2, 0);
    cout << "seq3 remove key 2, occurrence 1" << endl;
    seq3.remove(2, 0);
    cout << "seq3 remove key 3, occurrence 0" << endl;
    seq3.remove(3, 0);
    cout << "seq3: " << endl;
    seq3.displayAll();
    Sequence<int, string> seq4 = seq2 + seq3;
    cout << "plus operator seq4 = seq2 + seq3" << endl;
    cout << "seq4: " << endl;
    seq4.displayAll();
    cout << endl
         << endl
         << endl
         << endl;

    cout << "######################TEST 4######################" << endl;
    Sequence<int, string> seq5 = seq2 - seq3;
    cout << "minus operator seq5 = seq2 - seq3" << endl;
    cout << "seq5: " << endl;
    seq5.displayAll();
    cout << endl
         << endl
         << endl;

    Sequence<int, int> seq6;
    seq6.pushBack(1, 1);
    seq6.pushBack(2, 2);
    seq6.pushBack(3, 3);
    seq6.pushBack(4, 4);
    seq6.pushBack(5, 5);
    seq6.pushBack(6, 6);
    seq6.pushBack(7, 7);
    seq6.pushBack(8, 8);
    seq6.pushBack(9, 9);
    seq6.pushBack(10, 10);
    seq6.pushBack(11, 11);
    seq6.pushBack(12, 12);
    seq6.pushBack(13, 13);
    seq6.pushBack(14, 14);
    seq6.pushBack(15, 15);
    cout << "seq6:" << endl;
    seq6.displayAll();
    cout << endl
         << endl
         << endl
         << endl;

     cout << "######################TEST 5######################" << endl;
     Sequence<double, string> dSeq;
     dSeq.pushBack(1.1, "something");
     dSeq.pushBack(2.2, "something else");
     dSeq.pushBack(3.3, "something else again");
     dSeq.displayAll();


    cout << endl
         << endl
         << "EXTERNAL FUNCTIONS TESTS############################################" << endl
         << endl;

    cout << "######################TEST 1######################" << endl;
    Sequence<int, int> seq7;
    Sequence<int, int> seq8;
    split_by_pos(seq6, 5, 2, 3, 2, seq7, seq8);
    cout << endl
         << "split_by_pos seq6, start position 5, len1 2, len2 3, count 2, seq 7, seq 8" << endl;
    cout << "seq7:" << endl;
    seq7.displayAll();
    cout << "seq8:" << endl;
    seq8.displayAll();
    cout << endl
         << endl
         << endl
         << endl;

    cout << "######################TEST 2######################" << endl;
    Sequence<int, int> seq9;
    Sequence<int, int> seq10;
    seq6.add(4, 23, 4, 0);
    cout << endl
         << "seq6 add key 4, info 23, after key 4, occurrence 0" << endl;
    cout << "seq6:" << endl;
    seq6.displayAll();
    split_by_key(seq6, 4, 1, 1, 3, 5, seq9, seq10);
    cout << endl
         << "split_by_key seq6, start key 4, start occurrence 1, len1 1, len2 3, count 5, seq9, seq10" << endl;
    cout << "seq9:" << endl;
    seq9.displayAll();
    cout << "seq10:" << endl;
    seq10.displayAll();

    cout << endl
         << "ITERATOR TEST#################################################################################" << endl
         << endl;
    Sequence<int, int> seq11;
    seq11.pushBack(1, 1);
    seq11.pushBack(2, 2);
    seq11.pushBack(3, 3);
    cout << "seq11:" << endl;
    seq11.displayAll();
    cout << endl
         << endl
         << endl
         << endl;

    cout << "######################TEST 1######################" << endl;
    auto it = seq11.begin();
    cout << "it = seq11.begin(): " << (*it).first << " " << (*it).second << endl;
    cout << endl
         << endl
         << endl
         << endl;

    cout << "######################TEST 2######################" << endl;
    ++it;
    cout << "++it: " << (*it).first << " " << (*it).second << endl;
    cout << endl
         << endl
         << endl
         << endl;

    cout << "######################TEST 3######################" << endl;
    auto temp = it++;
    cout << "temp = it++: " << (*temp).first << " " << (*temp).second << endl;
    cout << "it: " << (*it).first << " " << (*it).second << endl;
    cout << endl
         << endl
         << endl
         << endl;

    cout << "###########################TEST 4##################################" << endl;
    cout << "it: " << (*it).first << " " << (*it).second << endl;
    auto it1 = seq11.begin();
    cout << "it1 = seq11.begin(): " << (*it1).first << " " << (*it1).second << endl;
    cout << "it1 == it: " << (it1 == it) << endl;
    cout << "it1 != it: " << (it1 != it) << endl;
    cout << endl
         << endl
         << endl
         << endl;

    cout << "#####################TEST 5###########################" << endl;
    cout << "it: " << (*it).first << " " << (*it).second << endl;
    it1 = it;
    cout << "it1 = it: " << (*it1).first << " " << (*it1).second << endl;
    cout << endl
         << endl
         << endl
         << endl;

    cout << "##################TEST 6#############################" << endl;
    cout << "seq11:" << endl;
    seq11.displayAll();
    cout << "it: " << (*it).first << " " << (*it).second << endl;
    cout << "it.isLast: " << it.isLast() << endl;
}
