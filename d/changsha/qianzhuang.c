// /d/zhuojun/qianzhuang.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "Ǯׯ");
	set("long", @LONG
�����ǳ�ɳ�ǵ�һ��Ǯׯ�����Ǯׯ�Ѿ��а������ʷ�ˣ�����׿
���������������Ǯ����Ըе��ǳ��ķ��ġ�
LONG
	);
set("exits", ([
                "east"  :__DIR__"nandajie1",
	]));
	set("objects",([
	  __DIR__"npc/qian":1,
	  ]));
       setup();
	replace_program(ROOM);
}	
