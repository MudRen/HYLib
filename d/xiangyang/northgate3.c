// Room: /d/xiangyang/southgate1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "����������");
	set("long", 
"�����������ǵı����ţ�ֻ�������Ϸ�����������
"HIB"

                      ����������
\n"NOR
"�������ɹ��Ŵ��ַ������ǣ�����������൱���ܣ�һЩ�ٱ�
�������̲�Ҫ�������ǵ��ˡ������Ǻܴ�Ĳݵء�\n"
 );
        set("outdoors", "xiangyang");

	set("exits", ([
		"west"  :"d/xiangyang/caodi3",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 3,
	]));
	setup();
	replace_program(ROOM);
}

