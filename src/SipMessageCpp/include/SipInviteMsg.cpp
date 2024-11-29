#include "SipInviteMsg.hpp"
#include "SipMsgConstValue.hpp"
#include "SipMessageUtil.h"
#include <iostream>
namespace DtSipMessageCpp
{
    CSipInviteMsg::CSipInviteMsg(){
    }

    CSipInviteMsg::~CSipInviteMsg(){}

    bool CSipInviteMsg::parse(const std::string& strMsg){
        auto allLines = CProtoUtil::SplitStringByLine(strMsg, "\n");
        for (const auto& item : allLines)
        {
            if (item.find(INVITE_TYPE_HEADER) == 0)
            {
                m_str_header_line = item;
            }
            else if (item.find(VIA_HEADER) == 0)
            {
                m_str_via_line = item;
                //parse_via_line();
            }
            else if (item.find(ROUTE_HEADER) == 0)
            {
                m_str_route_line = item;
            }
            else if (item.find(MAX_FORWARDS_HEADER) == 0)
            {
                m_str_max_forwards_line = item;
            }
            else if (item.find(CONTACT_HEADER) == 0)
            {
                m_str_contact_line = item;
            }
            else if (item.find(TO_HEADER) == 0)
            {
                m_str_to_line = item;
            }
            else if (item.find(FROM_HEADER) == 0)
            {
                m_str_from_line = item;
            }
            else if (item.find(CALL_ID_HEADER) == 0)
            {
                m_str_call_id_line = item;
            }
            else if (item.find(CSEQ_HEADER) == 0)
            {
                m_str_c_seq_line = item;
            }
            else if (item.find(EXPIRES_HEADER) == 0)
            {
                m_str_expires_line = item;
            }
            else if (item.find(ALLOW_HEADER) == 0)
            {
                m_str_allow_line = item;
            }
            else if (item.find(ALLOW_EVENTS_HEADER) == 0)
            {
                m_str_allow_events_line = item;
            }
            else if (item.find(USER_AGENT_HEADER) == 0)
            {
                m_str_user_agent_line = item;
            }
            else if (item.find(AUTHORIZATION_HEADER) == 0)
            {
                m_str_authorization_line = item;
            }
            else if (item.find(CONTENT_LENGTH_HEADER) != std::string::npos)
            {
                m_str_content_length_line = item;
            }
            else if (item.find(SUPPORTED_HEADER) != std::string::npos)
            {
                m_str_supported_line = item;
            }
            else if (item.find(MIN_SE_HEADER) == 0)
            {
                m_str_min_se_line = item;
            }
            else if (item.find(SESSION_EXPIRES_HEADER) == 0)
            {
                m_str_session_expires_line = item;
            }
            else if (item.find(CONTENT_TYPE_HEADER) == 0)
            {
                m_str_content_type_line = item;
            }
        }

        std::size_t lineIndex = strMsg.find("\n\n");
        if (lineIndex != std::string::npos)
        {
            std::string strSubStr = strMsg.substr(lineIndex, strMsg.length() - lineIndex);
            m_sdp_info.from_string(strSubStr);
        }
        return true;
    }

    std::string CSipInviteMsg::dump() const{

        std::string strResult;
        std::string strLineEnd = "\n";
        if (!m_str_header_line.empty())
        {
            strResult += m_str_header_line;
            strResult += strLineEnd;
        }
        if (!m_str_via_line.empty())
        {
            strResult += m_str_via_line;
            strResult += strLineEnd;
        }
        if (!m_str_route_line.empty())
        {
            strResult += m_str_route_line;
            strResult += strLineEnd;
        }
        {
            strResult += m_str_max_forwards_line;
            strResult += strLineEnd;
        }
        if (!m_str_contact_line.empty())
        {
            strResult += m_str_contact_line;
            strResult += strLineEnd;
        }

        {
            strResult += m_str_to_line;
            strResult += strLineEnd;
        }

        {
            strResult += m_str_from_line;
            strResult += strLineEnd;
        }

        {
            strResult += m_str_call_id_line;
            strResult += strLineEnd;
        }
        {
            strResult += m_str_c_seq_line;
            strResult += strLineEnd;
        }
        if (!m_str_expires_line.empty())
        {
            strResult += m_str_expires_line;
            strResult += strLineEnd;
        }

        {
            strResult += m_str_allow_line;
            strResult += strLineEnd;
        }
        if (!m_str_supported_line.empty())
        {
            strResult += m_str_supported_line;
            strResult += strLineEnd;
        }

        if (!m_str_user_agent_line.empty())
        {
            strResult += m_str_user_agent_line;
            strResult += strLineEnd;
        }

        if (!m_str_authorization_line.empty())
        {
            strResult += m_str_authorization_line;
            strResult += strLineEnd;
        }

        if (!m_str_allow_events_line.empty())
        {
            strResult += m_str_allow_events_line;
            strResult += strLineEnd;
        }

        {
            strResult += m_str_content_length_line;
        }
        {
            strResult += m_sdp_info.to_string();
        }

        return strResult;

    }

