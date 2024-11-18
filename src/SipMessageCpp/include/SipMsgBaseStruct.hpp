#ifndef _SIP_MSG_BASE_STRUCT_H_
#define _SIP_MSG_BASE_STRUCT_H_
#include <string>
class WWW_AUTH
{
public:
	WWW_AUTH();
	virtual ~WWW_AUTH();

	std::string to_string();
	bool from_string(const std::string strContent);
public:
	std::string get_realm();
	std::string get_nonce();
	std::string get_stale();
	std::string get_algorithm();
	std::string get_qop();
protected:
	std::string m_str_realm;
	std::string m_str_nonce;
	std::string m_str_stale;
	std::string m_str_algorithm;
	std::string m_str_qop;
protected:
	const std::string str_realm_Tag = "realm=";
	const std::string str_nonce_Tag = "nonce=";
	const std::string str_stale_Tag = "stale=";
	const std::string str_algorithm_Tag = "algorithm=";
	const std::string str_qop_Tag = "qop=";
};

#endif