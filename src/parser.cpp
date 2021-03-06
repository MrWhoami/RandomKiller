#include "parser.h"

using namespace cq;
using namespace std;

const string TRIGGER = "你累了吧";
const string AT_START = "[CQ:at,qq=";
const string AT_END = "]";

MessageParser::MessageParser(const std::string msg)
    : msg_(msg), valid_(false), start_(0), end_(60), target_(0) {
    // Check the trigger word.
    size_t location_start = msg.find(TRIGGER);
    if (location_start == string::npos) return;

    // Get the target string
    location_start = msg.find_first_of(AT_START);
    if (location_start == string::npos) return;
    size_t location_end = msg.find_first_of(AT_END, location_start);
    if (location_end == string::npos) return;
    string id_str = msg.substr(location_start + AT_START.length(), location_end - location_start - AT_START.length());
    try {
        target_ = stoi(id_str);
    }
    catch(const invalid_argument& e) {
        logging::info("Parser", string("Cannot parse: ") + msg_);
        return;
    }
    catch(const out_of_range& e) {
        logging::info("Parser", string("Too large: ") + msg_);
        return;
    }
    valid_ = true;

}

string MessageParser::msg() const { return msg_; }

bool MessageParser::valid() const { return valid_; }

uint32_t MessageParser::start() const { return start_; }

uint32_t MessageParser::end() const { return end_; }

int64_t MessageParser::target() const { return target_; }

// 你累了吧 [CQ:at,qq=844548205] aaa