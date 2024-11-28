#include "SipMsgBaseStruct.hpp"
#include "SipMessageUtil.h"
#include "SipMsgConstValue.hpp"
#include "SipMessageUtil.h"
namespace DtSipMessageCpp
{
	WWW_AUTH::WWW_AUTH()
	{

	}
	WWW_AUTH::~WWW_AUTH()
	{

	}

	std::string WWW_AUTH::to_string()
	{
		std::string strResult;
		strResult = " " + m_str_auth_type + " Digest ";
		{
			strResult += str_realm_Tag;
			strResult += "\"";
			strResult += m_str_realm;
			strResult += "\"";
			strResult += ", ";
		}

		{
			strResult += str_nonce_Tag;
			strResult += "\"";
			strResult += m_str_nonce;
			strResult += "\"";
			strResult += ", ";
		}

		{
			strResult += str_stale_Tag;
			strResult += m_str_stale;
			strResult += ", ";
		}

		{
			strResult += str_algorithm_Tag;
			strResult += m_str_algorithm;
			strResult += ", ";
		}
		{
			strResult += str_qop_Tag;
			strResult += "\"";
			strResult += m_str_qop;
			strResult += "\"";
		}
		return strResult;
	}
	bool WWW_AUTH::from_string(const std::string strContent)
	{
		if (strContent.find(DtSipMessageCpp::WWW_AUTHENTICATE_HEADER) != std::string::npos)
		{
			m_str_auth_type = DtSipMessageCpp::WWW_AUTHENTICATE_HEADER;
		}
		if (strContent.find(DtSipMessageCpp::PROXY_AUTHENTICATE_HEADER) != std::string::npos)
		{
			m_str_auth_type = DtSipMessageCpp::PROXY_AUTHENTICATE_HEADER;
		}
		std::vector<std::string> allLine = DtSipMessageCpp::CProtoUtil::SplitStringByLine(strContent, ",");
		//realm
		{
			/*std::string str_realm_Tag = "realm=";
			std::string str_nonce_Tag = "nonce=";
			std::string str_stale_Tag = "stale=";
			std::string str_algorithm_Tag = "algorithm=";
			std::string str_qop_Tag = "qop=";*/
			for (auto item : allLine)
			{
				if (item.find(str_realm_Tag) != std::string::npos)
				{
					std::size_t start_index = item.find(str_realm_Tag);
					if (start_index != std::string::npos)
					{
						std::size_t subIndex = start_index + str_realm_Tag.length();
						//Remove ["] at the begin and end,so start+1 and length-2
						m_str_realm = item.substr(subIndex + 1, item.length() - subIndex - 2);
					}
				}
				else if (item.find(str_nonce_Tag) != std::string::npos)
				{
					std::size_t start_index = item.find(str_nonce_Tag);
					if (start_index != std::string::npos)
					{
						std::size_t subIndex = start_index + str_nonce_Tag.length();
						m_str_nonce = item.substr(subIndex + 1, item.length() - subIndex - 2);
					}
				}
				else if (item.find(str_stale_Tag) != std::string::npos)
				{
					std::size_t start_index = item.find(str_stale_Tag);
					if (start_index != std::string::npos)
					{
						std::size_t subIndex = start_index + str_stale_Tag.length();
						m_str_stale = item.substr(subIndex, item.length() - subIndex);
					}
				}
				else if (item.find(str_algorithm_Tag) != std::string::npos)
				{
					std::size_t start_index = item.find(str_algorithm_Tag);
					if (start_index != std::string::npos)
					{
						std::size_t subIndex = start_index + str_algorithm_Tag.length();
						m_str_algorithm = item.substr(subIndex, item.length() - subIndex);
					}
				}
				else if (item.find(str_qop_Tag) != std::string::npos)
				{
					std::size_t start_index = item.find(str_qop_Tag);
					if (start_index != std::string::npos)
					{
						std::size_t subIndex = start_index + str_qop_Tag.length();
						std::size_t endIndex = item.find("\"", subIndex + 1);
						if (endIndex != std::string::npos)
						{
							m_str_qop = item.substr(subIndex + 1, endIndex - subIndex - 1);
						}

					}
				}
			}
		}
		return true;
	}
	std::string WWW_AUTH::get_realm()
	{
		return m_str_realm;
	}
	std::string WWW_AUTH::get_nonce()
	{
		return m_str_nonce;
	}
	std::string WWW_AUTH::get_stale()
	{
		return m_str_stale;
	}
	std::string WWW_AUTH::get_algorithm()
	{
		return m_str_algorithm;
	}
	std::string WWW_AUTH::get_qop()
	{
		return m_str_qop;
	}

