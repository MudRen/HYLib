
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"���߲�ԭ"NOR);
	set("long", GRN @LONG
 ���������������ϳ��������̵��ʲݣ�����׺���ϵ�С�׻���ʹ��
�����˾��þ�����죬վ��������Կ���Զ���Ĵ󺣣�������Ϊ���ﶼû
�иߴ��ֲ�һ��紵��������������������ʷ����˱仯!
LONG NOR);
set("magicroom",1);
set("magicset",1);
	set("exits", ([
		"east" : __DIR__"dong12",
		"south" : __DIR__"dong13",
                "west" : __DIR__"dong14",
                "north" : __DIR__"dong11",
                "down" : __DIR__"dong10",
	]));
set("no_npc",1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
void init()
{
        object me = this_player();
        me->start_busy(1);
        me->set("magicgift",1);
        return;
}
