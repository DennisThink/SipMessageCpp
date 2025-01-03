#ifndef _C_SIP_REGISTER_SERVER_RSP_H_
#define _C_SIP_REGISTER_SERVER_RSP_H_
#include "SipServerRspBase.hpp"
namespace DtSipMessageCpp
{
    class CSipRegisterServerRsp:public CSipServerRspBase
    {
    public:
        CSipRegisterServerRsp();
        virtual ~CSipRegisterServerRsp();

        virtual bool parse(const std::string& strMsg) override;
        virtual std::string dump() const override;

    public:
        std::string get_www_auth() const;
        std::string get_auth_type_header() const;
    protected:
        std::string m_strMsgType;
        std::string m_strSipRspHeader;
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
        std::string m_strWwwAuthentite;
        std::string m_strAuthType;
        //std::string AppendNotEmptyString(const std::string& strOrg, const std::string& item);
    };
}
#endif