
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"���ڽ̻�"NOR);
	set("long", HIM @LONG
�����ǿյ����İ��ڽ̻������,���ܵ�ǽ�ھ�Ȼ��
���˹����ɣ���Щ�˹���С���ģ���Ů�ġ����һ��ڲ�
ͣ�Ĳ����������������˹�����µ�������
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
	set("exits", ([
		"south" : __DIR__"dong4"+(random(9)+1),
                "north" : __DIR__"dong4"+(random(6)+4),
		"west" : __DIR__"dong4"+(random(9)+1),
                "east" : __DIR__"dong4"+(random(9)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong4"+(random(9)+1),
                "west" : __DIR__"dong4"+(random(6)+4),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong4"+(random(9)+1),
                "north" : __DIR__"dong4"+(random(9)+1),
		"west" : __DIR__"dong4"+(random(6)+4),
                "east" : __DIR__"dong4"+(random(9)+1),
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

