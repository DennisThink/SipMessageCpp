#include "SipReRegisterMsg.hpp"
#include "SipMessageUtil.h"
#include "SipMsgConstValue.hpp"
#include <iostream>
#include <cstring>
namespace DtSipMessageCpp
{
    CSipReRegisterMsg::CSipReRegisterMsg(){
    }

    CSipReRegisterMsg::~CSipReRegisterMsg(){}

    bool CSipReRegisterMsg::parse(const std::string& strMsg){
        auto allLines = CProtoUtil::SplitStringByLine(strMsg, "\n");
        for (const auto& item : allLines)
        {
            if (item.find(REGISTER_TYPE_HEADER) == 0)
            {
                m_str_header_line = item;
            }
            else if (item.find(VIA_HEADER) == 0)
            {
                m_str_via_line = item;
                parse_via_line();
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
        }
        parse_register_header();
        return true;
    }

    std::string CSipReRegisterMsg::dump() const{
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

        return strResult;
    }

    void CSipReRegisterMsg::create_header_line()
    {
        if (m_str_header_line.empty())
        {
            {
                std::string strMsgType = "REGISTER";
                strMsgType += " ";
                strMsgType += "sip:";
                strMsgType += m_strSipServerIp;
                strMsgType += ":";
                strMsgType += std::to_string(m_nSipServerPort);
                strMsgType += " SIP/2.0";


                //strResult += m_str_header_line;
                m_str_header_line = strMsgType;
            }
        }
    }
    std::string CSipReRegisterMsg::get_authorization_line()
    {
        return m_str_authorization_line;
    }
    std::string CSipReRegisterMsg::get_allow_events()
    {
        return m_str_allow_events_line;
    }

    void CSipReRegisterMsg::set_sip_server_ip_port(const std::string strIp, const int nPort)
    {
        m_strSipServerIp = strIp;
        m_nSipServerPort = nPort;
    }

    void CSipReRegisterMsg::set_sip_local_ip_port(const std::string strIp, const int nPort)
    {
        this->m_strSipLocalIp = strIp;
        this->m_nSipLocalPort = nPort;
    }
    void CSipReRegisterMsg::set_username_password(const std::string strUserName, const std::string strPassword)
    {
        this->m_strUserName = strUserName;
        this->m_strUserPassword = strPassword;
    }

    void CSipReRegisterMsg::set_net_type(const std::string strType)
    {
        m_strNetType = strType;
    }

    void CSipReRegisterMsg::set_branch(const std::string strBranch)
    {
        m_strBranch = strBranch;
    }

    void CSipReRegisterMsg::set_authorization(const std::string strAuthorization)
    {
        m_str_authorization_line = strAuthorization;
    }
    void CSipReRegisterMsg::parse_register_header()
    {
        if (m_str_header_line.find("transport") != std::string::npos)
        {
            parse_register_header_with_transport();
        }
        else
        {
            parse_register_header_without_transport();
        }
    }

    void CSipReRegisterMsg::create_from_line()
    {
        //From: "1009" <sip:1009@192.168.31.109>;tag=a2c95cb6bbf84183a634b0244b09dcd9
        m_str_from_line.clear();
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
    }

    void CSipReRegisterMsg::create_to_line()
    {
        //To: "1009" <sip:1009@192.168.31.109>
        m_str_to_line.clear();
        if (m_str_to_line.empty())
        {
            std::string strResult = "To: \"";
            strResult += m_strUserName;
            strResult += "\" <sip:";
            strResult += m_strUserName;
            strResult += "@";
            strResult += m_strSipServerIp;
            strResult += ">";
            m_str_to_line = strResult;
        }
    }
    
    bool CSipReRegisterMsg::create_c_seq_line()
    {
        if (m_str_c_seq_line.empty())
        {
            m_str_c_seq_line = "CSeq: " + std::to_string(m_n_c_seq) + " REGISTER";
        }
        return true;
    }
    void CSipReRegisterMsg::create_contact_line()
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
    }
    void CSipReRegisterMsg::set_allow_options(const std::string strAllowOptions)
    {
        m_str_allow_line = strAllowOptions;
    }

    void CSipReRegisterMsg::set_call_id(const std::string strCallId)
    {
        m_str_call_id_line = strCallId;
    }

    void CSipReRegisterMsg::set_content_length(const std::string strContentLength)
    {
        m_str_content_length_line = strContentLength;
    }
    
    void CSipReRegisterMsg::set_from_tag(const std::string strFromTag)
    {
        m_str_from_tag = strFromTag;
    }

