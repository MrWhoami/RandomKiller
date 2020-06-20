#ifndef __RANDOMKILLER_KILLER_H__
#define __RANDOMKILLER_KILLER_H__

#include "common.h"
#include "parser.h"

class Killer {
   protected:
    const MessageParser request_;

   public:
    Killer(const MessageParser& request);
    ~Killer() = default;
    void kill();
};

#endif