#include "sip_client.h"

SipClient::SipClient()
{

}
SipClient::~SipClient()
{

}

void SipClient::set_user_name(const std::string str_user_name)
{
	m_str_user_name = str_user_name;
}
void SipClient::set_pass_word(const std::string str_pass_word)
{
	m_str_pass_word = str_pass_word;
}
void SipClient::set_sip_server_addr(const std::string serverIp, const int port)
{
	m_str_sip_server_ip = serverIp;
	m_sip_server_port = port;
}
void SipClient::send_sms(const std::string strReciver, const std::string strSms)
{

}
std::string SipClient::recv_sms()
{
	return "";
}

void SipClient::register_to_server()
{

}