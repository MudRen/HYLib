// /d/wudang/husunchou.c  �����

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","�����");
        set("long", @LONG
��ò������������ɽ���������ʯ�βɽ��̹ǣ����涼���������£�
�±�ƽ����������Ҳ�����ʵǡ����ܴ�ݲ�������һ��ӭ����(song)�µ�����
���±ߡ�
LONG                           
        );
	set("outdoors", "�䵱");
        set("exits", ([
                "northdown":__DIR__"gudao2",
        ]));
        set("item_desc", ([
                "song" :
"���ǿ�ǧ��ӭ���ɣ����������������ɱ���ڻ��֣�����һ�����õĽ���֧�ŵ㡣\n",
        ]));

        set("objects",([
                __DIR__"npc/monkey" : 3,

        ]));

        setup();
}

void init()
{
        add_action("do_pa", ({ "climb", "pa" }));
        add_action("do_bang", ({ "tie", "bang" }));
}                   

int do_pa(string arg)
{
        object me;

        me=this_player();
        if ( !arg || arg != "down" )
            return notify_fail("��Ҫ��������\n");
        if (!( present("sheng zi", this_player())))
              return notify_fail("û��֧�ŵ㣬����ô������\n");
	if (!me->query_temp("mark/bang"))
              return notify_fail("û��֧�ŵ㣬����������ɱѽ����\n");

        message_vision("$N���������������ȥ��\n", me);
        if ((int)me->query_skill("force", 1) < 20) 
           {
           message_vision(RED"ɽ��ͻȻתǿ��$N�����������޷���ס���壬һ��ҡ�Σ��ֱ����˻�ȥ��\n"NOR, me);
            message_vision(HIR"$N����һ����һ����ת��������ʱ���˹�ȥ��\n"NOR, me);
            me->unconcious();
            return 1;
           }
        me->move(__DIR__"shanya1");
	tell_room(environment(me), me->name() + "����������������\n", ({ me }));
        me->delete_temp("mark/bang");
     	return 1;
}

int do_bang(string arg)
{      
        object me;
        me = this_player();
        if (!( present("sheng zi", this_player())))
            return notify_fail("��Ҫ��ʲô��\n");

        if ( !arg || arg != "song" )
            return notify_fail("��Ҫ��ʲô��\n");
	if (me->query_temp("mark/bang"))
		return notify_fail("�����Ѿ�����ˡ�\n");
        message_vision("$N����ϸϸ�ذ�����һ�˰����������ϡ�\n", me);
        me->set_temp("mark/bang",1);
        return 1;
}
