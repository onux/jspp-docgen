//
// Copyright (C) 2017 Onux Corporation. All rights reserved.
//

#ifndef JSPP_DOCGEN_TEST_H
#define JSPP_DOCGEN_TEST_H

#include <catch.hpp>
#include <pugixml.hpp>
#include "CommentParser/CommentParser.h"
#include "DocCommentData/DocCommentTags.h"
#include "Output/DocVisitor.h"
#include "Output/OutputBuilder.h"
#include "ParsedData/includes.h"
#include "Utils/Utils.h"

std::unique_ptr<pugi::xml_document> generate(const std::string& code);

#endif