#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "�㳡��");
		  set("long",@long
������һ��ƽƽ�����Ĵ�㳡���㳡���������ɵĵ�����ϰ�䣬������
��Ȼ�ǹ㳡�������ȥ���������ˣ���������ɽ��·��
long);
		 set("exits",([
"northwest" : __DIR__"shanlu04",
"west" : __DIR__"guangchang",

]));
set("objects",([
        "/kungfu/class/kunlun/yulingzi" :  1,
		__DIR__"npc/kl-dizi3" :  2,
]));
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}
