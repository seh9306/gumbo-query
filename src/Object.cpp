/***************************************************************************
 * 
 * $Id$
 * 
 **************************************************************************/

/**
 * @file $HeadURL$
 * @author $Author$(hoping@baimashi.com)
 * @date $Date$
 * @version $Revision$
 * @brief 
 *  
 **/

#include "Object.h"

Object::Object()
{
	mReferences = 1;
}

Object::~Object()
{
	if (mReferences != 1)
	{
		throw "something wrong, reference count not zero";
	}
}

void Object::retain()
{
	mReferences++;
}

void Object::release()
{
	if (mReferences < 0)
	{
		throw "something wrong, reference count is negative";
	}

	if (mReferences == 1)
	{
		delete this;
	}
	else
	{
		mReferences--;
	}
}

unsigned int Object::references()
{
	return mReferences;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */

