
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
		"east" : __DIR__"dong1"+(random(5)+1),
		"south" : __DIR__"dong15",
                "west" : __DIR__"dong1"+(random(5)+1),
                "north" : __DIR__"dong1"+(random(4)+1),
	]));
if (random(4)==0)
	set("exits", ([
		"east" : __DIR__"dong1"+(random(4)+1),
                "west" : __DIR__"dong15",
	]));
if (random(3)==1)
	set("exits", ([
		"south" : __DIR__"dong1"+(random(5)+1),
                "north" : __DIR__"dong1"+(random(5)+1),
	]));

         set("objects", ([
              __DIR__"npc/lev2" : random(3),
              __DIR__"npc/lev1" : random(3),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
