#include "CSipRegisterServerRsp.hpp"
#include "SipMsgConstValue.hpp"
#include "SipMessageUtil.h"
namespace DtSipMessageCpp
{
    CSipRegisterServerRsp::CSipRegisterServerRsp()
    {

    }
    CSipRegisterServerRsp::~CSipRegisterServerRsp()
    {

    }

    bool CSipRegisterServerRsp::parse(const std::string& strMsg)
    {
        auto allLines = CProtoUtil::SplitStringByLine(strMsg, "\n");
        for (const auto& item : allLines)
        {
            if (item.find(SIP_RSP_HEADER) == 0)
            {
                m_strSipRspHeader = item;
            }
            //std::cout << "ITEM: " << item << std::endl;
            else if (item.find(BYE_TYPE_HEADER) == 0)
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
            else if (item.find(WWW_AUTHENTICATE_HEADER) != std::string::npos)
            {
                m_strWwwAuthentite = item;
            }
        }
        return true;
    }
    std::string CSipRegisterServerRsp::get_rsp_code()
    {
        return "";
    }
    std::string CSipRegisterServerRsp::get_rsp_message()
    {
        return "";
    }
    std::string CSipRegisterServerRsp::get_www_auth() const
    {
        return m_strWwwAuthentite;
    }

    std::string CSipRegisterServerRsp::dump() const
    {
        std::string strResult;
        std::string strLineEnd = "\n";
        {
            strResult += m_strSipRspHeader;
            strResult += strLineEnd;
        }
        {
            strResult += m_strVia;
            strResult += strLineEnd;
        }
        if(0)
        {
            strResult += m_strMaxForwards;
            strResult += strLineEnd;
        }

        {
            strResult += m_strFrom;
            strResult += strLineEnd;
        }

        {
            strResult += m_strTo;
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
            strResult += m_strUserAgent;
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
            strResult += m_strWwwAuthentite;
            strResult += strLineEnd;
        }

        {
            strResult += m_strContentLength; 
        }


        return strResult;
    }
}