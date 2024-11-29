#ifndef _DT_SIP_INVITE_MSG_H_
#define _DT_SIP_INVITE_MSG_H_
#include "SipMsgClientReqBase.hpp"
#include "SipMsgBaseStruct.hpp"
#include <vector>
namespace DtSipMessageCpp
{
    class CSipInviteMsg:public CSipMsgClientReqBase
    {
    public:
        CSipInviteMsg();
        virtual ~CSipInviteMsg();

        virtual bool parse(const std::string& strMsg);
        virtual std::string dump() const;
    protected:
        virtual bool create_c_seq_line() override;
        virtual bool create_from_line() override;
        virtual bool create_header_line() override;
        virtual bool create_via_line() override;
        virtual bool create_to_line() override;
    public:
        void set_called_number(const std::string strCalled);
        void set_user_agent(const std::string strUserAgent);
        void set_content_type(const std::string strType);
        void set_content_length(const int nContentLength);
        std::string get_contact_line();
        std::string get_content_type_line();
        std::string get_session_expires_line();
        std::string get_min_se_line();
        void set_from_tag(const std::string strFromTag)
        {
            m_str_from_tag = strFromTag;
        }
        bool create_session_expires_line();
        bool create_min_se_line();
        bool create_user_agent_line();
        bool create_content_type_line();
        bool create_content_length_line();
        bool create_contact_line()
        {
            m_str_contact_line.clear();
            if (m_str_contact_line.empty())
            {
                //Contact: "1002" <sip:1002@192.168.31.109:64998;ob>
                std::string strResult = "Contact: \"";
                strResult += m_strUserName;
                strResult += "\" <sip:";
                strResult += m_strUserName;
                strResult += "@";
                strResult += m_strSipServerIp;
                strResult += ":";
                strResult += std::to_string(m_nSipLocalPort);
                strResult += ";ob>";//OB mean what?
                m_str_contact_line = strResult;
            }
            return true;
        }

        void set_supported_line(const std::string strSupportedLine);
        void set_session_expires(const int nSeconds);
        void set_min_se(const int nSeconds);

    public:
        CSdpInfo m_sdp_info;
    protected:
        std::string m_str_content_type_line;
        std::string m_str_session_expires_line;
        std::string m_str_min_se_line;
        //std::string m_str_user_agent_line;
        std::string m_str_from_tag;

        std::string m_str_called;
        std::string m_strUserAgent;
        std::string m_strContentType;
        int m_n_session_expires;
        int m_n_min_se;
        int m_n_content_length;
    };
}
#endif