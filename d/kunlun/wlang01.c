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
"east" : __DIR__"qianting",
"west" : __DIR__"keting2",
]));
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
