//Cracked by Kafei
// ������
// Dong  11/03/1996.
// modified by aln 2 / 98

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{       set("short", "������");
        set("long", @LONG
���������������£���ǰ���峺��СϪ��Ϫ�Խ�����Ȫͤ�ͺ���
ͤ���������Ŀ�ɼ����������������������ϱ�ص������
LONG);

        set("exits", ([ /* sizeof() == 2 */ 
             "enter" : __DIR__"lingyin1", 
	       "south" : __DIR__"lingyinsi",
        ]));

	set("objects", ([
               __DIR__"npc/seng" : 1,
        ]));

	set("cost", 1);

        setup();
        replace_program(ROOM);
}
