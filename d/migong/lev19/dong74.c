#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", WHT"�ɴ�֮�ż�"NOR);
	set("long", CYN @LONG
   ��˵����һ�ҽ�������ŵķɴ�����ħ�������������˵��ǰ��
һ��������յĳ��У���֪ʲôʱ������������˵�ڵĵط���ϡ��
���ĵ��Ǽװ�����ӣ������������أ����е�ɱ��Խ��ԽŨ�ˡ�
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong7"+(random(4)+2),
		"east" : __DIR__"dong7"+(random(4)+3),
		"south" : __DIR__"dong7"+(random(4)+2),
		"north" : __DIR__"dong7"+(random(4)+2),
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong75",
		"north" : __DIR__"dong74",
	]));
         set("objects", ([
              __DIR__"npc/lev5" : 6,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
