#include <string>
#include <iostream>

class CompanyA {
public:
  void sendClearText(const std::string &msg) {
    std::cout << "CompanyA::sendClearText : " << msg << std::endl;
  }
  void sendEncrypted(const std::string &msg) {
    std::cout << "CompanyA::sendEncrypted : " << msg << std::endl;
  }
};

class CompanyB {
public:
  void sendClearText(const std::string &msg) {
    std::cout << "CompanyB::sendClearText : " << msg << std::endl;
  }
  void sendEncrypted(const std::string &msg) {
    std::cout << "CompanyB::sendEncrypted : " << msg << std::endl;
  }
};

class CompanyZ {
public:
  void sendEncrypted(const std::string &msg) {
    std::cout << "CompanyZ::sendEncrypted : " << msg << std::endl;
  }
};

template<typename Company>
class MsgSender {
public:
  void sendClear(const std::string &msg) {
    Company c;
    c.sendClearText(msg);
  }
  void sendSecret(const std::string &msg) {
    Company c;
    c.sendEncrypted(msg);
  }
};

template<>
class MsgSender<CompanyZ> {
public:
  void sendSecret(const std::string &msg) {
    CompanyZ c;
    c.sendEncrypted(msg);
  }
};

template<typename Company>
class LoggingMsgSender : public MsgSender<Company> {
public:
  void sendClearMsg(const std::string &msg) {
    std::cout << "Logging start." << std::endl;
    // gcc: note: use ‘this->sendClear’ instead
    this->sendClear(msg);
    std::cout << "Logging finished." << std::endl;
  }
};

int main() {
  LoggingMsgSender<CompanyB> b_msg_sender;
  b_msg_sender.sendClearMsg("I'm b_msg_sender");

  MsgSender<CompanyZ> z_msg_sender;
  // error: ‘class MsgSender<CompanyZ>’ has no member named ‘sendClear’
  // z_msg_sender.sendClear("I'm z_msg_sender");
  z_msg_sender.sendSecret("iemm zhi msg shender");
}
