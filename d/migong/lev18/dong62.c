
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
		"west" : __DIR__"dong63",
		"east" : __DIR__"dong5"+(random(4)+1),
		"south" : __DIR__"dong6"+(random(4)+1),
		"north" : __DIR__"dong6"+(random(4)+1),
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong5"+(random(4)+1),
		"east" : __DIR__"dong6"+(random(2)+2),
		"south" : __DIR__"dong6"+(random(4)+1),
		"north" : __DIR__"dong6"+(random(4)+1),
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

