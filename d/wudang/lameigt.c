// tygate1.c ��԰���
// by Marz 
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��÷԰���");
	set("long", @LONG
������һ��ͨ�����������С���ϣ�ǰ���и������(fence)��
LONG
	);
	set("outdoors", "wudang");
	
	set("item_desc",([
		"fence"	:	"\n\t\t\t�����������ʫ��\n\n\n" 
					"\t\t�ˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡ�\n"
					"\t\t�ˡˡˡ������������������������������ˡˡ�\n"
					"\t\t�ˡˡˡ�Ӧ�������졡�ݡ�ӡ���ԡ�̦���ˡˡ�\n"
					"\t\t�ˡˡˡ������������������������������ˡˡ�\n"
					"\t\t�ˡˡˡ�С���ۡ����顡�á����������ˡˡ�\n"
					"\t\t�ˡˡˡ������������������������������ˡˡ�\n"
					"\t\t�ˡˡˡ�����ɫ������԰���ء�����ס���ˡˡ�\n"
					"\t\t�ˡˡˡ������������������������������ˡˡ�\n"
					"\t\t�ˡˡˡ�һ��֦���졡�ӡ�����ǽ�������ˡˡ�\n"
					"\t\t�ˡˡˡ������������������������������ˡˡ�\n"
					"\t\t�ˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡ�\n\n\n",
							
		]));

	set("exits", ([
		"west" : __DIR__"langmei",
		"east" : __DIR__"langmeiyuan",
	]));

 //        create_door("west", "����", "east", DOOR_CLOSED);

	set("coor/x",-80);
	set("coor/y",100);
	set("coor/z",190);
	set("coor/x",-80);
	set("coor/y",100);
	set("coor/z",190);
	set("coor/x",-80);
	set("coor/y",100);
	set("coor/z",190);
	setup();
       replace_program(ROOM);
}
