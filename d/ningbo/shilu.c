// Room: /u/beyond/ningbo/shilu.c ʯ·
// Beyond make 1997.6.8
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "ʯ·");
	set("long", @LONG
������һ����ʯ·�ϣ�������һƬï�ܵ������֣�ͷ��Сϲȵ��������
�Ľи���ͣ��һ��΢�紵����ʹ��о���һ�ɳ�ʪ�Ŀ������������Ҳ����
��Ϊ�������Ǹ��ۿڰɡ���Զ����ɽ�Ͼ��Ƕ��������ı������ˡ����ϱ���
�������
LONG
	);
   set("outdoors","ningbo");
	set("exits", ([
	"east" : __DIR__"tianyige",
"northwest" : __DIR__"qsddao",
        "south" : __DIR__"tianfengta",
        "southup" : __DIR__"baoguosi",
	]));
	setup();
        replace_program(ROOM);
}
