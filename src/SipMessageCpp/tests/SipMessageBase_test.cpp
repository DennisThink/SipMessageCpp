#include <doctest/doctest.h>
#include "SipMessageBase.hpp"

TEST_CASE("SipMessageBase"){
    DtSipMessageCpp::CSipMessageBase baseMsg;
    CHECK(baseMsg.parse("Hello"));
    std::string strResult="Hello";
    CHECK(strResult==baseMsg.dump());
}