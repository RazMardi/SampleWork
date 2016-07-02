/*****************************************************************************/
/*!
@file   IDGenerator.cpp
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   6/19/2016
@brief  helper class for generating unique id's on components and entities
*/
/*****************************************************************************/
#include "IDGenerator.h"

const unsigned& IDGenerator::operator()(unsigned& id) {
    id++;
    return id;
}
