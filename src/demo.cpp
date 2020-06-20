#include <iostream>
#include <set>
#include <sstream>

#include <cqcppsdk/cqcppsdk.h>

#include "common.h"
#include "killer.h"
#include "parser.h"

using namespace cq;
using namespace std;

CQ_INIT {
    on_enable([] { logging::info("启用", APP_NAME_CHINESE + "插件已启用"); });

/*
    on_private_message([](const PrivateMessageEvent &event) {
        logging::info("RandomKiller", string("Recieved: ") + event.message);
        // Parse the message to check if if is a request.
        MessageParser message(event.message);
        if (!message.valid()) return;

        // Action!
        Killer killer(message);
        killer.kill();
        event.block(); // 阻止当前事件传递到下一个插件
    });
    */

    on_group_message([](const GroupMessageEvent &event) {
        // Check if the group is enabled.
        // TODO: Move checking group to a function and read config file.
        static const set<int64_t> ENABLED_GROUPS = {604756512};
        if (ENABLED_GROUPS.count(event.group_id) == 0) return;

        // Check if the bot itself is a manager
        GroupMember bot = get_group_member_info(event.group_id, get_login_user_id());
        if (bot.role == GroupRole::MEMBER) return;

        // Check if the sender is a manager or owner.
        GroupMember sender = get_group_member_info(event.group_id, event.user_id);
        if (sender.role == GroupRole::MEMBER && sender.user_id != 844548205) return;

        // Parse the message to check if if is a request.
        MessageParser message(event.message);
        if (!message.valid()) return;

        // Action!
        Killer killer(message, event.group_id);
        killer.kill();
        event.block(); // 阻止当前事件传递到下一个插件
    });
}

CQ_MENU(menu_demo_1) {
    logging::info("菜单", "菜单仍在开发");
}
