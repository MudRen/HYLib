
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", RED"���ȵ���Ԩ"NOR);
	set("long", RED @LONG
  ��������ǣ�����һƬ���Ĵ�أ����ȵĵ�����
����һ��һ��Ķ���!�޼ʵĴ�ɳĮ�������µĹ���
���Ƕ��㻢��������ʱ�����˹�����ҧ������ʺ�
��˺�����������
LONG NOR);
set("magicroom",1);
set("magicset",1);

	set("exits", ([
		"west" : __DIR__"dong5"+(random(5)+3),
		"east" : __DIR__"dong5"+(random(4)+1),
		"south" : __DIR__"dong6"+(random(4)+1),
		"north" : __DIR__"dong63",
	]));
if (random(3)==0)
	set("exits", ([
		"west" : __DIR__"dong5"+(random(4)+1),
		"east" : __DIR__"dong63",
		"south" : __DIR__"dong6"+(random(4)+1),
		"north" : __DIR__"dong6"+(random(4)+3),
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
