#include <iostream>
#include "cassert"
#include "HashTable.h"
#include "Repetitions.h"
int main() {
    HashTable<int, int> table1;

    assert(table1.size_() == 0);
    table1.insert(1, 11);
    assert(table1.size_() == 1);
    table1.insert(1, 4);
    assert(table1.size_() == 1);
    table1.remove(1);
    assert(table1.size_() == 0);
    table1.insert(1, 1);
    table1.removeAll();
    HashTable<int, int> table2;
    assert(table1 == table2);
    table1.insert(5, 3);
    table2.insert(5,3);
    assert(table1 == table2);
    table2.removeAll();
    table1.removeAll();

    table1.insert(1, 1);
    table1.insert(2, 2);
    table1.insert(3, 3);

    table2 = HashTable<int, int>(table1);
    assert(table2.size_() == 3);
    assert(table1 == table2);
    table2.insert(4,1);
    assert((table1 == table2) == false);
    table1.removeAll();
    table2.removeAll();

    table1.insert(1, 1);
    table1.insert(2, 2);
    table1.insert(3, 3);

    table2.insert(1, 2);
    table2.insert(2, 2);
    table2.insert(3, 1);

    table1.saveToFile("output.txt");
    HashTable<int, int> table3;
    table3.loadFromFile("output.txt");
    assert(table3.size_() == 3);
    assert(table1==table3);

    table1.removeAll();
    assert((table1&&table3) == table1);
    assert((table3&&table3) == table3);
    Repetitions repetition = Repetitions();

    repetition.add("Баныны", 3);
    repetition.add("Яблоко", 1);
    repetition.add("Слово", 5);
    repetition.add("Крыша", 2);
    repetition.add("Слон", 2);

    assert(repetition.numberofrepetitions(4) == 1);
    assert(repetition.numberofrepetitions(2) == 4);

    assert(repetition.get("Слово") == 5);



    std::cout << "All tests are passed" << std::endl;
}
