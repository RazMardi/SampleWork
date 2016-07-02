/*****************************************************************************/
/*!
@file   IDGenerator.h
@author Razmig Mardirossian
@par    email: r.mardirossian\@digipen.edu
@date   6/19/2016
@brief  contains the interface for the IDGenerator class
*/
/*****************************************************************************/
#ifndef IDGENERATOR_H
#define IDGENERATOR_H

struct IDGenerator {
    const unsigned& operator()(unsigned& id);
};
#endif

