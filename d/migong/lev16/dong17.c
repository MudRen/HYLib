
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
		"east" : __DIR__"dong1"+(random(7)+1),
		"south" : __DIR__"dong18",
                "west" : __DIR__"dong1"+(random(7)+1),
                "north" : __DIR__"dong1"+(random(7)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong1"+(random(8)+1),
                "west" : __DIR__"dong18",
	]));
if (random(4)==1)
	set("exits", ([
		"south" : __DIR__"dong1"+(random(8)+1),
                "north" : __DIR__"dong1"+(random(8)+1),
	]));

         set("objects", ([
"/clone/box/gboxm" : random(2),
              __DIR__"npc/lev2" : random(3),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
