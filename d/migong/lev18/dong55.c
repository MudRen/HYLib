
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
		"west" : __DIR__"dong56",
		"east" : __DIR__"dong5"+(random(6)+1),
		"south" : __DIR__"dong5"+(random(6)+1),
		"north" : __DIR__"dong5"+(random(5)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong56",
		"north" : __DIR__"dong52",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong56",
		"west" : __DIR__"dong52",
	]));

if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong5"+(random(4)+3),
		"east" : __DIR__"dong5"+(random(5)+1),
		"south" : __DIR__"dong5"+(random(4)+3),
		"north" : __DIR__"dong5"+(random(5)+1),
	]));
        set("objects", ([
              __DIR__"npc/lev7" : 8,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

