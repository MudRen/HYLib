// Room: /d/shaolin/shulin1.c
// by pishou

inherit ROOM;




void create()
{
    set("short", "������");
	set("long", @LONG
������һƬ�������п��ٵ�һ�յء���������ϡ�٣������Ե�ʮ��
�ľ����ߴ��������ס�˴��۵����⣬Ϊ�����ṩ��һ����Ȼ����Ϣ��
����
LONG
	);

	set("exits", ([
        "north" :__DIR__"shulin",
        "east" :"/d/jingzhou/qingshan1",

	]));

 	set("outdoors", "yuyang");
	setup();
	replace_program(ROOM);
}



