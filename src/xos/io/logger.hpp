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
///   File: logger.hpp
///
/// Author: $author$
///   Date: 4/9/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_IO_LOGGER_HPP
#define _XOS_IO_LOGGER_HPP

#include "xos/logger/interface.hpp"

namespace xos {
namespace io {

typedef xos::logger::interface loggert_implements;
///////////////////////////////////////////////////////////////////////
///  Class: loggert
///////////////////////////////////////////////////////////////////////
template <class TImplements = loggert_implements>
class _EXPORT_CLASS loggert: virtual public TImplements {
public:
    typedef TImplements implements;
};
typedef loggert<> logger;

typedef logger logger_extendt_implements;
typedef base logger_extendt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: logger_extendt
///////////////////////////////////////////////////////////////////////
template <class TImplements = logger_extendt_implements, class TExtends = logger_extendt_extends>
class _EXPORT_CLASS logger_extendt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    logger_extendt() {
    }
    virtual ~logger_extendt() {
    }
private:
    logger_extendt(const logger_extendt &copy) {
    }
};
typedef logger_extendt<> logger_extend;

} /// namespace io
} /// namespace xos

#endif /// _XOS_IO_LOGGER_HPP 
        

