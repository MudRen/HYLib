#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "����");
		  set("long",@long
����һ�����ȣ�������ʥ�úͻ�԰�����Ͽ������ִ��Ľ�����ʿ�߹���
�������⣬��һƬ��ɫ�����֣��ľ����£�ֻ�������ϴ�������������
long);
		 set("exits",([
"southup" : __DIR__"sanshengtang",
"north" : __DIR__"huayuan1",
]));
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
