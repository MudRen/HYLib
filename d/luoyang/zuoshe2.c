//  Room:  /d/luoyang/zuoshe2.c
#include <ansi.h>
inherit  ROOM;

void  create  ()
{
	set("short",  "�ڽ�");
	set("long",  @LONG
�߽��ڽ��������μ�齣���һ�������ơ����ϰ���һ�����٣���
�����һ������Ů�������Ღ���������������ְ���������
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"       :  __DIR__"zuoshe1",
	]));
	set("objects",  ([
		__DIR__"npc/renyy" : 1,
	]));
	set("coor/x", -382);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}