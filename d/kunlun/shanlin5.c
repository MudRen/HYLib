// shanlin5.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "��ɼ��");
		  set("long",@long
����һƬ�����޾��Ĵ��̵����֣����ܵ���ɼ�����ľ�ɡ�����ص�����
֦Ѿ��ֻ©�°߰ߵ��ϸ�����Ӱ������ʮ���ľ�������ȸҲ�ٷ�����ֻż��
������Զ���ļ���������
long);
		 set("exits",([
				"south" : __DIR__"conglinggu",
				"west" : __DIR__"shanlin6",
				"north" : __DIR__"shanlin"+(random(5)+1),
				"east" : __DIR__"shanlin"+ (random(5)+1),
]));

set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
