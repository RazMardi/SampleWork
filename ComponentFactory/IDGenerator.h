/*****************************************************************************/
/*!
@file   IDGenerator.h
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   2/23/2017
@brief  holds the interface for the IDGenerator class. A utility class for 
generation unique ids for all entities.
*/
/*****************************************************************************/
#ifndef ID_GENERATOR_H
#define ID_GENERATOR_H

#include <set>
#include "Entity.h"

namespace Utilities
{
    class IDGenerator
    {
    public:
        static unsigned GenerateId();
        static void     AssignIDToEntity(Core::Entity* entity);
        static void     AddIdToSet(unsigned id);

    private:
        static std::set<unsigned> _idContainer;
    };
}
#endif