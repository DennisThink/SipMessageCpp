#ifndef _DT_SIP_BYE_MSG_H_
#define _DT_SIP_BYE_MSG_H_
#include <string>
#include "SipMessageBase.hpp"
namespace DtSipMessageCpp
{
    class CSipByeMsg :public CSipMessageBase
    {
    public:
        CSipByeMsg();
        virtual ~CSipByeMsg();

        virtual bool parse(const std::string& strMsg);
        virtual std::string dump() const;
    public:
        std::string m_strMsgType;
        std::string m_strVia;
        std::string m_strMaxForwards;
        std::string m_strContact;
        std::string m_strFrom;
        std::string m_strTo;
        std::string m_strCallId;
        std::string m_strCSeq;
        std::string m_strExpires;
        std::string m_strAllow;
        std::string m_strSupported;
        std::string m_strUserAgent;
        std::string m_strAuthorization;
        std::string m_strAllowEvents;
        std::string m_strContentLength;

    };
}
#endif