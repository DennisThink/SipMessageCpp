#include "sip_client.h"
#include "simple_cpp_sockets.h"
#include "SipMsgBaseStruct.hpp"
#include "CSipMsgCpp.hpp"
#include "md5/md5.h"
#include "SipMessageUtil.h"
#include "sip_client_protocal_handler.h"
static sip_client_protocal_handler g_clientProtoHandler;
static UDPClient g_socket(5060,"192.168.31.109");
static bool g_debug = true;
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

void SipClient::init_protocal()
{
    g_clientProtoHandler.set_sip_client_ip_port(g_socket.get_local_ip(), g_socket.get_local_port());
    g_clientProtoHandler.set_sip_server_ip_port(m_str_sip_server_ip, m_sip_server_port);
    g_clientProtoHandler.set_user_name_pass_word(m_str_user_name, m_str_pass_word);

}

void SipClient::do_register()
{
    g_clientProtoHandler.do_register();
    std::string strSendMsg = g_clientProtoHandler.get_next_message();
    do {
        g_socket.send_message(strSendMsg);
        if (g_debug)
        {
            std::cout << "=====================================" << std::endl;
            std::cout << "Client SEND:" << std::endl;
            std::cout << strSendMsg << std::endl;
            std::cout << "=====================================" << std::endl;
        }
        std::string strRecvMsg;
        g_socket.recv_message(strRecvMsg);
        if (g_debug)
        {
            std::cout << "=====================================" << std::endl;
            std::cout << "Client RECV:" << std::endl;
            std::cout << strRecvMsg << std::endl;
            std::cout << "=====================================" << std::endl;
        }
        g_clientProtoHandler.handle_current_message(strRecvMsg);
        strSendMsg = g_clientProtoHandler.get_next_message();
    } while (!strSendMsg.empty());
}

void SipClient::send_sms(const std::string strReciver, const std::string strSms)
{
    register_to_server();
}
std::string SipClient::recv_sms()
{
	return "";
}


void SipClient::register_to_server()
{

}