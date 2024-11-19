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

        void set_sip_server_ip_port(const std::string strIp, const int nPort);
        void set_sip_local_ip_port(const std::string strIp, const int nPort);
        void set_username_password(const std::string strUserName, const std::string strPassword);
        void set_net_type(const std::string strType);
        void set_authorization(const std::string strAuthorization);
        //std::string get_sip_server_ip() const;
        //int get_sip_server_port() const;
    protected:
        void parse_register_header();
        void parse_register_header_with_transport();
        void parse_register_header_without_transport();
    public:
        std::string m_strMsgType;
        std::string m_strVia;
        std::string m_strRoute;
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
    private:
        std::string m_strSipServerIp;
        int m_nSipServerPort;
        std::string m_strUserName;
        std::string m_strUserPassword;

        std::string m_strSipLocalIp;
        int m_nSipLocalPort;

        std::string m_strNetType;//TCP/UDP/SSL
    };
}
#endif