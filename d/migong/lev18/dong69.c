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
set("no_npc",1);
	set("exits", ([
		"west" : __DIR__"dong6"+(random(7)+3),
		"east" : __DIR__"dong6"+(random(7)+3),
		"south" : __DIR__"dong6"+(random(7)+3),
		"north" : __DIR__"dong70",
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong6"+(random(7)+3),
		"east" : __DIR__"dong6"+(random(7)+3),
		"south" : __DIR__"dong6"+(random(7)+3),
		"north" : __DIR__"dong70",
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong69",
		"west" : __DIR__"dong70",
	]));

       set("objects", ([
              __DIR__"npc/player" : 3,
              "/clone/box/gboxm" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
