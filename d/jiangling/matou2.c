//Edited by fandog, 02/15/2000

#include <ansi.h>
inherit ROOM;

void create()
{

	set("short", "�����ͷ");
	set("long", @LONG
���Ҳ���人��һ�����򡣶ɴ�������ͣ�£�����ʯ������Ľ�����
��Ȼ�ܸо����󽭵ı������Դ���ζ�Ľ�����Ϣ���Ʈ�����ϱ߿ɼ���
��һ������ʯ�ڡ�
LONG );

	set("exits", ([
		"south" : __DIR__"chibi",
		"north" : __DIR__"matou1",
	]));

	set("outdoors", "jiangling");
	set("no_clean_up", 0);
	set("coor/x", -1400);
	set("coor/y", -2200);
	set("coor/z", 0);


	setup();
}