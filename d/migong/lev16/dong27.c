
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"��֮����"NOR);
	set("long", HIY @LONG
  ���ڻ�Ԫ�ص�Ӱ�죬�⸽��ȫ��ɰĮ��������֮����������
��ɰĮ�����ϵ�һ������!!����������������������˵������
����һƬ�������ǳ��е�����㳡��
LONG NOR);
set("magicroom",1);
set("magicset",1);
set("no_fight",1);
	set("exits", ([
                "east" : __DIR__"dong22",
                "west" : __DIR__"dong33",
		"south" : __DIR__"dong28",
                "north" : __DIR__"dong29",
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
