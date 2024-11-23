#include "SipSmsMessage.hpp"
#include "SipMsgConstValue.hpp"
#include "SipMessageUtil.h"
namespace DtSipMessageCpp
{
    CSipSmsMessage::CSipSmsMessage(){
    }

    CSipSmsMessage::~CSipSmsMessage(){}

    bool CSipSmsMessage::parse(const std::string& strMsg){
        auto allLines = CProtoUtil::SplitStringByLine(strMsg, "\n");
        for (const auto& item : allLines)
        {
            if (item.find(MESSAGE_TYPE_HEADER) == 0)
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
            else if (item.find(CONTACT_HEADER) == 0)
            {
                m_strContact = item;
            }
            else if (item.find(TO_HEADER) == 0)
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
       // parse_register_header();
        return true;
        //return false;
    }

    std::string CSipSmsMessage::dump() const{
        std::string strResult;
        std::string strLineEnd = "\n";
        {

        }
        {
            std::string strMsgType = "MESSAGE";
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
        if (!m_strContact.empty())
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
        if (!m_strExpires.empty())
        {
            strResult += m_strExpires;
            strResult += strLineEnd;
        }

        {
            strResult += m_strAllow;
            strResult += strLineEnd;
        }
        if (!m_strSupported.empty())
        {
            strResult += m_strSupported;
            strResult += strLineEnd;
        }

        if (!m_strUserAgent.empty())
        {
            strResult += m_strUserAgent;
            strResult += strLineEnd;
        }

        if (!m_strAuthorization.empty())
        {
            strResult += m_strAuthorization;
            strResult += strLineEnd;
        }

        if (!m_strAllowEvents.empty())
        {
            strResult += m_strAllowEvents;
            strResult += strLineEnd;
        }

        {
            strResult += m_strContentLength;
        }

        return strResult;
    }


    std::string CSipSmsMessage::get_header_line()
    {
        return m_str_header_line;
    }
    std::string CSipSmsMessage::get_via_line()
    {
        return m_strVia;
    }
    std::string CSipSmsMessage::get_route_line()
    {
        return m_strRoute;
    }
    std::string CSipSmsMessage::get_to_line()
    {
        return m_strTo;
    }
    std::string CSipSmsMessage::get_from_line()
    {
        return m_strFrom;
    }
    std::string CSipSmsMessage::get_call_id_line()
    {
        return m_strCallId;
    }
    std::string CSipSmsMessage::get_c_seq_line()
    {
        return m_strCSeq;
    }
    std::string CSipSmsMessage::get_expires_line()
    {
        return m_strExpires;
    }
    std::string CSipSmsMessage::get_allow_line()
    {
        return m_strAllow;
    }

    std::string CSipSmsMessage::get_allow_events_line()
    {
        return m_strAllowEvents;
    }
    std::string CSipSmsMessage::get_supported_line()
    {
        return m_strSupported;
    }
    std::string CSipSmsMessage::get_user_agent_line()
    {
        return m_strUserAgent;
    }
    std::string CSipSmsMessage::get_content_length_line()
    {
        return m_strContentLength;
    }
    std::string CSipSmsMessage::get_max_forwards_line()
    {
        return m_strMaxForwards;
    }

    void CSipSmsMessage::parse_register_header()
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
    void CSipSmsMessage::parse_register_header_with_transport()
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
    void CSipSmsMessage::parse_register_header_without_transport()
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

    void CSipSmsMessage::create_via_line()
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

    void CSipSmsMessage::parse_via_line()
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
                m_strSipLocalIp = m_strVia.substr(secondIndex + 1, firstIndex - secondIndex - 1);
            }

            secondIndex = firstIndex;
            firstIndex = m_strVia.find(";", secondIndex);
            if (firstIndex != std::string::npos)
            {
                std::string strPort = m_strVia.substr(secondIndex + 1, firstIndex - secondIndex);
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