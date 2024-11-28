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
	bool set_max_forwards(int nMaxForwards);
	bool init_protocal();
	void do_register();
	void do_send_sms(const std::string strReciver, const std::string strContent);
	void do_call(const std::string strCalled);
	std::string get_next_message();
	bool handle_current_message(const std::string strMsg);
	std::string create_call_id();
public:
	bool is_registered() const;
protected:
	std::string get_first_register_message();
	std::string get_second_register_message(const std::string& strRsp);
	std::string get_send_sms_message(const std::string strReciver, const std::string strContent);
	std::string get_call_message(const std::string strCalled);
	bool handle_first_register_rsp(const std::string strRsp);
	bool handle_first_send_sms(const std::string strRsp);
	void init_first_register();
	void init_send_sms();
private:
	std::string create_c_seq();
	int get_c_seq();
	std::string create_branch();
	std::string create_from_tag();

private:
	std::string get_authorization_from_www_auth_for_client(const std::string strMethod, const std::string& strWwwAuth, const std::string strUser, const std::string strPass, const std::string strCnonce, const std::string strUri);
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

	int m_n_c_seq;
	//send_sms
	std::string m_strReciver;
	std::string m_strContent;
	//do_call
	std::string m_strCalled;

	bool m_b_registered;

private:
	std::string m_str_branch;
	std::string m_str_from_tag;
	int m_n_max_forwards;
};
#endif