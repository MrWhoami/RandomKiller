#ifndef __RANDOMKILLER_PARSER_H__
#define __RANDOMKILLER_PARSER_H__

#include "common.h"

class MessageParser {
   protected:
    const std::string msg_;
    bool valid_;
    uint32_t start_;
    uint32_t end_;
    uint32_t step_;
    uint64_t target_;

   public:
    MessageParser(const std::string msg);
    ~MessageParser() = default;
    bool valid() const;
    uint32_t start() const;
    uint32_t end() const;
    uint32_t step() const;
    int64_t target() const;
};

#endif