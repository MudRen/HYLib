#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "��");
		  set("long",@long
����һ�����ȣ�����ǰ���Ϳͷ������Ͽ������ִ��Ľ�����ʿ�߹���
�������⣬��һƬ��ɫ�����֣��ľ����£�ֻ�������ϴ�������������
long);
		 set("exits",([
"west" : __DIR__"qianting",
"east" : __DIR__"keting1",
]));
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