    std::string CSipInviteMsg::get_contact_line()
    {
        return m_str_contact_line;
    }

    std::string CSipInviteMsg::get_content_type_line()
    {
        return m_str_content_type_line;
    }

    std::string CSipInviteMsg::get_session_expires_line()
    {
        return m_str_session_expires_line;
    }
    std::string CSipInviteMsg::get_min_se_line()
    {
        return m_str_min_se_line;
    }

    void CSipInviteMsg::set_called_number(const std::string strCalled)
    {
        m_str_called = strCalled;
    }

    void CSipInviteMsg::set_user_agent(const std::string strUserAgent)
    {
        m_strUserAgent = strUserAgent;
    }

    void CSipInviteMsg::set_content_type(const std::string strType)
    {
        m_strContentType = strType;
    }

    void CSipInviteMsg::set_content_length(const int nContentLength)
    {
        m_n_content_length = nContentLength;
    }

    void CSipInviteMsg::set_supported_line(const std::string strSupported)
    {
        m_str_supported_line = strSupported;
    }

    void CSipInviteMsg::set_session_expires(const int nSeconds)
    {
        m_n_session_expires = nSeconds;
    }

    void CSipInviteMsg::set_min_se(const int nSeconds) 
    {
        m_n_min_se = nSeconds;
    }

    bool CSipInviteMsg::create_via_line()
    {
        {
            std::string strResult;
            strResult += VIA_HEADER;
            strResult += " SIP/2.0/";
            strResult += m_strNetType;
            strResult += " ";
            strResult += m_strSipLocalIp;
            strResult += ":";
            strResult += std::to_string(m_nSipLocalPort);
            strResult += ";rport;branch=";
            strResult += m_strBranch;
            m_str_via_line = strResult;
        }
        return true;
    }

    bool CSipInviteMsg::create_from_line()
    {
        //From: "1009" <sip:1009@192.168.31.109>;tag=a2c95cb6bbf84183a634b0244b09dcd9
        if (m_str_from_line.empty())
        {
            std::string strResult = "From: \"";
            strResult += m_strUserName;
            strResult += "\" <sip:";
            strResult += m_strUserName;
            strResult += "@";
            strResult += m_strSipServerIp;
            strResult += ">;tag=";
            strResult += m_str_from_tag;
            m_str_from_line = strResult;
        }
        return true;
    }
    bool CSipInviteMsg::create_to_line()
    {
        //To: "1009" <sip:1009@192.168.31.109>
        if (m_str_to_line.empty())
        {
            std::string strResult = "To: ";
            strResult += "<sip:";
            strResult += m_str_called;
            strResult += "@";
            strResult += m_strSipServerIp;
            strResult += ">";
            m_str_to_line = strResult;
        }
        return true;
    }

    bool CSipInviteMsg::create_session_expires_line()
    {
        m_str_session_expires_line.clear();
        //"Session-Expires: 1800";
        if (m_str_session_expires_line.empty())
        {
            m_str_session_expires_line = "Session-Expires: " + std::to_string(m_n_session_expires);
        }
        return true;
    }

    bool CSipInviteMsg::create_min_se_line()
    {
        m_str_min_se_line.clear();
        if (m_str_min_se_line.empty())
        {
            m_str_min_se_line = "Min-SE: " + std::to_string(m_n_min_se);
        }
        return true;
    }

    bool CSipInviteMsg::create_user_agent_line()
    {
        m_str_user_agent_line.clear();
        if (m_str_user_agent_line.empty())
        {
            m_str_user_agent_line = "User-Agent: "+m_strUserAgent;
        }
        return true;
    }

    bool CSipInviteMsg::create_content_type_line()
    {
        m_str_content_type_line.clear();
        if (m_str_content_type_line.empty())
        {
            m_str_content_type_line = "Content-Type: " + m_strContentType;
        }
        return true;
    }

    bool CSipInviteMsg::create_content_length_line()
    {
        m_str_content_length_line.clear();
        if (m_str_content_length_line.empty())
        {
            m_str_content_length_line = "Content-Length:   " + std::to_string(m_n_content_length);
        }
        return true;
    }
    bool CSipInviteMsg::create_c_seq_line()
    {
        if (m_str_c_seq_line.empty())
        {
            m_str_c_seq_line = "CSeq: " + std::to_string(m_n_c_seq) + " INVITE";
        }
        return true;
    }

    bool CSipInviteMsg::create_header_line()
    {
        if (m_str_header_line.empty())
        {
            {
                std::string strMsgType = "INVITE";
                strMsgType += " ";
                strMsgType += "sip:";
                strMsgType += m_str_called;
                strMsgType += "@";
                strMsgType += m_strSipServerIp;
                strMsgType += ":";
                strMsgType += std::to_string(m_nSipServerPort);
                strMsgType += " SIP/2.0";


                //strResult += m_str_header_line;
                m_str_header_line = strMsgType;
            }
        }
        return true;
    }
}