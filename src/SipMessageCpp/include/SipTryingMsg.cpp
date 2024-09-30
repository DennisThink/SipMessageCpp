#include "SipTryingMsg.hpp"
#include "SipMessageUtil.h"
#include "SipMsgConstValue.hpp"
namespace DtSipMessageCpp
{
    CSipTryingMsg::CSipTryingMsg(){
    }

    CSipTryingMsg::~CSipTryingMsg(){}

    bool CSipTryingMsg::parse(const std::string& strMsg){
        auto allLines = CProtoUtil::SplitStringByLine(strMsg, "\n");
        for (const auto& item : allLines)
        {
            //std::cout << "ITEM: " << item << std::endl;
            if (item.find(TRYING_TYPE_HEADER) != std::string::npos)
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
            else if (item.find(CONTENT_TYPE_HEADER) == 0)
            {
                m_strContentType = item;
            }
            else if (item.find(PROXY_AUTHORIZATION_HEADER) == 0)
            {
                m_strProxyAuthorization = item;
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
            else if (item.find(ACCEPT_HEADER) != std::string::npos)
            {
                m_strAccept = item;
            }
            else if (item.find(PROXY_AUTHENTICATE_HEADER) != std::string::npos)
            {
                m_strProxyAuthenticate = item;
            }
        }
        return true;
    }

    std::string CSipTryingMsg::dump() const{
        std::string strResult;
        std::string strLineEnd = "\n";
        {
            strResult += m_strMsgType;
            strResult += strLineEnd;
        }
        {
            strResult += m_strVia;
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
            strResult += m_strContentLength;
        }

        return strResult;
    }
}