// Room: /u/dubei/u/gumu/jqg/qzy
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��֥Ժ");
	set("long", @LONG
����һ�䲻���С�ݣ����ϣ���������ҩ�ޣ�����һ�Դ�
�Ĺ�������Ǭ��ҩ�����ײ���������¯��ͭ���߰ߣ������Զ��
LONG
	);

	set("exits", ([
 
                "north" : __DIR__"st",
	]));
//	set("objects", ([
//		__DIR__"npc/ldr" : 1,
//	 ]));

   
	setup();
	replace_program(ROOM); 
}

