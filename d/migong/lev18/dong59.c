
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
		"west" : __DIR__"dong5"+(random(5)+4),
		"east" : __DIR__"dong5"+(random(5)+4),
		"south" : __DIR__"dong56",
		"north" : __DIR__"dong60",
	]));
if (random(4)==0)
	set("exits", ([
		"west" : __DIR__"dong5"+(random(5)+3),
		"east" : __DIR__"dong6"+(random(1)+1),
		"south" : __DIR__"dong5"+(random(5)+3),
		"north" : __DIR__"dong5"+(random(5)+3),
	]));
        set("objects", ([
              __DIR__"npc/lev6" : 6,
              __DIR__"npc/lev7" : 6,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

