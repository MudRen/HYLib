
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"̿���ż�"NOR);
	set("long",YEL @LONG
    �����ǿ�ӵ��.���ܿ�������һ����Χ���ұڳ��������ھ�ĺۼ�
�Լ���ľͷ�������������ݵ��Ҷ�.�ڵ���������������.ר���˿�ͨ��
ʹ��.
LONG NOR);

set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong5"+(random(5)+1),
		"east" : __DIR__"dong5"+(random(5)+4),
		"south" : __DIR__"dong53",
		"north" : __DIR__"dong54",
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong5"+(random(5)+1),
		"east" : __DIR__"dong4"+(random(5)+1),
		"south" : __DIR__"dong5"+(random(5)+4),
		"north" : __DIR__"dong4"+(random(5)+1),
	]));
        set("objects", ([
              __DIR__"npc/lev6" : 6,
              __DIR__"npc/lev4" : 7,
              "/clone/box/gboxm" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

