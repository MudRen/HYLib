// Room: /u/dubei/u/gumu/jqg/qlf
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ɽ�������̧ͷ���죬ֻ��һ�ߡ�ɽ��ˮ�̣���
ɫ�������ģ�ֻ�����¼�����Ϣ������͸�����գ�Ϫ���оſ�
��ʯӭ����������������һ�㣬��ס��ȥ·��
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"glt",
                "southdown" : "/d/sdxl/conglin1",
	]));

           set("outdoors", "xiangyang");
	setup();
	replace_program(ROOM);
}

