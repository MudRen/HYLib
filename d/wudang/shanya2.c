// /d/wudang/shanya2.c  ɽ��

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","ɽ��");
        set("long", @LONG
����һ�涸�͵�ɽ�£�ʯ��ƽ���羵��������ˣ�ɽ��ε����絶���
������ף����˵�����
LONG);
	set("outdoors", "�䵱");
        setup();
}

void init()
{
        add_action("do_pa", ({ "climb", "pa" }));
}

int do_pa(string arg)
{       object me,tmp;
        object *ob;
        int i;
        me=this_player();
        if ( !arg ||( (arg != "down") && ( arg != "up") ) )
            return notify_fail("��Ҫ��������\n");
        if (! present("sheng zi", this_player()))
            return notify_fail("û��֧�ŵ㣬����ô����\n");

        if (arg =="down") {
           message_vision("$N���������������ȥ��\n", me);
           if ((int)me->query_skill("force", 1) < 20) {
            message_vision(RED"ɽ��ͻȻתǿ��$N�����������޷���ס���壬һ��ҡ�Σ��ֱ����˻�ȥ��\n"NOR, me);
            message_vision(HIR"$N����һ����һ����ת��������ʱ���˹�ȥ��\n"NOR, me);
            me->unconcious();
            return 1;
           }
           me->receive_damage("jing", random(20));
           me->add("neili", (int)me->query_skill("force", 1)/20-60);
           me->move(__DIR__"shanya3");
	tell_room(environment(me), me->name() + "����������������\n", ({ me }));
        }
        else
          {message_vision("$N���������������ȥ��\n", me);
           me->add("neili", -random(20));
           me->receive_damage("jing", 60-(int)me->query_skill("dodge", 1)/20);
           if ((int)me->query_skill("dodge",1)<180)
              me->improve_skill("dodge", me->query("dex")+random((int)me->query_skill("dodge",1)/10));
           me->move(__DIR__"shanya1");
	tell_room(environment(me), me->name() + "����������������\n", ({ me }));
          }
        if ((int)me->query("jing", 1)<0||(int)me->query("neili", 1)<0)
         {
            message_vision(RED"$NͻȻ��ð���ǣ�ҡҡ��׹������һ�򻬣�[��...]��һ��ͷ������������ȡ�\n"NOR, me);
            me->set_temp("last_damage_from","ˤ��ɽ�µ�");
            me->unconcious();
            me->die();
		if (tmp = present("corpse", this_object())) {
			ob = deep_inventory(tmp);
			i = sizeof(ob);
			while (i--) if (userp(ob[i])) ob[i]->move(this_object());
			destruct(tmp);
                        destruct("corpse");
                        if (me) tell_room(this_object(), me->name()+"��ʬ�Ƕ��Ҳ����ˡ�\n");
		}
         }

     return 1;
}
