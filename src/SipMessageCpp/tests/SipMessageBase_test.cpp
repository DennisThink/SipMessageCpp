#include <doctest/doctest.h>
#include "SipMessageBase.hpp"

TEST_CASE("SipMessageBase"){
    DtSipMessageCpp::CSipMessageBase baseMsg;
    std::string strSipMessageBase = R"(HELLO)";
    CHECK_FALSE(baseMsg.parse(strSipMessageBase));
    std::string strResult="Hello";
    CHECK_FALSE(strResult==baseMsg.dump());
}