#ifndef _DT_SIP_REGISTER_MSG_H_
#define _DT_SIP_REGISTER_MSG_H_
#include "SipMessageBase.hpp"
namespace DtSipMessageCpp
{
    class CSipRegisterMsg:public CSipMessageBase
    {
    public:
        CSipRegisterMsg();
        virtual ~CSipRegisterMsg();

        virtual bool parse(const std::string& strMsg) override;
        virtual std::string dump() const override; 
    };
}
#endif