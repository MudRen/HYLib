
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
		"west" : __DIR__"dong16",
		"east" : __DIR__"dong52",
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong1"+(random(3)+4),
		"north" : __DIR__"dong1"+(random(3)+4),
		"west" : __DIR__"dong52",
                "east" : __DIR__"dong16",
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong16",
		"west" : __DIR__"dong52",
	]));

        set("objects", ([
              __DIR__"npc/lev2" : 2,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

