#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"������Թ�"NOR);
	set("long", HIM @LONG
   ��������һ���ƾɵķ��棬����ɢ�������ܵ�ʯ����ʯ�顣���д����
���ﱻ�����Ѹ������ˡ���Ƭ���������ľ���ͳ��Ÿ�����ΰ�����Ľ���
���Ǹ���Ϊ��̵ĶԱȣ����ֱ�������㻹�������߲����ҵ���·��
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong9"+(random(4)+2),
            	"east" : __DIR__"dong96",
		"south" : __DIR__"dong9"+(random(4)+2),
		"north" : __DIR__"dong9"+(random(4)+2),
	]));
if (random(2)==0)
	set("exits", ([
		"south" : __DIR__"dong9"+(random(4)+2),
		"north" : __DIR__"dong96",
	]));
         set("objects", ([
              __DIR__"npc/lev8" : 3,
              "/clone/box/gboxm" : random(2),
         ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
