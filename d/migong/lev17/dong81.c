#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"ˮ��ɽ��"NOR);
	set("long", WHT @LONG
    ��һ�����صĵط����˴���һ�����ܶ�Χ������ɽ�����ɽ��
ɽ�ȵĵ�������һ��Ư���ĺ����������������Ĵ�����ұ��
�ʻ��̲ݣ����ҴӴ���ȥ��������ɼ����������Ǹ�������Դ��
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
	set("exits", ([
		"west" : __DIR__"dong8"+(random(4)+3),
		"east" : __DIR__"dong8"+(random(4)+1),
		"north" : __DIR__"dong8"+(random(4)+1),
		"south" : __DIR__"dong7"+(random(4)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong8"+(random(4)+3),
		"east" : __DIR__"dong8"+(random(4)+1),
	]));
         set("objects", ([
              __DIR__"npc/lev8" : 1,
              __DIR__"npc/lev7" : 1,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
