#include "SipRegisterMsg.hpp"
#include "SipMessageUtil.h"
#include "SipMsgConstValue.hpp"
#include <iostream>
#include <cstring>
namespace DtSipMessageCpp
{
    CSipRegisterMsg::CSipRegisterMsg(){
    }

    CSipRegisterMsg::~CSipRegisterMsg(){}

    bool CSipRegisterMsg::parse(const std::string& strMsg){
        auto allLines = CProtoUtil::SplitStringByLine(strMsg,"\n");
        for (const auto& item : allLines)
        {
            if (item.find(REGISTER_TYPE_HEADER) == 0)
            {
                m_str_header_line = item;
            }
            else if (item.find(VIA_HEADER) == 0)
            {
                m_strVia = item;
                parse_via_line();
            }
            else if (item.find(ROUTE_HEADER) == 0)
            {
                m_strRoute = item;
            }
            else if (item.find(MAX_FORWARDS_HEADER) == 0)
            {
                m_strMaxForwards = item;
            }
            else if(item.find(CONTACT_HEADER) == 0)
            {
                m_strContact = item;
            }
            else if(item.find(TO_HEADER) == 0)
            {
                m_strTo = item;
            }
            else if (item.find(FROM_HEADER) == 0)
            {
                m_strFrom = item;
            }
            else if (item.find(CALL_ID_HEADER) == 0)
            {
                m_strCallId = item;
            }
            else if (item.find(CSEQ_HEADER) == 0)
            {
                m_strCSeq = item;
            }
            else if (item.find(EXPIRES_HEADER) == 0)
            {
                m_strExpires = item;
            }
            else if (item.find(ALLOW_HEADER) == 0)
            {
                m_strAllow = item;
            }
            else if (item.find(ALLOW_EVENTS_HEADER) == 0)
            {
                m_strAllowEvents = item;
            }
            else if (item.find(USER_AGENT_HEADER) == 0)
            {
                m_strUserAgent = item;
            }
            else if (item.find(AUTHORIZATION_HEADER) == 0)
            {
                m_strAuthorization = item;
            }
            else if (item.find(CONTENT_LENGTH_HEADER) != std::string::npos)
            {
                m_strContentLength = item;
            }
            else if (item.find(SUPPORTED_HEADER) != std::string::npos)
            {
                m_strSupported = item;
            }
        }
        parse_register_header();
        return true;
    }

    std::string CSipRegisterMsg::dump() const{
        std::string strResult;
        std::string strLineEnd = "\n";
        {

        }
        {
            std::string strMsgType = "REGISTER";
            strMsgType += " ";
            strMsgType += "sip:";
            strMsgType += m_strSipServerIp;
            strMsgType += ":";
            strMsgType += std::to_string(m_nSipServerPort);
            strMsgType += " SIP/2.0";


            //strResult += m_str_header_line;
            strResult += strMsgType;
            strResult += strLineEnd;
        }
        //Via
        {
            //strResult += m_strVia;
            //Via: SIP/2.0/UDP 192.168.31.109:64998;rport;branch=z9hG4bKPj69ad7fa3a38d41159b63dcb5f8b38a69
            {
                strResult += VIA_HEADER;
                strResult += " SIP/2.0/";
                strResult += m_strNetType;
                strResult += " ";
                strResult += m_strSipLocalIp;
                strResult += ":";
                strResult += std::to_string(m_nSipLocalPort);
                strResult += ";rport;branch=";
                strResult += m_strBranch;
            }
            strResult += strLineEnd;
        }
        if (!m_strRoute.empty())
        {
            strResult += m_strRoute;
            strResult += strLineEnd;
        }
        {
            strResult += m_strMaxForwards;
            strResult += strLineEnd;
        }
        if(!m_strContact.empty())
        {
            strResult += m_strContact;
            strResult += strLineEnd;
        }
        
        {
            strResult += m_strTo;
            strResult += strLineEnd;
        }

        {
            strResult += m_strFrom;
            strResult += strLineEnd;
        }

        {
            strResult += m_strCallId;
            strResult += strLineEnd;
        }
        {
            strResult += m_strCSeq;
            strResult += strLineEnd;
        }
        if(!m_strExpires.empty())
        {
            strResult += m_strExpires;
            strResult += strLineEnd;
        }

        {
            strResult += m_strAllow;
            strResult += strLineEnd;
        }
        if(!m_strSupported.empty())
        {
            strResult += m_strSupported;
            strResult += strLineEnd;
        }

        if(!m_strUserAgent.empty())
        {
            strResult += m_strUserAgent;
            strResult += strLineEnd;
        }

        if(!m_strAuthorization.empty())
        {
            strResult += m_strAuthorization;
            strResult += strLineEnd;
        }

        if(!m_strAllowEvents.empty())
        {
            strResult += m_strAllowEvents;
            strResult += strLineEnd;
        }

        {
            strResult += m_strContentLength;
        }

        return strResult;
    }


    void CSipRegisterMsg::set_sip_server_ip_port(const std::string strIp, const int nPort)
    {
        m_strSipServerIp = strIp;
        m_nSipServerPort = nPort;
    }

    void CSipRegisterMsg::set_sip_local_ip_port(const std::string strIp, const int nPort)
    {
        this->m_strSipLocalIp = strIp;
        this->m_nSipLocalPort = nPort;
    }
    void CSipRegisterMsg::set_username_password(const std::string strUserName, const std::string strPassword)
    {
        this->m_strUserName = strUserName;
        this->m_strUserPassword = strPassword;
    }