	std::string WWW_AUTH::get_auth_type()
	{
		return m_str_auth_type;
	}
	Authorization::Authorization()
	{

	}
	Authorization::~Authorization()
	{

	}

	std::string Authorization::to_string()
	{
		std::string strResult;
		if (m_str_auth_type.empty())
		{
			strResult = "Authorization: Digest ";
		}
		else
		{
			strResult = "Proxy-Authorization: Digest ";
		}


		{
			strResult += str_user_name_Tag;
			strResult += "\"";
			strResult += m_str_user_name;
			strResult += "\"";
			strResult += ",";
		}
		{
			strResult += str_realm_Tag;
			strResult += "\"";
			strResult += m_str_realm;
			strResult += "\"";
			strResult += ",";
		}

		{
			strResult += str_nonce_Tag;
			strResult += "\"";
			strResult += m_str_nonce;
			strResult += "\"";
			strResult += ",";
		}
		{
			strResult += str_uri_Tag;
			strResult += "\"";
			strResult += m_str_uri;
			strResult += "\"";
			strResult += ",";
		}
		{
			strResult += str_response_Tag;
			strResult += "\"";
			strResult += m_str_response;
			strResult += "\"";
			strResult += ",";
		}
		{
			strResult += str_cnonce_Tag;
			strResult += "\"";
			strResult += m_str_cnonce;
			strResult += "\"";
			strResult += ",";
		}
		{
			strResult += str_nc_Tag;
			strResult += m_str_nc;
			strResult += ",";
		}
		{
			strResult += str_qop_Tag;
			//strResult += "\"";
			strResult += m_str_qop;
			//strResult += "\"";
			strResult += ",";
		}
		{
			strResult += str_algorithm_Tag;
			strResult += m_str_algorithm;
		}
		return strResult;
	}

	bool Authorization::from_string(const std::string strContent)
	{
		std::vector<std::string> allLine = DtSipMessageCpp::CProtoUtil::SplitStringByLine(strContent, ",");
		//realm
		{
			/*std::string str_realm_Tag = "realm=";
			std::string str_nonce_Tag = "nonce=";
			std::string str_stale_Tag = "stale=";
			std::string str_algorithm_Tag = "algorithm=";
			std::string str_qop_Tag = "qop=";*/
			for (auto item : allLine)
			{
				if (item.find(str_realm_Tag) != std::string::npos)
				{
					std::size_t start_index = item.find(str_realm_Tag);
					if (start_index != std::string::npos)
					{
						std::size_t subIndex = start_index + str_realm_Tag.length();
						//Remove ["] at the begin and end,so start+1 and length-2
						m_str_realm = item.substr(subIndex + 1, item.length() - subIndex - 2);
					}
				}
				else if (item.find(str_user_name_Tag) != std::string::npos)
				{
					std::size_t start_index = item.find(str_user_name_Tag);
					if (start_index != std::string::npos)
					{
						std::size_t subIndex = start_index + str_user_name_Tag.length();
						//Remove ["] at the begin and end,so start+1 and length-2
						m_str_user_name = item.substr(subIndex + 1, item.length() - subIndex - 2);
					}
				}
				else if (item.find(str_nonce_Tag) == 0)
				{
					std::size_t start_index = item.find(str_nonce_Tag);
					if (start_index != std::string::npos)
					{
						std::size_t subIndex = start_index + str_nonce_Tag.length();
						//romove the begin and end " of nonce
						m_str_nonce = item.substr(subIndex + 1, item.length() - subIndex - 2);
					}
				}
				else if (item.find(str_uri_Tag) == 0)
				{
					std::size_t start_index = item.find(str_uri_Tag);
					if (start_index != std::string::npos)
					{
						std::size_t subIndex = start_index + str_uri_Tag.length();
						m_str_uri = item.substr(subIndex + 1, item.length() - subIndex - 2);
					}
				}
				else if (item.find(str_response_Tag) == 0)
				{
					std::size_t start_index = item.find(str_response_Tag);
					if (start_index != std::string::npos)
					{
						std::size_t subIndex = start_index + str_response_Tag.length();
						m_str_response = item.substr(subIndex + 1, item.length() - subIndex - 2);
						//m_str_response = item.substr(subIndex, item.length() - subIndex);
					}
				}
				else if (item.find(str_cnonce_Tag) == 0)
				{
					std::size_t start_index = item.find(str_cnonce_Tag);
					if (start_index != std::string::npos)
					{
						std::size_t subIndex = start_index + str_cnonce_Tag.length();
						m_str_cnonce = item.substr(subIndex + 1, item.length() - subIndex - 2);
					}
				}
				else if (item.find(str_nc_Tag) == 0)
				{
					std::size_t start_index = item.find(str_nc_Tag);
					if (start_index != std::string::npos)
					{
						std::size_t subIndex = start_index + str_nc_Tag.length();
						m_str_nc = item.substr(subIndex, item.length() - subIndex);
					}
				}
				else if (item.find(str_qop_Tag) == 0)
				{
					std::size_t start_index = item.find(str_qop_Tag);
					if (start_index != std::string::npos)
					{
						std::size_t subIndex = start_index + str_qop_Tag.length();
						m_str_qop = item.substr(subIndex, item.length() - subIndex);
					}
				}
				else if (item.find(str_algorithm_Tag) != std::string::npos)
				{
					std::size_t start_index = item.find(str_algorithm_Tag);
					if (start_index != std::string::npos)
					{
						std::size_t subIndex = start_index + str_algorithm_Tag.length();
						m_str_algorithm = item.substr(subIndex, item.length() - subIndex);
					}
				}
			}
		}
		return true;
	}

