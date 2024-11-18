#include "SipMsgBaseStruct.hpp"
#include "SipMessageUtil.h"
WWW_AUTH::WWW_AUTH()
{

}
WWW_AUTH::~WWW_AUTH()
{

}

std::string WWW_AUTH::to_string()
{
	std::string strResult= " WWW-Authenticate: Digest ";
	{
		strResult += str_realm_Tag;
		strResult += m_str_realm;
		strResult += ", ";
	}
	
	{
		strResult += str_nonce_Tag;
		strResult += m_str_nonce;
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
		strResult += m_str_qop;
	}
	return strResult;
}
bool WWW_AUTH::from_string(const std::string strContent)
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
					m_str_realm = item.substr(subIndex, item.length() - subIndex);
				}
			}
			else if (item.find(str_nonce_Tag) != std::string::npos)
			{
				std::size_t start_index = item.find(str_nonce_Tag);
				if (start_index != std::string::npos)
				{
					std::size_t subIndex = start_index + str_nonce_Tag.length();
					m_str_nonce = item.substr(subIndex, item.length() - subIndex);
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
					m_str_qop = item.substr(subIndex, item.length() - subIndex);
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