// Room: /d/xiangyang/southgate1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "��ȸ������");
	set("long", 
"�����������ǵ��ϳ��ŵ��ڳ��ţ�ֻ�������Ϸ���������
�֡�"HIR"

                      ��ȸ������
\n"NOR
"�������ɹ��Ŵ��ַ������ǣ�����������൱���ܣ�һЩ�ٱ�
�������̲�Ҫ�������ǵ��ˡ��������ϳ�ͷ��ʯ�ף��򱱽���
������\n"
 );
        set("outdoors", "xiangyang");

	set("exits", ([
		"west"  :"quest/menpaijob/gaibang/guanka",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 3,
	]));
	setup();
	replace_program(ROOM);
}

