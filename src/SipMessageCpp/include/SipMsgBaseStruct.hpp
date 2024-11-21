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
	//std::string get_uri();
protected:
	//std::string m_str_uri;
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
	const std::string str_uri_Tag = "uri=";
};

class Authorization
{
public:
	Authorization();
	virtual ~Authorization();

	std::string to_string();
	bool from_string(const std::string strContent);
public:
	std::string get_user_name();
	std::string get_realm();
	std::string get_nonce();
	std::string get_uri();
	std::string get_response();
	std::string get_cnonce();
	std::string get_nc();
	std::string get_qop();
	std::string get_algorithm();


	bool set_user_name(const std::string strUserName);
	bool set_realm(const std::string strRealm);
	bool set_nonce(const std::string strNonce);
	bool set_uri(const std::string strUri);
	bool set_response(const std::string strResponse);
	bool set_cnonce(const std::string strCnonce);
	bool set_nc(const std::string strNc);
	bool set_qop(const std::string strQop);
	bool set_algorithm(const std::string strAlgorithm);
protected:
	std::string m_str_user_name;
	std::string m_str_realm;
	std::string m_str_nonce;
	std::string m_str_uri;
	std::string m_str_response;
	std::string m_str_cnonce;
	std::string m_str_nc;
	std::string m_str_qop;
	std::string m_str_algorithm;
protected:
	/*
	* "Authorization: Digest 
	username="1002",
	realm="192.168.31.109",
	nonce="fffe2121-d01f-4c89-ab62-12a030a1c10d",
	uri="sip:192.168.31.109:5060;transport=UDP",
	response="b4418b2b96e05ec2a0beb3c522edbcc9",
	cnonce="b3468b9ac6827d7c51e85ef96618190f",
	nc=00000002,
	qop=auth,
	algorithm=MD5")"; 
"
	*/
	const std::string str_user_name_Tag = "username=";
	const std::string str_realm_Tag = "realm=";
	const std::string str_nonce_Tag = "nonce=";
	const std::string str_uri_Tag = "uri=";
	const std::string str_response_Tag = "response=";
	const std::string str_cnonce_Tag = "cnonce=";
	const std::string str_nc_Tag = "nc=";
	const std::string str_stale_Tag = "stale=";
	const std::string str_algorithm_Tag = "algorithm=";
	const std::string str_qop_Tag = "qop=";
};

#endif