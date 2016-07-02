/*****************************************************************************/
/*!
@file   MemoryUtils.h
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   6/19/2016
@brief  contains utility functions for managing memory
*/
/*****************************************************************************/
#ifndef MEMORY_UTILS
#define MEMORY_UTILS

namespace Memory
{
    /******************************************************************************
    \fn FreeMapMemory(Map & map)
    @author Razmig Mardirossian
    @brief clears memory allocated in a map where the value is the allocated object
    @param map the target map that is being cleared
    *******************************************************************************/
    template <typename Map>
    void FreeMapMemory(Map & map) {
        for (typename Map::iterator it = map.begin(); it != map.end(); ++it)
            delete it->second;
        map.clear();
    }
}
#endif
