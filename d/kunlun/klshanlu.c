// klshanlu.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "����ɽ´");
		  set("long",@long
��������ɽ��ѩɽ���࣬���Ӵ�����Զ�����أ���������Ʋʼ����ɫ��
����ÿ�괺���Ժ󣬱�ѩ�ڻ������һ�ɹ��峺Ϫ�������볤�����ƺӡ�
long);
		 set("exits",([
            "northup" : __DIR__"shanmen",
				"east" : __DIR__"shankou",
				"west" : "/d/fairyland/shanlu1",
]));
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
