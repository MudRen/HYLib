// /d/zhuojun/nandajie3.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "�ϴ��");
         set("long", @LONG
��ʯ�̳ɵ���·����������������ô��������ǳ����ĵĹ㳡
�ˣ����洫��һ��һʮ����Ǯ�������洫��һ��ҩ�㡣
LONG
	);
set("outdoors", "changsha");
set("exits", ([
		"north" :__DIR__"nandajie2",
                "south"  :__DIR__"nanmen",
                "west"  :__DIR__"qianzhuang",
                 "east"  :__DIR__"yaopu",
	]));
       setup();
	replace_program(ROOM);
}	
