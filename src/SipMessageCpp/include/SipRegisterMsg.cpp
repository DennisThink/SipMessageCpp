#include "SipRegisterMsg.hpp"
#include "SipMessageUtil.h"
#include "SipMsgConstValue.hpp"
#include <iostream>
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
                m_strMsgType = item;
            }
            else if (item.find(VIA_HEADER) == 0)
            {
                m_strVia = item;
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
            strMsgType += ";transport=";
            strMsgType += m_strNetType;
            strMsgType += " SIP/2.0";


            //strResult += m_strMsgType;
            strResult += strMsgType;
            strResult += strLineEnd;
        }
        {
            strResult += m_strVia;
            strResult += strLineEnd;
        }
        {
            strResult += m_strMaxForwards;
            strResult += strLineEnd;
        }
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
        {
            strResult += m_strExpires;
            strResult += strLineEnd;
        }

        {
            strResult += m_strAllow;
            strResult += strLineEnd;
        }

        {
            strResult += m_strSupported;
            strResult += strLineEnd;
        }


        {
            strResult += m_strUserAgent;
            strResult += strLineEnd;
        }


        {
            strResult += m_strAuthorization;
            strResult += strLineEnd;
        }


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
    void CSipRegisterMsg::set_authorization(const std::string strAuthorization)
    {
        m_strAuthorization = strAuthorization;
    }
    void CSipRegisterMsg::parse_register_header()
    {
        std::size_t nFirstPos = 0;
        std::size_t nSecondPos = 0;
        nSecondPos = m_strMsgType.find("sip:", nFirstPos);
        if (nSecondPos != std::string::npos)
        {
            nFirstPos = nSecondPos + std::strlen("sip:");
        }
        
        nSecondPos = m_strMsgType.find(":", nFirstPos);
        if(nSecondPos!=std::string::npos)
        {
            m_strSipServerIp = m_strMsgType.substr(nFirstPos, nSecondPos - nFirstPos);
            nFirstPos = nSecondPos + std::strlen(":");
        }

        nSecondPos = m_strMsgType.find(";transport=", nFirstPos);
        if (nSecondPos != std::string::npos)
        {
            std::string strPort = m_strMsgType.substr(nFirstPos, nSecondPos - nFirstPos);
            m_nSipServerPort = std::atoi(strPort.c_str());
            nFirstPos = nSecondPos + std::strlen(";transport=");
        }

        nSecondPos = m_strMsgType.find(" SIP/2.0", nFirstPos);
        if (nSecondPos != std::string::npos)
        {
            m_strNetType = m_strMsgType.substr(nFirstPos, nSecondPos - nFirstPos);
            nFirstPos = nSecondPos + std::strlen(" SIP/2.0");
        }
    }
}