#ifndef _DT_SIP_INVITE_MSG_H_
#define _DT_SIP_INVITE_MSG_H_
#include "SipMessageBase.hpp"
#include <vector>
namespace DtSipMessageCpp
{
    class CSipInviteMsg:public CSipMessageBase
    {
    public:
        CSipInviteMsg();
        virtual ~CSipInviteMsg();

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
        std::string m_strContentType;
        std::string m_strProxyAuthorization;
        std::string m_strExpires;
        std::string m_strAllow;
        std::string m_strSupported;
        std::string m_strUserAgent;
        std::string m_strAuthorization;
        std::string m_strAllowEvents;
        std::string m_strContentLength;


        //const std::string SDP_PROTOCAL_VERSION_HEADER = "v=";
        std::string m_strsdpProtocalVersion;
        std::string m_strsdpOwnerSessionIndentifier;
        std::string m_strsdpSessionName;
        std::string m_strsdpSessionInformation;
        std::string m_strsdpUriOfDescription;
        std::string m_strsdpEmailAddress;
        std::string m_strsdpPhoneNumber;
        std::string m_strsdpConnectionInformation;
        std::string m_strsdpBandwidthInformation;

        //std::vector<std::string> 
        std::string m_strsdpTimeZoneAdjustments;
        std::string m_strsdpEncryptionKey;
        std::vector<std::string> m_strsdpZeroOrMoreSessionAttributeLines;
    };
}
#endif