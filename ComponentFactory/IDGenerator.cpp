/*****************************************************************************/
/*!
@file   IDGenerator.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   2/23/2017
*/
/*****************************************************************************/
#include <cstdlib> /* srand */
#include <time.h>  /* time  */
#include "IDGenerator.h"

#define MAX_SIZE 1000000

namespace Utilities
{
    std::set<unsigned> IDGenerator::_idContainer = std::set<unsigned>();

    unsigned IDGenerator::GenerateId()
    {
        return static_cast<unsigned>(rand() % MAX_SIZE + 1);
    }

    void IDGenerator::AddIdToSet(unsigned id)
    {
        _idContainer.insert(id);
    }

    void IDGenerator::AssignIDToEntity(Core::Entity* entity)
    {
        unsigned tempID = 0;
        do
        {
            tempID = GenerateId();
            std::set<unsigned>::const_iterator it = _idContainer.find(tempID);
            if (it == _idContainer.end())
                entity->SetId(tempID);
        } while (!_idContainer.insert(tempID).second);
    }
}