    void CSipRegisterMsg::set_net_type(const std::string strType)
    {
        m_strNetType = strType;
    }

    void CSipRegisterMsg::set_branch(const std::string strBranch)
    {
        m_strBranch = strBranch;
    }

    void CSipRegisterMsg::set_authorization(const std::string strAuthorization)
    {
        m_strAuthorization = strAuthorization;
    }

    void CSipRegisterMsg::set_allow_options(const std::string strAllowOptions)
    {
        m_strAllow = strAllowOptions;
    }
    void CSipRegisterMsg::set_call_id(const std::string strCallId)
    {
        m_strCallId = strCallId;
    }
    void CSipRegisterMsg::set_content_length(const std::string strContentLength)
    {
        m_strContentLength = strContentLength;
    }

    void CSipRegisterMsg::set_max_forwards(const std::string strMaxForwards)
    {
        m_strMaxForwards = strMaxForwards;
    }

    void CSipRegisterMsg::set_from_tag(const std::string strFromTag)
    {
        m_str_from_tag = strFromTag;
    }
    void CSipRegisterMsg::set_c_seq(const std::string strSeq)
    {
        m_strCSeq = strSeq;
    }
    std::string CSipRegisterMsg::get_header_line()
    {
        return m_str_header_line;
    }

    void CSipRegisterMsg::create_header_line()
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

    std::string CSipRegisterMsg::get_via_line()
    {
        return m_strVia;
    }

    std::string CSipRegisterMsg::get_route_line()
    {
        return "";
    }

    std::string CSipRegisterMsg::get_to_line()
    {
        return m_strTo;
    }

    std::string CSipRegisterMsg::get_from_line()
    {
        return m_strFrom;
    }

    std::string CSipRegisterMsg::get_call_id_line()
    {
        return m_strCallId;
    }

    std::string CSipRegisterMsg::get_c_seq_line()
    {
        return m_strCSeq;
    }

    std::string CSipRegisterMsg::get_expires_line()
    {
        return m_strExpires;
    }

    std::string CSipRegisterMsg::get_allow_line()
    {
        return m_strAllow;
    }

    std::string CSipRegisterMsg::get_supported_line()
    {
        return m_strSupported;
    }

    std::string CSipRegisterMsg::get_user_agent_line()
    {
        return m_strUserAgent;
    }

    std::string CSipRegisterMsg::get_content_length_line()
    {
        return m_strContentLength;
    }
    //std::string 
    std::string CSipRegisterMsg::get_max_forwards_line()
    {
        return m_strMaxForwards;
    }

    void CSipRegisterMsg::parse_register_header()
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
    void CSipRegisterMsg::parse_register_header_with_transport()
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
    void CSipRegisterMsg::parse_register_header_without_transport()
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

    void CSipRegisterMsg::create_via_line()
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
            m_strVia = strResult;
        }
    }

    void CSipRegisterMsg::create_from_line()
    {
        //From: "1009" <sip:1009@192.168.31.109>;tag=a2c95cb6bbf84183a634b0244b09dcd9
        if (m_strFrom.empty())
        {
            std::string strResult = "From: \"";
            strResult += m_strUserName;
            strResult += "\" <sip:";
            strResult += m_strUserName;
            strResult += "@";
            strResult += m_strSipServerIp;
            strResult += ">;tag=";
            strResult += m_str_from_tag;
            m_strFrom = strResult;
        }
    }
    void CSipRegisterMsg::create_to_line()
    {
        //To: "1009" <sip:1009@192.168.31.109>
        if (m_strTo.empty())
        {
            std::string strResult = "To: \"";
            strResult += m_strUserName;
            strResult += "\" <sip:";
            strResult += m_strUserName;
            strResult += "@";
            strResult += m_strSipServerIp;
            strResult += ">";
            m_strTo = strResult;
        }
    }

    void CSipRegisterMsg::parse_via_line()
    {
        //Via: SIP/2.0/UDP 192.168.31.109:64998;rport;branch=z9hG4bKPj69ad7fa3a38d41159b63dcb5f8b38a69
        std::size_t firstIndex = 0;
        std::size_t secondIndex = 0;
        {
            secondIndex = m_strVia.find("SIP/2.0/");
            if (secondIndex != std::string::npos)
            {
                std::size_t startIndex = secondIndex + std::strlen("SIP/2.0/");
                firstIndex = m_strVia.find(" ", startIndex);
                m_strNetType = m_strVia.substr(startIndex, firstIndex - startIndex);
            }
            
            secondIndex = firstIndex;
            firstIndex = m_strVia.find(":", secondIndex);
            if (firstIndex != std::string::npos)
            {
                m_strSipLocalIp = m_strVia.substr(secondIndex+1, firstIndex - secondIndex-1);
            }

            secondIndex = firstIndex;
            firstIndex = m_strVia.find(";", secondIndex);
            if (firstIndex != std::string::npos)
            {
                std::string strPort = m_strVia.substr(secondIndex+1, firstIndex - secondIndex);
                m_nSipLocalPort = std::atoi(strPort.c_str());
            }

            secondIndex = m_strVia.find("branch=", firstIndex);
            firstIndex = m_strVia.length();
            if (firstIndex != std::string::npos)
            {
                m_strBranch = m_strVia.substr(secondIndex + std::strlen("branch="), firstIndex - secondIndex);
            }

        }
    }
}