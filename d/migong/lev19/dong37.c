
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
        set("outdoors", "migong");
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
	set("exits", ([
                "west" : __DIR__"dong33",
		"east" : __DIR__"dong38",
		"south" : __DIR__"dong35",
                "north" : __DIR__"dong32",
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong35",
                "west" : __DIR__"dong38",
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong3"+(random(3)+6),
                "north" : __DIR__"dong3"+(random(3)+6),
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

