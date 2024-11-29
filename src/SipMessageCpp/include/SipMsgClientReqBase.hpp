#ifndef _DT_SIP_MSG_CLIENT_REQ_BASE_H_
#define _DT_SIP_MSG_CLIENT_REQ_BASE_H_
#include <string>
#include "SipMessageBase.hpp"
namespace DtSipMessageCpp
{
    class CSipMsgClientReqBase:public CSipMessageBase
    {
    public:
        CSipMsgClientReqBase();
        virtual ~CSipMsgClientReqBase();

        virtual bool parse(const std::string& strMsg);
        virtual std::string dump() const;
    public:
        void set_sip_server_ip_port(const std::string strIp, const int nPort);
        void set_sip_local_ip_port(const std::string strIp, const int nPort);
        void set_username_password(const std::string strUserName, const std::string strPassword);
        void set_net_type(const std::string strType);
        void set_branch(const std::string strBranch);
        void set_authorization(const std::string strAuthorization);
        void set_allow_options(const std::string strAllowOptions);
        void set_call_id(const std::string strCallId);
        void set_content_length(const std::string strContentLength);
        void set_max_forwards(const std::string strMaxForwards);
        void set_from_tag(const std::string strFromTag);
        void set_route(const std::string strRoute);
    public:
        std::string get_header_line();
        std::string get_c_seq_line();
        std::string get_via_line();
        std::string get_route_line();
        std::string get_to_line();
        std::string get_from_line();
        std::string get_call_id_line();
        std::string get_expires_line();
        std::string get_allow_line();
        std::string get_supported_line();
        std::string get_user_agent_line();
        std::string get_content_length_line();
        std::string get_max_forwards_line();
    protected:
        virtual bool create_header_line();
        virtual bool create_c_seq_line();
        virtual bool create_via_line();
        virtual bool create_route_line();
        virtual bool create_to_line();
        virtual bool create_from_line();
        virtual bool create_call_id_line();
        virtual bool create_expires_line();
        virtual bool create_allow_line();
        virtual bool create_supported_line();
        virtual bool create_user_agent_line();
        virtual bool create_content_length_line();
        virtual bool create_max_forwards_line();
    public:
        bool create_all_lines();
        bool set_c_seq(const int nCSeq);

    protected:
    protected:
        int m_n_c_seq;
        std::string m_str_header_line;
        std::string m_str_c_seq_line;
        //std::string AppendNotEmptyString(const std::string& strOrg, const std::string& item);
        std::string m_str_to_line;
        std::string m_str_from_line;
        std::string m_str_via_line;
        std::string m_str_branch_line;
        std::string m_str_route_line;
        std::string m_str_max_forwards_line;
        std::string m_str_contact_line;


        std::string m_str_call_id_line;
        //std::string m_strCSeq;
        std::string m_str_expires_line;
        std::string m_str_allow_line;
        std::string m_str_supported_line;
        std::string m_str_user_agent_line;
        std::string m_str_authorization_line;
        std::string m_str_allow_events_line;
        std::string m_str_content_length_line;

    protected:
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