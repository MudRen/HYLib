
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"���߲�ԭ"NOR);
	set("long", GRN @LONG
 ���������������ϳ��������̵��ʲݣ�����׺���ϵ�С�׻���ʹ��
�����˾��þ�����죬վ��������Կ���Զ���Ĵ󺣣�������Ϊ���ﶼû
�иߴ��ֲ�
LONG NOR);
set("magicroom",1);
set("magicset",1);
	set("exits", ([
		"east" : __DIR__"dong17",
                "west" : __DIR__"dong1"+(random(7)+3),
	]));
if (random(3)==0)
	set("exits", ([
		"eastwest" : __DIR__"dong1"+(random(7)+3),
                "southwest" : __DIR__"dong1"+(random(7)+1),
	]));
if (random(4)==1)
	set("exits", ([
		"south" : __DIR__"dong1"+(random(7)+1),
                "north" : __DIR__"dong17",
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
