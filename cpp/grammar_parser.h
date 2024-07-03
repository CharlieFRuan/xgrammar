/*!
 *  Copyright (c) 2023 by Contributors
 * \file grammar/grammar_parser.h
 * \brief The header for the parser of BNF/EBNF grammar into BNF AST.
 */

#ifndef XGRAMMAR_GRAMMAR_PARSER_H_
#define XGRAMMAR_GRAMMAR_PARSER_H_

#include <xgrammar/grammar.h>
#include <xgrammar/support/logging.h>

namespace xgrammar {

/*!
 * \brief This class parses a BNF/EBNF grammar string into an BNF abstract syntax tree (AST).
 * \details This function accepts the EBNF notation defined in the W3C XML Specification
 * (https://www.w3.org/TR/xml/#sec-notation), which is a popular standard, with the following
 * changes:
 * - Using # as comment mark instead of C-style comments
 * - Accept C-style unicode escape sequence \u01AB, \U000001AB, \xAB instead of #x0123
 * - Rule A-B (match A and not match B) is not supported yet
 *
 * See tests/python/serve/json.ebnf for an example.
 */
class EBNFParser {
 public:
  /*!
   * \brief Parse the grammar string. If fails, throw ParseError with the error message.
   * \param ebnf_string The grammar string.
   * \param main_rule The name of the main rule. Default is "main".
   * \return The parsed grammar.
   */
  static BNFGrammar Parse(std::string ebnf_string, std::string main_rule = "main");

  /*!
   * \brief The exception thrown when parsing fails.
   */
  class ParseError : public Error {
   public:
    ParseError(const std::string& msg) : Error(msg) {}
  };
};

}  // namespace xgrammar

#endif  // XGRAMMAR_GRAMMAR_PARSER_H_