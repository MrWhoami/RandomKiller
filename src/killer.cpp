#include "killer.h"

#include <cstdlib>
#include <ctime>

using namespace cq;
using namespace std;

Killer::Killer(const MessageParser& request, int64_t group_id) : request_(request), group_id_(group_id) {
}

void Killer::kill() {
    srand(time(0));
    int rd_num = rand();
    int total_pos = (request_.end() - request_.start());
    total_pos = total_pos < 0 ? 0 : total_pos;
    int result = rd_num % total_pos + request_.start();
    send_group_message(
        group_id_,
        message::MessageSegment::at(request_.target()) + string(" 那就休息") + to_string(result) + string("分钟吧"));
}
