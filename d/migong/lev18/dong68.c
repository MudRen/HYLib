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
		"west" : __DIR__"dong6"+(random(7)+3),
		"east" : __DIR__"dong6"+(random(7)+3),
		"south" : __DIR__"dong69",
		"north" : __DIR__"dong6"+(random(7)+3),
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong6"+(random(7)+3),
		"east" : __DIR__"dong69",
		"south" : __DIR__"dong6"+(random(7)+3),
		"north" : __DIR__"dong6"+(random(7)+3),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong69",
		"north" : __DIR__"dong52",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong69",
		"west" : __DIR__"dong52",
	]));

         set("objects", ([
              __DIR__"npc/lev8" : 6,
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
