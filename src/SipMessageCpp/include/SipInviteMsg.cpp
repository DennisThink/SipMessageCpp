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
            std::cout << "ITEM: " << item << std::endl;
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

            {
                if (item.find(SDP_PROTOCAL_VERSION_HEADER) == 0)
                {
                    m_strsdpProtocalVersion = item;
                }
                else if (item.find(SDP_OWNER_SESSION_IDENTIFIER_HEADER) == 0)
                {
                    m_strsdpOwnerSessionIndentifier = item;
                }
                else if (item.find(SDP_SESSION_NAME_HEADER) == 0)
                {
                    m_strsdpSessionName = item;
                }
                else if (item.find(SDP_SESSION_INFORMATION_HEADER) == 0)
                {
                    m_strsdpSessionInformation = item;
                }
                else if (item.find(SDP_URI_OF_DESCRIPTION_HEADER) == 0)
                {
                    m_strsdpUriOfDescription = item;
                }
                else if (item.find(SDP_EMAIL_ADDRESS_HEADER) == 0)
                {
                    m_strsdpEmailAddress = item;
                }
                else if (item.find(SDP_PHONE_NUMBER_HEADER) == 0)
                {
                    m_strsdpPhoneNumber = item;
                }
                else
                if (item.find(SDP_CONNECTION_INFORMATION_HEADER) == 0)
                {
                    m_strsdpConnectionInformation = item;
                }
                else if (item.find(SDP_BANDWIDTH_INFORMATION_HEADER) == 0)
                {
                    m_strsdpBandwidthInformation = item;
                }
                else
                if (item.find(SDP_TIME_ZONE_ADJUSTMENTS_HEADER) == 0)
                {
                    m_strsdpTimeZoneAdjustments = item;
                }
                else if (item.find(SDP_ENCRYPTION_KEY_HEADER) == 0)
                {
                    m_strsdpEncryptionKey = item;
                }
                else if (item.find(SDP_ZERO_OR_MORE_SESSION_ATTRIBUTE_LINES_HEADER) == 0)
                {
                    m_strsdpZeroOrMoreSessionAttributeLines.push_back(item);
                }
            }
        }
        return true;
    }

    std::string CSipInviteMsg::dump() const{

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
            strResult += m_strContentType;
            strResult += strLineEnd;
        }
        {
            strResult += m_strProxyAuthorization;
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

        {
            strResult += strLineEnd;
            
            strResult += m_strsdpProtocalVersion;
            strResult += strLineEnd;
            
            strResult += m_strsdpOwnerSessionIndentifier;
            strResult += strLineEnd;

            strResult += m_strsdpSessionName;
            strResult += strLineEnd;

            strResult += m_strsdpSessionInformation;
            strResult += strLineEnd;

            strResult += m_strsdpUriOfDescription;
            strResult += strLineEnd;

            strResult += m_strsdpEmailAddress;
            strResult += strLineEnd; 
            
            strResult += m_strsdpPhoneNumber;
            strResult += strLineEnd; 
            
            strResult += m_strsdpConnectionInformation;
            strResult += strLineEnd; 
            
            strResult += m_strsdpBandwidthInformation;
            strResult += strLineEnd;

            //std::vector<std::string> 
            strResult += m_strsdpTimeZoneAdjustments;
            strResult += strLineEnd;

            strResult += m_strsdpEncryptionKey;
            strResult += strLineEnd;

            for (const auto& item : m_strsdpZeroOrMoreSessionAttributeLines)
            {
                strResult += item;
            }
            strResult += strLineEnd;
        }

        return strResult;

    }
}