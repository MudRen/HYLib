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
		"eastdown" : __DIR__"dong98",
            	"westup" : __DIR__"dong9"+(random(4)+3),
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong9"+(random(3)+6),
            	"east" : __DIR__"dong9"+(random(4)+5),
		"south" : __DIR__"dong9"+(random(4)+5),
		"north" : __DIR__"dong9"+(random(4)+5),
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
