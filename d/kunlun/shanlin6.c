// shanlin6.c (kunlun)
// cck 6/6/97

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
				"west" : __DIR__"shanlin"+(random(5)+1),
				"east" : __DIR__"kuhanlou1",
				"north" : __DIR__"shanlin"+(random(5)+1),
				"south" : __DIR__"shanlin"+ (random(5)+1),
]));

set("outdoors", "kunlun");
replace_program(ROOM);
 
}