    void CSipReRegisterMsg::set_expires(const std::string strExpires)
    {
        m_str_expires_line = strExpires;
    }
    void CSipReRegisterMsg::set_max_forwards(const std::string strMaxForwards)
    {
        m_str_max_forwards_line = strMaxForwards;
    }

    void CSipReRegisterMsg::create_via_line()
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
    }

    void CSipReRegisterMsg::parse_register_header_with_transport()
    {
        std::size_t nFirstPos = 0;
        std::size_t nSecondPos = 0;
        nSecondPos = m_str_header_line.find("sip:", nFirstPos);
        if (nSecondPos != std::string::npos)
        {
            nFirstPos = nSecondPos + std::strlen("sip:");
        }
        
        nSecondPos = m_str_header_line.find(":", nFirstPos);
        if(nSecondPos!=std::string::npos)
        {
            m_strSipServerIp = m_str_header_line.substr(nFirstPos, nSecondPos - nFirstPos);
            nFirstPos = nSecondPos + std::strlen(":");
        }

        nSecondPos = m_str_header_line.find(";transport=", nFirstPos);
        if (nSecondPos != std::string::npos)
        {
            std::string strPort = m_str_header_line.substr(nFirstPos, nSecondPos - nFirstPos);
            m_nSipServerPort = std::atoi(strPort.c_str());
            nFirstPos = nSecondPos + std::strlen(";transport=");
        }

        nSecondPos = m_str_header_line.find(" SIP/2.0", nFirstPos);
        if (nSecondPos != std::string::npos)
        {
            m_strNetType = m_str_header_line.substr(nFirstPos, nSecondPos - nFirstPos);
            nFirstPos = nSecondPos + std::strlen(" SIP/2.0");
        }
    }

    //REGISTER sip:192.168.31.109:5060 SIP/2.0
    void CSipReRegisterMsg::parse_register_header_without_transport()
    {
        std::size_t nFirstPos = 0;
        std::size_t nSecondPos = 0;
        nSecondPos = m_str_header_line.find("sip:", nFirstPos);
        if (nSecondPos != std::string::npos)
        {
            nFirstPos = nSecondPos + std::strlen("sip:");
        }

        nSecondPos = m_str_header_line.find(":", nFirstPos);
        if (nSecondPos != std::string::npos)
        {
            m_strSipServerIp = m_str_header_line.substr(nFirstPos, nSecondPos - nFirstPos);
            nFirstPos = nSecondPos + std::strlen(":");
        }

        nSecondPos = m_str_header_line.find(" ", nFirstPos);
        if (nSecondPos != std::string::npos)
        {
            std::string strPort = m_str_header_line.substr(nFirstPos, nSecondPos - nFirstPos);
            m_nSipServerPort = std::atoi(strPort.c_str());
            nFirstPos = nSecondPos + std::strlen(" ");
        }
    }

    void CSipReRegisterMsg::parse_via_line()
    {
        //Via: SIP/2.0/UDP 192.168.31.109:64998;rport;branch=z9hG4bKPj69ad7fa3a38d41159b63dcb5f8b38a69
        std::size_t firstIndex = 0;
        std::size_t secondIndex = 0;
        {
            secondIndex = m_str_via_line.find("SIP/2.0/");
            if (secondIndex != std::string::npos)
            {
                std::size_t startIndex = secondIndex + std::strlen("SIP/2.0/");
                firstIndex = m_str_via_line.find(" ", startIndex);
                m_strNetType = m_str_via_line.substr(startIndex, firstIndex - startIndex);
            }

            secondIndex = firstIndex;
            firstIndex = m_str_via_line.find(":", secondIndex);
            if (firstIndex != std::string::npos)
            {
                m_strSipLocalIp = m_str_via_line.substr(secondIndex + 1, firstIndex - secondIndex - 1);
            }

            secondIndex = firstIndex;
            firstIndex = m_str_via_line.find(";", secondIndex);
            if (firstIndex != std::string::npos)
            {
                std::string strPort = m_str_via_line.substr(secondIndex + 1, firstIndex - secondIndex);
                m_nSipLocalPort = std::atoi(strPort.c_str());
            }

            secondIndex = m_str_via_line.find("branch=", firstIndex);
            firstIndex = m_str_via_line.length();
            if (firstIndex != std::string::npos)
            {
                m_strBranch = m_str_via_line.substr(secondIndex + std::strlen("branch="), firstIndex - secondIndex);
            }

        }
    }
}