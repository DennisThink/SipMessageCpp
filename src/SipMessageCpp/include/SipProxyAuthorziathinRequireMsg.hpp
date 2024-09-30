#ifndef _DT_SIP_PROXY_AUTHORIZATION_H_
#define _DT_SIP_PROXY_AUTHORIZATION_H_
#include <string>
namespace DtSipMessageCpp
{
    class CSipProxyAuthorizationRequiresMsg
    {
    public:
        CSipProxyAuthorizationRequiresMsg();
        virtual ~CSipProxyAuthorizationRequiresMsg();

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
        std::string m_strProxyAuthorization;
        std::string m_strExpires;
        std::string m_strAllow;
        std::string m_strAccept;
        std::string m_strSupported;
        std::string m_strUserAgent;
        std::string m_strProxyAuthenticate;
        std::string m_strAuthorization;
        std::string m_strAllowEvents;
        std::string m_strContentLength;
        //std::string AppendNotEmptyString(const std::string& strOrg, const std::string& item);
    };
}
#endif