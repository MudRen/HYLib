// /d/wudang/shanya3.c  ɽ��

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","ɽ��");
        set("long", @LONG
����һ�涸�͵�ɽ�£�ʯ��ƽ���羵��������ˣ�ɽ��ε�����
�����������ף����˵�������������ѷž��ˣ��������޿���
��ŵĵط�������¼�ʮ�ɴ��п������ɣ�֦Ҷï�ܣ�����Բ����ð
�����������ﻬ�裬Ҳ�����������ϡ�
LONG                           
);
	set("outdoors", "�䵱");
        setup();
}

void init()
{
        add_action("do_pa", ({ "climb", "pa" }));
        add_action("do_jump",({ "tiao", "jump" }));
}

int do_pa(string arg)
{       object me,tmp;
        object *ob;
        int i;
        me=this_player();
        if ( !arg || (arg != "down" && arg != "up" ))
            return notify_fail("��Ҫ��������\n");
        if (! present("sheng zi", me)) 
            return notify_fail("û��֧�ŵ㣬����ô����\n");

        if (arg =="down")
            return notify_fail("�����޷����������ˡ�\n");

        message_vision("$N�����������������\n", me);
        me->add("neili", -random(20));
        me->receive_damage("jing", 60-(int)me->query_skill("dodge", 1)/20);
        me->move(__DIR__"shanya2");
	tell_room(environment(me), me->name() + "����������������\n", ({ me }));
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

int do_jump(string arg)
{       object me, tmp;
	object *ob;
	int i;

        me=this_player();
        if ( !arg || arg != "down" )
            return notify_fail("��Ҫ��������\n");
        message_vision("$N˫��һ�ɣ���׼�����������¡�\n"NOR, me);
	if (present("sheng zi", me))
           destruct(present("sheng zi",me));

        if (! present("mao tan", me))
          { 
            message_vision("$N��һ�����Ȱ�Ѹ�����䣬˲��͵��������ߣ���æ����ȥץ��ȴ���ֲ��˼��硣\n"NOR, me);
            message_vision(RED"��---��$Nһ���ҽУ�ֱ�����������ȥ��\n"NOR, me);
            me->set_temp("last_damage_from","ˤ��ɽ�µ�");
            me->die();
		if (tmp = present("corpse", this_object())) {
			ob = deep_inventory(tmp);
			i = sizeof(ob);
			while (i--) if (userp(ob[i])) ob[i]->move(this_object());
			destruct(tmp);
			if (me) tell_room(this_object(), me->name()+"��ʬ�Ƕ��Ҳ����ˡ�\n");
		}
            return 1;
          }
        message_vision(HIY"$N���ڿ��У���æ��ë̺չ������ʱ���˳�����ƮƮ�س�������ȥ��\n"NOR, me);
        me->move(__DIR__"wanniansong");
	tell_room(this_object(), me->name() + "���˹�����\n", ({ me }));
     write(HIY"�����ڰ�ȫ��½��\n"NOR);
	return 1;
}
