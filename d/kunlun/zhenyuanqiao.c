// zhenyuanqiao.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "��Զ��");
		  set("long",@long
�����źųơ����»ƺӵ�һ�š������Ƽ�Ϊ��ΰ���������򣬶�����ԭ��
�ƺ�ˮ���ŵ���к��������¡���졣
long);

		 set("exits",([
                             "west" : __DIR__"shanlu",
            "eastdown" : "/d/mingjiao/shanjiao",
			     ]));

		 set("objects", ([
			     "/d/city/npc/wujiang" :  1,
			     "/d/city/npc/bing" :     3,
				]));

		 set("outdoors", "kunlun");
		 setup();
		 replace_program(ROOM);
}
