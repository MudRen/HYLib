//Cracked by Kafei
// box.c ����

#include <ansi.h>
inherit ITEM;

void create() {
    set_name("����", ({"box"}));
    set_weight(100);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "ֻ");
        set("long", "�˺и�Լһ�߼�������֪������װ��ʲô������\n");
        set("material", "steel");
        set("value", 100);
        set("no_get", 1);
   }
}

void init() {
    object ob = this_object();

	 //if (!ob->query("flag"))
	 ob->set("flag", 0);
	 if( random(8)==1 )
		ob->set("bomb", 1+ random(2) );
	 else if( random(16)==1 )
		 ob->set("hunterbow", 1+ random(2) );
	 else if( random(16)==1 )
		 ob->set("shortbow", 1+ random(2) );
	 else if( random(5)!=1 )
		 ob->set("arrow", 1+ random(5) );

    add_action("do_open", "open");
}

int do_open(string arg) {
    object ob = this_object(), flag, npc, me=this_player();

    if ( !arg || arg != "box" )
        return notify_fail("��Ҫ��ʲô�򿪣�\n");

	if( me->is_busy() )return notify_fail("����æ���أ�\n") ;

    if ( me->query_skill("dodge") > 200 && me->query("jingli") > me->query("max_jingli")/2 ) {
        if (ob->query("flag") == 1) {
            message_vision("$N�����䣬����������һ�����ġ�\n", me);
            message_vision(HIR"$N��������һ��չ�������ִ��죡\n"NOR, me);
            me->start_busy(7 + random(5));
            flag = new(__DIR__"flag");
            flag->move(me);
            ob->set("flag", 0);
            return 1;
        }
        else if (ob->query("bomb") > 0 ) {
            message_vision(HIY"$N�����䣬����������һö��������\n"NOR, me);
            message_vision(HIW"$N���Ͻ����������������\n"NOR, me);
            me->start_busy(16 + random(10));
            flag = new(__DIR__"bomb");
            flag->move(me);
            ob->add("bomb", -1);
            return 1;
        }
        else if (ob->query("hunterbow") > 0 ) {
            flag = new(__DIR__"hunterbow");
            flag->move(me);
            message_vision(HIY"$N�����䣬����������һ$n��\n"NOR, me,flag);
            message_vision(HIW"$N���Ͻ���$n�������\n"NOR, me,flag);
            me->start_busy(8 + random(10));
            ob->add("hunterbow", -1);
            return 1;
		}
        else if (ob->query("shortbow") > 0 ) {
            flag = new(__DIR__"shortbow");
            flag->move(me);
            message_vision(HIY"$N�����䣬����������һ$n��\n"NOR, me,flag);
            message_vision(HIW"$N���Ͻ���$n�������\n"NOR, me,flag);
            me->start_busy(8 + random(5));
            ob->add("shortbow", -1);
            return 1;
		}
        else if (ob->query("arrow") > 0 ) {
            flag = new(__DIR__"arrow");
            flag->move(me);
			flag->set_amount(10);
            message_vision(HIY"$N�����䣬����������һ$n��\n"NOR, me,flag);
            message_vision(HIW"$N���Ͻ���$n�������\n"NOR, me,flag);
            me->start_busy(4 + random(6));
            ob->add("arrow", -1);
            return 1;
		}
        else {
            message_vision("$N�����䣬���������ǿյġ�\n", me);
            me->start_busy(8 + random(8));
            return 1;
        }
    }
    else {
        message_vision(HIR"$N�����䣬ͻȻ�����������֧ӲŬ��ȫ��������$N���ϣ�\n"NOR, me);
        me->receive_wound("qi", me->query("max_qi")+ 1);
        return 1;
    }

        return notify_fail("��Ҫ��ʲô��\n");
}
