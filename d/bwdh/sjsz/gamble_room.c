//Cracked by Kafei
// group bwdh/gamble_room
// Apache 09/29/98

#include <ansi.h>

inherit ROOM;

string long_desc();
string look_paizi();

void create() {
    set("short", "�ĳ�");
    set("long", (: long_desc :) );
    set("exits", ([
        "west"  : __DIR__"square",
    ]));
    set("item_desc", ([
        "paizi" : (: look_paizi :),
    ]));
    set("valid_startroom", 1);

    setup();
}

void init() {
    object ob = this_object();

    if ( !ob->query("status") ) ob->set("status", 0); // 1 for bet -1 for collect
    if ( !ob->query("round") ) ob->set("round", 0); // round number for current bet
    if ( !ob->query("east") ) ob->set("east", 0); // east bet ratio: n for n ~ 1, -n for 1 ~ n
    if ( !ob->query("west") ) ob->set("west", 0); // west bet ratio:
    if ( !ob->query("win") ) ob->set("win", "none"); // winning side

    add_action("do_bet", "bet");
    add_action("do_collect", "collect");
}

string look_paizi() {
    object ob = this_object();
    string msg;
    int i;

    if ( ob->query("status") == 1) {
        msg = HIY"\n" + sprintf("    �� %2d ��  ѹע��\n    ����������������", ob->query("round")) + "\n"NOR;
        i = to_int(ob->query("east"));
        if ( i > 0 )
            msg = msg + HIR"    ����  " + chinese_number(i) + "��һ\n"NOR;
        else if (i < 0)
            msg = msg + HIR"    ����  һ��" + chinese_number(-i) + "\n"NOR;
        i = to_int(ob->query("west"));
        if ( i > 0 )
            msg = msg + HIR"    ����  " + chinese_number(i) + "��һ\n"NOR;
        else if (i < 0)
            msg = msg + HIR"    ����  һ��" + chinese_number(-i) + "\n"NOR;
    }
    else if ( ob->query("status") == -1) {
        msg = HIY"\n" + sprintf("    �� %2d ��  �⸶��\n    ����������������", ob->query("round")) + "\n"NOR;
        if ( ob->query("win") == "east" )
            msg = msg + HIR"        ���ӻ�ʤ\n"NOR;
        else if (ob->query("win") == "west" )
            msg = msg + HIR"        ���ӻ�ʤ\n"NOR;
        else
            msg = msg + HIW"      ������Ӯ��\n"NOR;
        return msg;
    }
    else
        msg = HIG"    ���޶ľ�\n"NOR;
    return msg;
}

string long_desc() {
    string msg;
    object ob = this_object();

    if (ob->query("status") == 1 )
        msg = "�ĳ�����ɽ�˺���������������ҷ׷���ע�����˿�ĭ��ɵ�\n����������������۷�ֱ�������\n";
    else if (ob->query("status") == -1 )
        msg = "�ĳ��������⸶ʱ�䣬Ӯ��ϲ�����󣬵�����������ӣ����\n���Ѽ������ۣ������ࡣ\n";
    else
        msg = "�ĳ�����û��Ӫҵ��������������ġ�\n";

    msg = msg + "�ĳ����й���һ������(paizi)��\n";
    return msg;
}

int do_bet(string arg) {
    object ob = this_object();
    object me = this_player();
    object money;
    int i, balance;
    string side;

    if ( ob->query("status") != 1 )
        return notify_fail("���ڲ���ѹעʱ�䡣\n");

    if (sscanf(arg, "%s %d", side, i) != 2) 
        return notify_fail("ʲô��\n");

    if ( ((side != "east") && (side != "west")) )
        return notify_fail("ʲô��\n");

    if ( i < 0 )
        return notify_fail("�޶���һ��һ����������\n");

    money = present("silver_money", me);
    if( !money )
        return notify_fail("������û�����ֻ��ҡ�\n");
    if( (int)money->query_amount() < i)
        return notify_fail("������û����ô�������\n");
    money->set_amount((int)money->query_amount() - i);
    money->move(me);

    switch(side) {
    case "east" :   if ( me->query("bwdh_gamble/east_round") == ob->query("round") )
                        balance = me->query("bwdh_gamble/east_bet");
                    else
                        balance = 0;
                    me->set("bwdh_gamble/east_round", ob->query("round"));
                    if ( balance == 0 ) {
                        me->set("bwdh_gamble/east_bet", i);
                        write("��Ѻ��" + chinese_number(i) + "�������ڶ��ӡ�\n");
                        return 1;
                    }
                    else {
                        me->set("bwdh_gamble/east_bet", i + balance);
                        write("����Ѻ��" + chinese_number(i) + "�������ڶ��ӡ�\n");
                        return 1;
                    }
                    break;
    case "west" :   if ( me->query("bwdh_gamble/west_round") == ob->query("round") )
                        balance = me->query("bwdh_gamble/west_bet");
                    else
                        balance = 0;
                    me->set("bwdh_gamble/west_round", ob->query("round"));
                    if ( balance == 0 ) {
                        me->set("bwdh_gamble/west_bet", i);
                        write("��Ѻ��" + chinese_number(i) + "�������ڶ��ӡ�\n");
                        return 1;
                    }
                    else {
                        me->set("bwdh_gamble/west_bet", i + balance);
                        write("����Ѻ��" + chinese_number(i) + "�������ڶ��ӡ�\n");
                        return 1;
                    }
                    break;
    default : break;
    }

    return 1;
}

int do_collect() {
    object ob = this_object(), me = this_player(), money;
    int bet, ratio;
    string win_side;

    if ( ob->query("status") != -1 )
        return notify_fail("���ڲ����⸶ʱ�䡣\n");

    win_side = ob->query("win");
    if ( win_side != "east" && win_side != "west" )
        return notify_fail("������Ӯ�ҡ�\n");

    switch(win_side) {
    case "east" :   if ( me->query("bwdh_gamble/east_round") == ob->query("round") ) {
                        bet = me->query("bwdh_gamble/east_bet");
                        ratio = ob->query("east");
                    }
                    else {
                        write("�ĳ���ƶ��㡰�ߡ�����Цһ����һ�Ű����߳����⡣\n");
                        me->move(__DIR__"square");
                        return 1;
                    }
                    me->set("bwdh_gamble/east_round", 0);
                    break;
    case "west" :   if ( me->query("bwdh_gamble/west_round") == ob->query("round") ) {
                        bet = me->query("bwdh_gamble/west_bet");
                        ratio = ob->query("west");
                    }
                    else {
                        write("�ĳ���ƶ��㡰�ߡ�����Цһ����ȥ�к��������ˡ�\n");
                        return 1;
                    }
                    me->set("bwdh_gamble/west_round", 0);
                    break;
    default: break;
    }

    money = new("/clone/money/silver");
    if (ratio > 0)
        bet = bet + (int) (bet / ratio * 9 / 10);
    else
        bet = bet - bet * ratio * 9 / 10;
    money->set_amount(bet);
    money->move(me);
    me->set("bwdh_gamble/east_round", 0);
    write ("�ĳ�������" + chinese_number(bet) + "��������\n");
    return 1;
}

int valid_leave(object player, string dir) {
    if (!wizardp(player) && dir == "up")
        return notify_fail("�˼����˲�û��������ȥ���\n");

    return ::valid_leave(player, dir);
}