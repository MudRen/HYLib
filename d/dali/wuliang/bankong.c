// bankong.c
// bbb 1997/6/11
// Modify By River 98/12
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "���");
	set("long", @LONG
���ų�һ���亹������ȫ�����ʹ����������α�ס���ɵ���֦����ʱ��
�ڰ�գ���סҡ�Σ�������ȥ��ֻ��������������������ǲ�����ͷ����Χֻ
����֦�ڲ�ͣ��ҡ�Ρ����������£������µ�����Σ����֡�
LONG
	);
        set("outdoors", "����");
	setup();
}

void init()
{
        add_action("do_move", "pa");
        add_action("do_move", "climb");
        add_action("do_move", "move");
        add_action("do_down", "down");
}

int do_down(string arg)
{
	object me;
 	me = this_player();
	message_vision(HIR "$N�ɿ�˫�֣�����������������׹ȥ�����߷���������\n" NOR, me);
        me->unconcious();
        me->move(__DIR__"xiaoxi");
	return 1;
}

int do_move(string arg)
{
	object me = this_player();
        if ( !arg || arg!="yabi") return 0;
        message_vision("$NС�ĵ���ס��֦�����±���ȥ��\n" , me);
        me->move(__DIR__"shushang");
        return 1; 
}
