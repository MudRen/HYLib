
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"�����ɳĮ"NOR);
	set("long", YEL @LONG
  ���ڻ�Ԫ�ص�Ӱ�죬�⸽��ȫ��ɰĮ������һƬһ��
�޼ʵĴ�ɳĮ����һ��������ʧ�˷��򡣿���Ҫ�߳���
��ɳĮ�������¡�
LONG NOR);
set("magicroom",1);
set("magicset",1);

	set("exits", ([
		"east" : __DIR__"dong33",
		"west" : __DIR__"dong35",
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

