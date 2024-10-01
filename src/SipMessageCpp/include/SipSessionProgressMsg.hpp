#ifndef _DT_SIP_SESSION_PROGRESS_MSG_H_
#define _DT_SIP_SESSION_PROGRESS_MSG_H_
#include <string>
#include <vector>
namespace DtSipMessageCpp
{
    class CSipSessionProgressMsg
    {
    public:
        CSipSessionProgressMsg();
        virtual ~CSipSessionProgressMsg();

        virtual bool parse(const std::string& strMsg);
        virtual std::string dump() const;
    protected:
        std::string m_strMsgType;
        std::string m_strVia;
        std::string m_strMaxForwards;
        std::string m_strContact;
        std::string m_strFrom;
        std::string m_strTo;
        std::string m_strCallId;
        std::string m_strCSeq;
        
        std::string m_strContentType;
        std::string m_strContentDisposition;
        std::string m_strRemotePartyId;
        std::string m_strContentLength;

        std::string m_strProxyAuthorization;
        std::string m_strExpires;
        std::string m_strAllow;
        std::string m_strAccept;
        std::string m_strSupported;
        std::string m_strUserAgent;
        std::string m_strProxyAuthenticate;
        std::string m_strAuthorization;
        std::string m_strAllowEvents;

        //std::string AppendNotEmptyString(const std::string& strOrg, const std::string& item);

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

        std::string m_strsdpTimeTheSessionIsActive;
        //std::vector<std::string> 
        std::string m_strsdpMediaAndTransport;
        std::string m_strsdpTimeZoneAdjustments;
        std::string m_strsdpEncryptionKey;
        std::vector<std::string> m_strsdpZeroOrMoreSessionAttributeLines;
    };
}
#endif