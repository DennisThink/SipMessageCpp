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
    public:
        bool create_all_lines();
        bool set_c_seq(const int nCSeq);

    protected:
        virtual bool create_c_seq_line();
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
    };
}
#endif