
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"�绯֮��"NOR);
	set("long", HIY @LONG
   ������ط�,����ʮ�ֵ�ǿ��,������һ����ȴ������������,������
����ɢ������,���Ѿ��޷����������ĵ�����,����С�������վ����
�ⱻǿ���ķ��ƴ����Ǹ�����������Ԩ.
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
        set("outdoors", "migong");
	set("exits", ([
		"south" : __DIR__"dong12",
                "north" : __DIR__"dong12",
		"east" : __DIR__"dong35",
		"west" : __DIR__"dong11",
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong12",
                "north" : __DIR__"dong35",
	]));
if (random(2)==0)
	set("exits", ([
		"west" : __DIR__"dong11",
                "east" : __DIR__"dong35",
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

