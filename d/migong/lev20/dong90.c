#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"���ҵ���Ĺ"NOR);
	set("long", HIM @LONG
���Ǵ�˵�й���ĵ���Ĺ��ͨ·������Ʈ����һ�ſ�����
�ĺ�ˮ�������ܵ�ǽ�ں��컨���������������ıڻ��;���
��ʯ������ɢ�������صĹ�â��
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"westdown" : __DIR__"dong91",
            	"eastup" : __DIR__"dong8"+(random(4)+4),
		"southdown" : __DIR__"dong8"+(random(4)+4),
		"northup" : __DIR__"dong8"+(random(4)+4),
	]));
if (random(3)==0)
	set("exits", ([
		"southdown" : __DIR__"dong7"+(random(3)+1),
		"northup" : __DIR__"dong91",
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong8"+(random(4)+6),
		"east" : __DIR__"dong91",
	]));
        set("objects", ([
              __DIR__"npc/lev5" : 3,
              __DIR__"npc/lev4" : 3,
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
