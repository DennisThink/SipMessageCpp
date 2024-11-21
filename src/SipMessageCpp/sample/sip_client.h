#ifndef _SIP_CLIENT_H_
#define _SIP_CLIENT_H_
#include <string>
class SipClient
{
public:
	SipClient();
	virtual ~SipClient();
public:
	void set_user_name(const std::string str_user_name);
	void set_pass_word(const std::string str_pass_word);
	void set_sip_server_addr(const std::string serverIp, const int port);
	void send_sms(const std::string strReciver,const std::string strSms);
	std::string recv_sms();
protected:
	std::string m_str_user_name;
	std::string m_str_pass_word;
	std::string m_str_sip_server_ip;
	int m_sip_server_port;
protected:
	void register_to_server();
	std::string get_c_seq_string();
};
#endif