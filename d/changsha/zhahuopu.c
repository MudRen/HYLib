// /d/zhuojun/zhahuopu.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "�ӻ���");
	set("long", @LONG
������ӻ�����Ȼ���Ǻܴ󣬵��ǻ���ȴ����ȫ����˵������ϰ�
����ͨ�죬ʲô���Ķ��������򵽣��������õ�ʲô����ϡ��Ķ�����
���ܷ����������ˡ�
LONG
	);
set("exits", ([
                "north"  :__DIR__"dongdajie1",
	]));
	set("objects",([
	  __DIR__"npc/li":1,
	  ]));
       setup();
	replace_program(ROOM);
}	
