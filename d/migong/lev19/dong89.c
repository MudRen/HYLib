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
		"south" : __DIR__"dong90",
		"north" : __DIR__"dong8"+(random(4)+6),
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong8"+(random(4)+6),
		"north" : __DIR__"dong90",
	]));
        set("objects", ([
              __DIR__"npc/lev6" : 3,
              __DIR__"npc/lev7" : 6,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
