// Room: /u/dubei/u/gumu/jqg/wx
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�Ϫ");
	set("long", @LONG
ͻȻһ������ӿ������ǰ�ޱ��޼ʵ�ȫ��ˮ�ɻ���ԭ������
��ǳǳ��һƬˮ�������ߣ�������ˮ�ɡ�ǰ�������һ
Ƭ��Ұ�Ļ��ԣ����ѱ����·��һ���������ζ�ڿ�������
���š�
LONG
	);

	set("exits", ([
                "east" : __DIR__"fyy",
                "enter" : __DIR__"hc1",
	]));

    set("outdoors", "����");
	setup();
	replace_program(ROOM); 
}

