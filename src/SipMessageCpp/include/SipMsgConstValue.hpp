#ifndef _SIP_MSG_CONST_VALUE_H_
#define _SIP_MSG_CONST_VALUE_H_
#include <string>
namespace DtSipMessageCpp
{
	/*
	*   std::string m_strMsgType;
        std::string m_strVia;
        std::string m_strMaxForwards;
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
	*/
    const std::string REGISTER_TYPE_HEADER = "REGISTER";
    const std::string VIA_HEADER = "Via:";
    const std::string MAX_FORWARDS_HEADER = "Max-Forwards:";
    const std::string FROM_HEADER = "From:";
    const std::string TO_HEADER = "To:";
    const std::string CALL_ID_HEADER = "Call-ID:";
    const std::string CSEQ_HEADER = "CSeq:";
    const std::string EXPIRES_HEADER = "Expires:";
    const std::string ALLOW_HEADER = "Allow:";
    const std::string SUPPORTED_HEADER = "Supported:";
    const std::string USER_AGENT_HEADER = "User-Agent:";
    const std::string AUTHORIZATION_HEADER = "Authorization:";
    const std::string ALLOW_EVENTS_HEADER = "Allow-Events:";
    const std::string CONTENT_LENGTH_HEADER = "Content-Length:";
}
#endif