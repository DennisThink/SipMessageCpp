#ifndef _SIP_CLIENT_PROTOCAL_HANDLER_H_
#define _SIP_CLIENT_PROTOCAL_HANDLER_H_
#include <string>
class sip_client_protocal_handler
{
public:
	sip_client_protocal_handler();
	virtual ~sip_client_protocal_handler();
public:
	bool set_user_name_pass_word(const std::string strUserName, const std::string strPassWord);
	bool set_sip_server_ip_port(const std::string strIp,const int nPort);
	bool set_sip_client_ip_port(const std::string strIp, const int nPort);
	bool set_client_type(const std::string strClientType);
	bool set_net_type(const std::string strNetType);
	bool init_protocal();
	void do_register();
	std::string get_next_message();
	bool handle_current_message(const std::string strMsg);
protected:
	std::string get_first_register_message();
	std::string get_second_register_message(const std::string& strRsp);
	bool handle_first_register_rsp(const std::string strRsp);
	void init_first_register();
protected:
	std::string m_str_call_id;
	std::string m_strWaitForSend;
	std::string m_str_user_name;
	std::string m_str_pass_word;
	std::string m_str_sip_server_ip;
	int m_n_sip_server_port;
	std::string m_str_sip_client_ip;
	int m_n_sip_client_port;
	std::string m_str_client_type;
	std::string m_str_net_type;
};
#endif