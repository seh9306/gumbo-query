#include "stdafx.h"
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

#include "Document.h"

Document::Document()
{
	mpOutput = NULL;
}

void Document::parse(const std::string& aInput)
{
	reset();
	mpOutput = gumbo_parse(aInput.c_str());
}

Document::~Document()
{
	reset();
}

CSelection Document::find(std::string aSelector)
{
	if (mpOutput == NULL)
	{
		throw "document not initialized";
	}

	CSelection sel(mpOutput->root);
	return sel.find(aSelector);
}

void Document::reset()
{
	if (mpOutput != NULL)
	{
		gumbo_destroy_output(&kGumboDefaultOptions, mpOutput);
		mpOutput = NULL;
	}
}

/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */

