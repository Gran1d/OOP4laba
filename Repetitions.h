//
// Created by Артём Сиротин on 25.11.2023.
//

#ifndef HASH_TABLE_REPETITIONS_H
#define HASH_TABLE_REPETITIONS_H
#include "HashTable.h"

class Repetitions {
public:
    Repetitions() = default;
    Repetitions(const Repetitions& other) = default;
    //Вставить
    void add(const string& name, size_t count){
        repetitions_.insert(name, count);
    }
    //удалить по ключу
    void remove(const string& name){
        return repetitions_.remove(name);
    }
    //удалить все
    void removeAll(){
        return repetitions_.removeAll();
    }
    //Геттер
    size_t get(string name) const{
        return repetitions_[name];
    }
    //Задаем число и выводим количество повторений
    int numberofrepetitions(int number){
        vector<string> keys = repetitions_.keys();
        int counter = 0;
        for(string& key : keys){
            if (repetitions_[key] >= number){
                counter+=1;
            }
        }
        return counter;
    }

private:
    HashTable<string, size_t> repetitions_;
};




#endif //HASH_TABLE_REPETITIONS_H
