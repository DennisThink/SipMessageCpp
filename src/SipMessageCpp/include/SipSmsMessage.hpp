#ifndef _DT_SIP_SMS_MESSAGE_H_
#define _DT_SIP_SMS_MESSAGE_H_
#include <string>
//#include <vector>
namespace DtSipMessageCpp
{
    class CSipSmsMessage
    {
    public:
        CSipSmsMessage();
        virtual ~CSipSmsMessage();

        virtual bool parse(const std::string& strMsg);
        virtual std::string dump() const;
    public:
        //set function list for dump function test
        void set_sip_server_ip_port(const std::string strIp, const int nPort);
        void set_sip_local_ip_port(const std::string strIp, const int nPort);
        void set_sender(const std::string strSender);
        void set_reciver(const std::string strReciver);
        //void set_username_password(const std::string strUserName, const std::string strPassword);
        void set_net_type(const std::string strType);
        void set_branch(const std::string strBranch);
        void set_authorization(const std::string strAuthorization);
        void set_allow_options(const std::string strAllowOptions);
        void set_call_id(const std::string strCallId);
        void set_content_length(const std::string strContentLength);
        void set_max_forwards(const std::string strMaxForwards);
        void set_from_tag(const std::string strFromTag);
        void set_c_seq(const std::string strSeq);
        void add_via_ip_port(const std::string strIp, const int port);
        void set_user_agent(const std::string strAgent);
        void set_allow_events(const std::string strAllowEvents);
        void set_content(const std::string strContent);
        void set_content_type(const std::string strType);
    public:
        std::string get_header_line();
        std::string get_via_line();
        std::string get_route_line();
        std::string get_to_line();
        std::string get_from_line();
        std::string get_call_id_line();
        std::string get_c_seq_line();
        std::string get_expires_line();
        std::string get_allow_line();
        std::string get_allow_events_line();
        std::string get_supported_line();
        std::string get_user_agent_line();
        std::string get_content_length_line();
        std::string get_max_forwards_line();

    public:
        void create_via_line();
        void create_header_line();
        void create_from_line();
        void create_to_line();

    protected:
        void parse_register_header();
        void parse_register_header_with_transport();
        void parse_register_header_without_transport();
        void parse_via_line();
    protected:
        std::string m_str_header_line;
        std::string m_strTo;
        std::string m_strFrom;
        std::string m_strVia;
        std::string m_strBranch;
        std::string m_strRoute;
        std::string m_strMaxForwards;
        std::string m_strContact;


        std::string m_strCallId;
        std::string m_strCSeq;
        std::string m_strExpires;
        std::string m_strAllow;
        std::string m_strSupported;
        std::string m_strUserAgent;
        std::string m_strAuthorization;
        std::string m_strAllowEvents;
        std::string m_strContentType;
        std::string m_strContentLength;

        std::string m_str_from_tag;

        std::string m_str_content;

    private:
        std::string m_strSipServerIp;
        int m_nSipServerPort;
        std::string m_strUserName;
        std::string m_strUserPassword;

        std::string m_strSipLocalIp;
        int m_nSipLocalPort;

        //Via IP and port may have many points and orders is important.
        std::string m_str_via_ip;//May have many, consider to change it to vector
        int m_n_via_port;//May have many, consider to change it to vector

        std::string m_strNetType;//TCP/UDP/SSL

        
        std::string m_str_sender;
        std::string m_str_reciver;
    };
}
#endif