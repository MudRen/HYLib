// Room: /u/beyond/ningbo/dongqianhu.c ��ǰ��
// Beyond make 1997.6.8
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "��Ǯ��");
	set("long", @LONG
������һ����ʯ·�ϣ�������һƬï�ܵ������֣�ͷ��Сϲȵ��������
�Ľи���ͣ��һ��΢�紵����ʹ��о���һ�ɳ�ʪ�Ŀ��������������ʱ��
���ߵ��˶�Ǯ���ϣ�ֻ��ˮ�����������ɽɫ���죬����ɽɫ�������ˡ���
��С�۷��ۺ��ϣ�ʹ����ø���ʫ�黭�⡣
LONG
	);
        set("outdoors", "ningbo");
	set("exits",([
	"west" : __DIR__"ningbocheng",
         "north" : __DIR__"xikou",
        "southwest" : __DIR__"kedian",
        "south" : __DIR__"xuedoushan",
	]));
	setup();
        replace_program(ROOM);
}
