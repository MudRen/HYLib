// Room: /u/dubei/u/gumu/jqg/jt
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "��̶");
	set("long", @LONG
ֻ��������ϡ����ϡ����ϡ����С����䣬�����������У�ʽ
�����࣬����ʮ֮�˾Ŷ��ǹŽ��������߳ߣ���̽����磬�е�
���ڰ߲����еĺ�����ˡ�
LONG
	);

	set("exits", ([
 
                "north" : __DIR__"sqx",
	]));
 	setup();
	replace_program(ROOM); 
}

