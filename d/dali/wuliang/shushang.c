// shushang.c
// bbb 1997/06/11
// Modify By River 98/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ڵĴ������ǲ����֦��ͣ�ط�����֨֨������������ʱ�������
���ǹ��ڰ�գ���סҡ�Σ�������ȥ��ֻ�������������������������ͷ����
���±ں�������ϸ��(feng)��
LONG
	);
	set("item_desc", ([
	   "feng" : "��Ľ���ǿ���Թ�����\n"
        ]));
        set("outdoors", "����");

	setup();
}

void init()
{
        add_action("do_move", "gou");
        add_action("do_move", "reach");
        add_action("do_down", "move");
        add_action("do_down", "pa");
}

int do_down(string arg)
{
	object me;
 	me = this_player();
	message_vision(HIR "$N���������±ڣ������������ã�����֦���ˣ�$N��������׹ȥ��\n" NOR, me);
        me->unconcious();
	return 1;
}

int do_move(string arg)
{
	object me = this_player();
        if (!arg || arg!="feng") return 0;
        message_vision(HIR "$NС�ĵ���ס��֦�����·��ý�̽ȥ����ǿ��Ԯ���¡�\n"  NOR, me);
        me->move(__DIR__"banshan1");
        return 1; 
}
