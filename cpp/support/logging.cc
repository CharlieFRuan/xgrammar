/*!
 *  Copyright (c) 2023 by Contributors
 * \file support/encoding.cc
 */
#include <xgrammar/support/logging.h>

namespace xgrammar {

LogFatal::Entry& LogFatal::GetEntry() {
  static thread_local LogFatal::Entry result;
  return result;
}

const char* LogMessage::level_strings_[] = {
    ": Debug: ",    // XGRAMMAR_LOG_LEVEL_DEBUG
    ": ",           // XGRAMMAR_LOG_LEVEL_INFO
    ": Warning: ",  // XGRAMMAR_LOG_LEVEL_WARNING
    ": Error: ",    // XGRAMMAR_LOG_LEVEL_ERROR
};

}  // namespace xgrammar