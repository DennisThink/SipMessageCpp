#ifndef _DT_SIP_RE_REGISTER_MSG_H_
#define _DT_SIP_RE_REGISTER_MSG_H_
#include "SipMsgClientReqBase.hpp"
namespace DtSipMessageCpp
{
    class CSipReRegisterMsg:public CSipMsgClientReqBase
    {
    public:
        CSipReRegisterMsg();
        virtual ~CSipReRegisterMsg();

        virtual bool parse(const std::string& strMsg) override;
        virtual std::string dump() const override; 
        //set function list
        void set_sip_server_ip_port(const std::string strIp, const int nPort);
        void set_sip_local_ip_port(const std::string strIp, const int nPort);
        void set_username_password(const std::string strUserName, const std::string strPassword);
        void set_net_type(const std::string strType);
        void set_branch(const std::string strBranch);
        void set_authorization(const std::string strAuthorization);
        void set_allow_options(const std::string strAllowOptions);
        void set_allow_events(const std::string strAllowEvents);
        void set_call_id(const std::string strCallId);
        void set_content_length(const std::string strContentLength);
        void set_max_forwards(const std::string strMaxForwards);
        void set_from_tag(const std::string strFromTag);
        //void set_c_seq(const std::string strSeq);
        void set_expires(const std::string strExpires);
        //std::string get_sip_server_ip() const;
        //int get_sip_server_port() const;

        //create function list
        void create_header_line();
        void create_via_line();
        void create_from_line();
        void create_to_line();
        void create_contact_line();
        virtual bool create_c_seq_line() override;
        //get function list
    public:
        std::string get_authorization_line();
        std::string get_allow_events();
    protected:
        void parse_register_header();
        void parse_register_header_with_transport();
        void parse_register_header_without_transport();

        void parse_via_line();
    protected:
        /*std::string m_str_header_line;
        //std::string m_strMsgType;
        std::string m_strVia;
        std::string m_strBranch;
        std::string m_strRoute;
        std::string m_strMaxForwards;
        std::string m_strContact;
        std::string m_strFrom;
        std::string m_strTo;
        std::string m_strCallId;
        //std::string m_strCSeq;
        std::string m_strExpires;
        std::string m_strAllow;
        std::string m_strSupported;
        std::string m_strUserAgent;
        std::string m_strAuthorization;
        std::string m_strAllowEvents;
        std::string m_strContentLength;
        std::string m_str_allow_events;*/
        std::string m_str_from_tag;
    private:
        std::string m_strSipServerIp;
        int m_nSipServerPort;
        std::string m_strUserName;
        std::string m_strUserPassword;

        std::string m_strSipLocalIp;
        int m_nSipLocalPort;

        std::string m_strBranch;
        std::string m_strNetType;//TCP/UDP/SSL
    };
}
#endif