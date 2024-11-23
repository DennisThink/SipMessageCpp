#ifndef _DT_SIP_SMS_MESSAGE_H_
#define _DT_SIP_SMS_MESSAGE_H_
#include <string>
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
        void create_via_line();
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
        std::string m_strContentLength;

        std::string m_str_from_tag;

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