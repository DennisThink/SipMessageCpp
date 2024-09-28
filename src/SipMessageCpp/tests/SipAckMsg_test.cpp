#include <doctest/doctest.h>
#include "SipAckMsg.hpp"

TEST_CASE("SipAckMsg"){
    DtSipMessageCpp::CSipAckMsg baseMsg;
    std::string strSipMessageBase = R"(HELLO)";
    CHECK_FALSE(baseMsg.parse(strSipMessageBase));
    std::string strResult="Hello";
    CHECK_FALSE(strResult==baseMsg.dump());
}