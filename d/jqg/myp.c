// Room: /u/dubei/u/gumu/jqg/myp
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "÷����");
	set("long", @LONG
����ٲ���Σ���ͱڶ�������ֱ�£����ٿڲ�Զ��һ��ͻ��
ʯ����ʯ�ɽ�������ëëϸ�꣬�����塢����÷�꣬����÷���١�
LONG
	);

	set("exits", ([
                "west" : __DIR__"glt", 
	]));

   set("outdoors", "����");
	setup();
	replace_program(ROOM);
}

