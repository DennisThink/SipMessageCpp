#include "sip_client.h"
#include "SipMsgBaseStruct.hpp"
#include "CSipMsgCpp.hpp"
#include "md5/md5.h"
#include "SipMessageUtil.h"
#include "sip_client_protocal_handler.h"
#include "simple_cpp_sockets.h"
//static UDPClient g_socket(5060,"192.168.31.109");
static bool g_debug = true;
SipClient::SipClient()
{
    m_socket = nullptr;
}
SipClient::~SipClient()
{
    if (nullptr != m_socket)
    {
        delete m_socket;
        m_socket = nullptr;
    }
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
    if (nullptr == m_socket)
    {
        m_socket = new UDPClient(port, serverIp);
    }
    else
    {
        delete m_socket;
        m_socket = new UDPClient(port, serverIp);
    }
}

void SipClient::set_client_type(const std::string strClientType)
{
    m_str_client_type = strClientType;
}

void SipClient::init_protocal()
{
    m_handler.set_sip_client_ip_port(m_socket->get_local_ip(), m_socket->get_local_port());
    m_handler.set_sip_server_ip_port(m_str_sip_server_ip, m_sip_server_port);
    m_handler.set_user_name_pass_word(m_str_user_name, m_str_pass_word);
    m_handler.set_net_type("UDP");
    m_handler.init_protocal();
}

void SipClient::do_register()
{
    m_handler.do_register();
    std::string strSendMsg = m_handler.get_next_message();
    do {
        m_socket->send_message(strSendMsg);
        if (g_debug)
        {
            std::cout << "=====================================" << std::endl;
            std::cout << "Client SEND:" << std::endl;
            std::cout << strSendMsg << std::endl;
            std::cout << "=====================================" << std::endl;
        }
        std::string strRecvMsg;
        m_socket->recv_message(strRecvMsg);
        if (g_debug)
        {
            std::cout << "=====================================" << std::endl;
            std::cout << "Client RECV:" << std::endl;
            std::cout << strRecvMsg << std::endl;
            std::cout << "=====================================" << std::endl;
        }
        m_handler.handle_current_message(strRecvMsg);
        strSendMsg = m_handler.get_next_message();
    } while (!strSendMsg.empty());
}

void SipClient::send_sms(const std::string strReciver, const std::string strSms)
{
    m_handler.do_send_sms(strReciver,strSms);
    std::string strSendMsg = m_handler.get_next_message();
    do {
        m_socket->send_message(strSendMsg);
        if (g_debug)
        {
            std::cout << "=====================================" << std::endl;
            std::cout << "Client SEND:" << std::endl;
            std::cout << strSendMsg << std::endl;
            std::cout << "=====================================" << std::endl;
        }
        std::string strRecvMsg;
        m_socket->recv_message(strRecvMsg);
        if (g_debug)
        {
            std::cout << "=====================================" << std::endl;
            std::cout << "Client RECV:" << std::endl;
            std::cout << strRecvMsg << std::endl;
            std::cout << "=====================================" << std::endl;
        }
        m_handler.handle_current_message(strRecvMsg);
        strSendMsg = m_handler.get_next_message();
    } while (!strSendMsg.empty());
}
std::string SipClient::recv_sms()
{
   
    std::string strSendMsg = m_handler.get_next_message();
    do {
        m_socket->send_message(strSendMsg);
        if (g_debug)
        {
            std::cout << "=====================================" << std::endl;
            std::cout << "Client SEND:" << std::endl;
            std::cout << strSendMsg << std::endl;
            std::cout << "=====================================" << std::endl;
        }
        std::string strRecvMsg;
        m_socket->recv_message(strRecvMsg);
        if (g_debug)
        {
            std::cout << "=====================================" << std::endl;
            std::cout << "Client RECV:" << std::endl;
            std::cout << strRecvMsg << std::endl;
            std::cout << "=====================================" << std::endl;
        }
        m_handler.handle_current_message(strRecvMsg);
        strSendMsg = m_handler.get_next_message();
    } while (!strSendMsg.empty());
	return "";
}


void SipClient::register_to_server()
{

}