
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
		"west" : __DIR__"dong5"+(random(4)+1),
		"east" : __DIR__"dong5"+(random(4)+3),
		"south" : __DIR__"dong51",
		"north" : __DIR__"dong53",
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong53",
		"north" : __DIR__"dong51",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong51",
		"west" : __DIR__"dong53",
	]));

if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong5"+(random(4)+1),
		"east" : __DIR__"dong5"+(random(4)+3),
		"south" : __DIR__"dong5"+(random(4)+1),
		"north" : __DIR__"dong5"+(random(4)+3),
	]));
        set("objects", ([
              __DIR__"npc/lev2" : 6,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

