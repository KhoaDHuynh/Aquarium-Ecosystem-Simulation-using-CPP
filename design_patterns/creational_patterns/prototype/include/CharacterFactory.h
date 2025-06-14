#ifndef _CHARACTERFACTORY_H_
#define _CHARACTERFACTORY_H_

#include <unordered_map>
#include <string>
#include "Character.h"

class CharacterFactory 
{
private:
    /* Like a dictionnary ["tên của mẫu"] -> [con trỏ tới mẫu]
        - Từ điển này lưu tên của các mẫu và các mẫu (nguyên bản muốn sao chép) 
        tương ứng.
        - Store the prototypes of different character types, allowing the factory 
        to create new instances by cloning these prototypes. 
    */
    std::unordered_map<std::string, Character*> prototypes;
    
public:
    void registerPrototype(const std::string& type, Character* prototype) 
    {
        // Lưu mẫu mới vào từ điển
        prototypes[type] = prototype;
    }

    Character* createCharacter(const std::string& type) const 
    {
        // Tìm mãu type trong từ điển, trả về con trỏ chứa mẫu đó
        auto it = prototypes.find(type);

        // Nếu con trỏ đó có tồn tại
        if (it != prototypes.end()) 
        {
            // thì nhân bản Character
            return it->second->clone();
        }
        // Còn không thì trả về  nullptr
        return nullptr;
    }

    /*
        - The purpose of the destructor is to ensure that all dynamically 
        allocated prototypes are properly deleted when the CharacterFactory 
        object is destroyed. 
        - This prevents memory leaks by releasing the 
        memory that was allocated for the prototypes.
    */
    ~CharacterFactory() 
    {
        for (auto& pair : prototypes) 
        {
            delete pair.second;
        }
    }
};

#endif