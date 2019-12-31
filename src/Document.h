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

#ifndef DOCUMENT_H_
#define DOCUMENT_H_

#include <gumbo.h>
#include <string>
#include "Selection.h"

class Document: public Object
{
	public:

		Document();

		void parse(const std::string& aInput);

		virtual ~Document();

		CSelection find(std::string aSelector);

	private:

		void reset();

	private:

		GumboOutput* mpOutput;
};

#endif /* DOCUMENT_H_ */

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