	std::string Authorization::get_user_name()
	{
		return m_str_user_name;
	}
	std::string Authorization::get_realm()
	{
		return m_str_realm;
	}
	std::string Authorization::get_nonce()
	{
		return m_str_nonce;
	}

	std::string Authorization::get_algorithm()
	{
		return m_str_algorithm;
	}
	std::string Authorization::get_qop()
	{
		return m_str_qop;
	}

	std::string Authorization::get_uri()
	{
		return m_str_uri;
	}

	std::string Authorization::get_response()
	{
		return m_str_response;
	}

	std::string Authorization::get_cnonce()
	{
		return m_str_cnonce;
	}

	std::string Authorization::get_nc()
	{
		return m_str_nc;
	}

	bool Authorization::set_user_name(const std::string strUserName)
	{
		m_str_user_name = strUserName;
		return true;
	}

	bool Authorization::set_realm(const std::string strRealm)
	{
		m_str_realm = strRealm;
		return true;
	}

	bool Authorization::set_nonce(const std::string strNonce)
	{
		m_str_nonce = strNonce;
		return true;
	}

	bool Authorization::set_uri(const std::string strUri)
	{
		m_str_uri = strUri;
		return true;
	}

	bool Authorization::set_response(const std::string strResponse)
	{
		m_str_response = strResponse;
		return true;
	}

	bool Authorization::set_cnonce(const std::string strCnonce)
	{
		m_str_cnonce = strCnonce;
		return true;
	}

	bool Authorization::set_nc(const std::string strNc)
	{
		m_str_nc = strNc;
		return true;
	}

	bool Authorization::set_qop(const std::string strQop)
	{
		m_str_qop = strQop;
		return true;
	}

	bool Authorization::set_algorithm(const std::string strAlgorithm)
	{
		m_str_algorithm = strAlgorithm;
		return true;
	}

	bool Authorization::set_auth_type(const std::string strAuthType)
	{
		m_str_auth_type = strAuthType;
		return true;
	}


	CSdpInfo::CSdpInfo()
	{

	}

	CSdpInfo::~CSdpInfo()
	{

	}

	std::string CSdpInfo::to_string() const
	{
		std::string strLineEnd = "\n";
		std::string strResult = "";
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

	bool CSdpInfo::from_string(const std::string strInfo)
	{
		std::string strSplit = "\n";
		auto allLines = DtSipMessageCpp::CProtoUtil::SplitStringByLine(strInfo, strSplit);
		using namespace DtSipMessageCpp;

		for (auto item : allLines)
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

		return true;
	}
}