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
}