// lingshi.c
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
ֻ���տտ�����һ�������ϲ��з������ʯ�ס�����ϸ����������ʯ�׹�
�������ܸ�����ԭ���ǹ�Ĺ����ʦ�ֳ�Ӣ��С��Ůʦ���İ���֮�����������
�Ĺ׸�(guangai)ȴֻ����һ�룬Ҳ��֪��������ʬ�塣
LONG
        );

        set("exits", ([
                "east" : __DIR__"mishi7",
        ]));

        setup();
//        replace_program(ROOM);
}

void init()
{
	add_action("do_push",  ({ "push" }));
}

int do_push (string arg)
{
	object me = this_player();
	
	if( !arg || arg!="guangai" )
		return notify_fail("��Ҫ��ʲô��\n");
	if (me->query("neili") < 1000)
		return notify_fail("���þ����̵���������ϧ�׸���Ȼ��˿������\n");
	me->set("neili", (int)me->query("neili") - 200);
	message_vision(HIY"$Nʹ���ƿ��˹׸ǡ�\n"NOR, me);
	me->move(__DIR__"shiguan");
	return 1;
}