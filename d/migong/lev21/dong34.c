
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
        set("outdoors", "migong");
	set("exits", ([
		"southwest" : __DIR__"dong12",
                "northeast" : __DIR__"dong12",
		"eastup" : __DIR__"dong35",
		"westdown" : __DIR__"dong11",
	]));
if (random(3)==0)
	set("exits", ([
		"southup" : __DIR__"dong12",
                "northdown" : __DIR__"dong35",
	]));
if (random(3)==0)
	set("exits", ([
		"westsouth" : __DIR__"dong11",
                "eastnorth" : __DIR__"dong35",
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

