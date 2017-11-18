//
// Copyright (C) 2017 Onux Corporation. All rights reserved.
//

#ifndef JSPP_DOCGEN_OUTPUTBUILDER_H
#define JSPP_DOCGEN_OUTPUTBUILDER_H

#include "CommentData/includes.h"
#include "Data/Modifiers.h"
#include "Data/DocCommentTags.h"
#include <sstream>
#include <memory>

namespace jspp
{
namespace docgen
{
    /**
     * The `OutputBuilder` class is responsible for building the XML output.
     */
    class OutputBuilder
    {
    public:
        /**
         * Gets the output XML.
         */
        std::string getOutput() const;

        /**
         * Builds the XML for a JS++ `module`.
         *
         * @param comment The processed comment data. See `ModuleCommentData`.
         */
        void buildModule(const ModuleCommentData& comment);
        /**
         * Builds the XML for a JS++ `class`.
         *
         * @param comment The processed comment data. See `ClassCommentData`.
         */
        void buildClass(const ClassCommentData& comment);
        /**
         * Builds the XML for a JS++ `interface`.
         *
         * @param comment The processed comment data. See `InterfaceCommentData`.
         */
        void buildInterface(const InterfaceCommentData& comment);
        /**
         * Builds the XML for JS++ class/interface methods.
         *
         * @param comment The processed comment data. See `MethodCommentData`.
         */
        void buildFunctions(const MethodCommentData& comment);
        /**
         * Builds the XML for JS++ overloaded class/interface methods.
         *
         * @param comment The processed comment data. See `OverloadedMethodCommentData`.
         */
        void buildFunctions(const OverloadedMethodCommentData& comment);
        /**
         * Builds the XML for JS++ class constructors.
         *
         * @param comment The processed comment data. See `ConstructorCommentData`.
         */
        void buildFunctions(const ConstructorCommentData& comment);
        /**
         * Builds the XML for JS++ overloaded class constructors.
         *
         * @param comment The processed comment data. See `OverloadedConstructorCommentData`.
         */
        void buildFunctions(const OverloadedConstructorCommentData& comment);
        /**
         * Builds the XML for a JS++ class field.
         *
         * @param comment The processed comment data. See `FieldCommentData`.
         */
        void buildField(const FieldCommentData& comment);
        /**
         * Builds the XML for a JS++ enum declaration.
         *
         * @param comment The processed comment data. See `EnumCommentData`.
         */
        void buildEnumeration(const EnumCommentData& comment);

    private:
        std::ostringstream output;

        /**
         * Wraps the string in an XML CDATA section.
         */
        std::string cdata(const std::string& s) const;
        /**
         * Adds a <title> tag to the output XML document.
         *
         * @param title The text for the <title> tag.
         */
        void addTitle(const std::string& title);
        /**
         * Adds a <summary> tag to the output XML document.
         */
        void addSummary(const std::string& text);
        /**
         * Adds a <description> tag to the output XML document.
         */
        void addDescription(const std::string& text);
        /**
         * Adds a <example> tag to the output XML document.
         *
         * @param The title of the example.
         * @param The code for the example.
         */
        void addExample(const std::string& title, const std::string& code);
        /**
         * Adds a <deprecated> tag with the specified reason to the output XML
         * document.
         *
         * @param reason The reason the documented node is deprecated.
         */
        void addDeprecated(const std::string& reason);
        /**
         * Adds a <see> ("See Also") tag with the specified page to the output
         * XML document.
         *
         * @param title The link text for the suggested page.
         * @param page The fully-qualified name (FQN) or URL to suggest.
         */
        void addSeeAlso(const std::string& title, const std::string& page);
        /**
         * Adds the modifiers to the output XML document.
         *
         * @param modifiers The modifiers applied to the documented AST node.
         */
        void addModifiers(const jspp::docgen::Modifiers& modifiers);
        /**
         * Adds <param> tags to the output XML document.
         *
         * @param commentData The data for the associated documentation comment.
         * @param tags The parsed documentation tags and data.
         */
        void addParameters(const jspp::docgen::OverloadableCommentData& commentData,
                           const jspp::docgen::DocCommentTags& tags);
        /**
         * Adds a <class> tag to the output XML document for constructor class
         * names.
         *
         * @param text The text for the <class> tag.
         */
        void addClass(const std::string& text);
        /**
         * Returns the Markdown-formatted text for a given string.
         */
        std::string markdown(const std::string& text) const;
    };
}
}

#endif