#ifndef __RANDOMKILLER_KILLER_H__
#define __RANDOMKILLER_KILLER_H__

#include "common.h"
#include "parser.h"

class Killer {
   protected:
    const MessageParser request_;
    const int64_t group_id_;

   public:
    Killer(const MessageParser& request, int64_t group_id);
    ~Killer() = default;
    void kill();
};

#endif