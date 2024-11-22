#ifndef _SIP_CLIENT_H_
#define _SIP_CLIENT_H_
#include <string>
#include <memory>
#include "sip_client_protocal_handler.h"
class UDPClient;
class SipClient
{
public:
	SipClient();
	virtual ~SipClient();
public:
	void set_user_name(const std::string str_user_name);
	void set_pass_word(const std::string str_pass_word);
	void set_sip_server_addr(const std::string serverIp, const int port);
	void set_client_type(const std::string strClientType);
	void init_protocal();
	void do_register();
	void send_sms(const std::string strReciver,const std::string strSms);
	std::string recv_sms();
protected:
	std::string m_str_client_type;
	std::string m_str_user_name;
	std::string m_str_pass_word;
	std::string m_str_sip_server_ip;
	int m_sip_server_port;

	//
	sip_client_protocal_handler m_handler;
	UDPClient* m_socket;
protected:
	void register_to_server();
	std::string get_c_seq_string();
};
#endif