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
///   File: interface.hpp
///
/// Author: $author$
///   Date: 4/9/2018
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_LOGGER_INTERFACE_HPP
#define _XOS_LOGGER_INTERFACE_HPP

#include "xos/logger/output.hpp"

namespace xos {
namespace logger {

typedef implement_base interfacet_implements;
///////////////////////////////////////////////////////////////////////
///  Class: interfacet
///////////////////////////////////////////////////////////////////////
template <class TImplements = interfacet_implements>
class _EXPORT_CLASS interfacet: virtual public TImplements {
public:
    typedef TImplements implements;
};
typedef interfacet<> interface;

} /// namespace logger
} /// namespace xos

///
/// LOG_ TRACE / DEBUG / ERROR
/// 
#if !defined(LOG_TRACE)
#define LOG_TRACE(__message__) ERR_LOG_TRACE(__message__)
#endif /// !defined(LOG_TRACE)

#if !defined(LOG_DEBUG)
#define LOG_DEBUG(__message__) ERR_LOG_DEBUG(__message__)
#endif /// !defined(LOG_DEBUG)

#if !defined(LOG_ERROR)
#define LOG_ERROR(__message__) ERR_LOG_ERROR(__message__)
#endif /// !defined(LOG_ERROR)

#endif /// _XOS_LOGGER_INTERFACE_HPP 
        

