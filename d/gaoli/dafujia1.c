// /d/gaoli/dafujia1
// Room in ����
// rich 99/03/28
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIC"��֮��"NOR);
        set("long", @LONG
����һ�Ҹ������ڵĸ����˼ң�������˾���һ���ӣ����˲���Ǯ��
�ڸ������ڸ�����ô����լ�ӣ��ſ�����������ʯʨ�ӣ�վ�������Ҷ���
LONG
);
        set("exits", ([ 
        "south": __DIR__"baihu-1",
        "north": __DIR__"dafujia2",
	]));
set("objects",([
		"/d/gaoli/npc/jiading" : 2,
	]));
      setup();
	replace_program(ROOM);

}
