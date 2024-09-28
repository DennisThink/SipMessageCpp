#ifndef _DT_SIP_ACK_MSG_H_
#define _DT_SIP_ACK_MSG_H_
#include "SipMessageBase.hpp"
#include <string>
namespace DtSipMessageCpp
{
    class CSipAckMsg:public CSipMessageBase
    {
    public:
        CSipAckMsg();
        virtual ~CSipAckMsg();

        virtual bool parse(const std::string& strMsg);
        virtual std::string dump() const;

    };
}
#endif