#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "�㳡");
		  set("long",@long
������һ��ƽƽ�����Ĵ�㳡���㳡���������ɵĵ�����ϰ�䣬ǰ�治Զ����
���޴��ʯ���磬������������ɵ�ǰ���ˣ�����Ͷ�����Ȼ�ǹ㳡��
long);
		 set("exits",([
"north" : __DIR__"shanlu04",
"south" : __DIR__"pingfeng",
"west" : __DIR__"guangchangw",
"east" : __DIR__"guangchange",
]));
set("objects",([
        "/kungfu/class/kunlun/gaozecheng" :  1,
		__DIR__"npc/kl-dizi2" :  2,
		"/d/biwu/champion_kl":1,
           "quest/menpai/kunlun/shi" : 1,
]));
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
