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
		"west" : __DIR__"dong9"+(random(4)+1),
            	"east" : __DIR__"dong9"+(random(4)+1),
		"south" : __DIR__"dong9"+(random(4)+2),
		"north" : __DIR__"dong9"+(random(4)+1),
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong9"+(random(4)+2),
		"north" : __DIR__"dong9"+(random(4)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong9"+(random(4)+2),
            	"east" : __DIR__"dong9"+(random(4)+1),
	]));
        set("objects", ([
              __DIR__"npc/lev5" : 5,
              __DIR__"npc/lev4" : 3,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
