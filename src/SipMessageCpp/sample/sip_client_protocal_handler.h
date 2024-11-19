#ifndef _SIP_CLIENT_PROTOCAL_HANDLER_H_
#define _SIP_CLIENT_PROTOCAL_HANDLER_H_
#include <string>
class sip_client_protocal_handler
{
public:
	sip_client_protocal_handler();
	virtual ~sip_client_protocal_handler();
public:
	std::string get_next_message();
	bool handle_current_message(const std::string strMsg);
};
#endif