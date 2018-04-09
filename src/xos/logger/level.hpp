///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2018 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: level.hpp
///
/// Author: $author$
///   Date: 4/9/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_LOGGER_LEVEL_HPP
#define _XOS_LOGGER_LEVEL_HPP

#include "xos/base/base.hpp"

namespace xos {
namespace logger {

class _EXPORT_CLASS level: virtual public implement_base, public base {
public:
    typedef implement_base implements;
    typedef base extends;

    typedef unsigned enable;
    enum {
        none  = 0,

        fatal = 1,
        error = (fatal << 1),
        warn  = (error << 1),
        info  = (warn << 1),
        debug = (info << 1),
        trace = (debug << 1),

        next  = (trace << 1),
        all   = (next - 1),
        last  = (next >> 1),
        first = (fatal),
        
        message_fatal = (last << 1),
        message_error = (message_fatal << 1),
        message_warn  = (message_error << 1),
        message_info  = (message_warn << 1),
        message_debug = (message_info << 1),
        message_trace = (message_debug << 1),

        message_next  = (message_trace << 1),
        message_all   = (all << next),
        message_last  = (message_next >> 1),
        message_first = (message_fatal),
   
        fatal_message = message_fatal,
        error_message = message_error,
        warn_message = message_warn,
        info_message = message_info,
        debug_message = message_debug,
        trace_message = message_trace
    };

    level(const level& copy): enable_(copy.enable_) {        
    }
    level(enable _enable): enable_(_enable) {
    }
    level(): enable_(none) {
    }

    virtual level& operator = (enable _enable) {
        enable_ = _enable;
        return *this;
    }
    virtual operator enable() const {
        return enable_;
    }

protected:
    enable enable_;
};

class _EXPORT_CLASS levels: virtual public implement_base, public base {
public:
    typedef implement_base implements;
    typedef base extends;

    typedef unsigned enable;
    enum {
        none  = 0,

        fatal = 1,
        error = (((fatal + 1) << 1) - 1),
        warn  = (((error + 1) << 1) - 1),
        info  = (((warn + 1) << 1) - 1),
        debug = (((info + 1) << 1) - 1),
        trace = (((debug + 1) << 1) - 1),

        all = trace,

        message_none  = 0,

        message_fatal = (fatal << trace),
        message_error = (error << trace),
        message_warn  = (warn << trace),
        message_info  = (info << trace),
        message_debug = (debug << trace),
        message_trace = (trace << trace),

        message_all = message_trace
    };

    levels(const levels& copy): enable_(copy.enable_) {        
    }
    levels(enable _enable): enable_(_enable) {
    }
    levels(): enable_(none) {
    }

    virtual levels& operator = (enable _enable) {
        enable_ = _enable;
        return *this;
    }
    virtual operator enable() const {
        return enable_;
    }

protected:
    enable enable_;
};

} /// namespace logger
} /// namespace xos

#endif /// _XOS_LOGGER_LEVEL_HPP 
        

