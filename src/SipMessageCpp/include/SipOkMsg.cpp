#include "SipOkMsg.hpp"
namespace DtSipMessageCpp
{
    CSipOkMsg::CSipOkMsg(){
    }

    CSipOkMsg::~CSipOkMsg(){}

    bool CSipOkMsg::parse(const std::string& strMsg){
        auto allLines = CProtoUtil::SplitStringByLine(strMsg, "\n");
        for (const auto& item : allLines)
        {
            //std::cout << "ITEM: " << item << std::endl;
            if (item.find(OK_200_HEADER) != std::string::npos)
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
            else if (item.find(CONTENT_DISPOSITION_HEADER) != std::string::npos)
            {
                m_strContentDisposition = item;
            }
            else if (item.find(REMOTE_PARTY_ID_HEADER) != std::string::npos)
            {
                m_strRemotePartyId = item;
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
                    else if (item.find(SDP_TIME_ZONE_ADJUSTMENTS_HEADER) == 0)
                    {
                        m_strsdpTimeZoneAdjustments = item;
                    }
                    else if (item.find(SDP_MEDIA_NAME_AND_TRANSPORT_ADDRESS_HEADER) == 0)
                    {
                        m_strsdpMediaAndTransport = item;
                    }
                    else if (item.find(SDP_TIME_THE_SESSION_IS_ACTIVE_HEADER) == 0)
                    {
                        m_strsdpTimeTheSessionIsActive = item;
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

    std::string CSipOkMsg::dump() const{

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
            strResult += m_strContact;
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
            strResult += m_strAllowEvents;
            strResult += strLineEnd;
        }

        {
            strResult += m_strContentType;
            strResult += strLineEnd;
        }

        {
            strResult += m_strContentDisposition;
            strResult += strLineEnd;
        }

        {
            strResult += m_strContentLength;
            strResult += strLineEnd;
        }

        {
            strResult += m_strRemotePartyId;
            strResult += strLineEnd;
            strResult += strLineEnd;
        }

        {

            strResult += m_strsdpProtocalVersion;
            strResult += strLineEnd;

            strResult += m_strsdpOwnerSessionIndentifier;
            strResult += strLineEnd;

            strResult += m_strsdpSessionName;
            strResult += strLineEnd;

            if (!m_strsdpSessionInformation.empty())
            {
                strResult += m_strsdpSessionInformation;
                strResult += strLineEnd;
            }

            if (!m_strsdpUriOfDescription.empty())
            {
                strResult += m_strsdpUriOfDescription;
                strResult += strLineEnd;
            }

            if (!m_strsdpEmailAddress.empty())
            {
                strResult += m_strsdpEmailAddress;
                strResult += strLineEnd;
            }

            if (!m_strsdpPhoneNumber.empty())
            {
                strResult += m_strsdpPhoneNumber;
                strResult += strLineEnd;
            }

            strResult += m_strsdpConnectionInformation;
            strResult += strLineEnd;

            if (!m_strsdpBandwidthInformation.empty())
            {
                strResult += m_strsdpBandwidthInformation;
                strResult += strLineEnd;
            }

            //std::vector<std::string> 
            if (!m_strsdpTimeZoneAdjustments.empty())
            {
                strResult += m_strsdpTimeZoneAdjustments;
                strResult += strLineEnd;
            }

            if (!m_strsdpEncryptionKey.empty())
            {
                strResult += m_strsdpEncryptionKey;
                strResult += strLineEnd;
            }

            if (!m_strsdpTimeTheSessionIsActive.empty())
            {
                strResult += m_strsdpTimeTheSessionIsActive;
                strResult += strLineEnd;
            }

            if (!m_strsdpMediaAndTransport.empty())
            {
                strResult += m_strsdpMediaAndTransport;
            }
            for (const auto& item : m_strsdpZeroOrMoreSessionAttributeLines)
            {
                strResult += strLineEnd;
                strResult += item;
            }
            //strResult += strLineEnd;
        }

        return strResult;
    }
}