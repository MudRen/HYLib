// Room: banshan2.c
// bbb 1997/06/11
// Modify By River 98/12
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "��ɽ");
	set("long", @LONG
��ɽ���ƺ������޾����Һ��·����в���ɰʯ��������һ����£�Խ����
Խ��ƽ����������Σ�±����������к�¡��¡������Խ��Խ�죬ֻ��ˮ������
���꽦�����ϣ��������ۡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "down" : __DIR__"banshan4",
        ]));
	set("no_clean_up", 0);
        set("outdoors", "����");

	setup();
}

void init()
{	
	add_action("do_down", "pa");
}

int do_down(string arg)
{
	object me = this_player();
        if (!arg || arg!="down") return 0;
	message_vision(HIR "$N�������ϣ����������һ�����ﵽ�˹ȵס�\n" NOR, me);
	me->move(__DIR__"gudi");
	return 1;
}
