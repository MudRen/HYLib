// /d/zhuojun/guangchang.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "��ɳ�㳡");
        set("long", @LONG
������λ�ڳ�ɳ�ǵ����ĵ����Ĺ㳡��һ����¥���������Ĺ㳡��
���룬������ǳ�ɳ�Ǻ�ɫ��������������֬��ϣ��������������
��ͨ��ɳ�ĸ������š�
LONG
	);
set("outdoors", "changsha");
set("exits", ([
		"north" :__DIR__"beidajie2",
                "south"  :__DIR__"nandajie2",
                "west"  :__DIR__"yanzixiang",
                 "east"  :__DIR__"dongdajie2",
	]));
	set("objects",([
	  __DIR__"npc/bing":1,
	  "/clone/npc/man":2,	
"/clone/misc/dache":1,
	  ]));
       setup();
	replace_program(ROOM);
}	
