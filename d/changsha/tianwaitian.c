// /d/zhuojun/tianwaitian.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "������");
	set("long", @LONG
�������¥�ǳ�ɳ������һ�Ҿ�¥���������Ƶ�״Ԫ����Կ���
һ����ɽ�ͺ��ʣ��ϱ����Ӧ�о��С��۸񹫵����������ϡ�
LONG
	);
set("exits", ([
                "north"  :__DIR__"xidajie1",
	]));
	set("objects",([
	  __DIR__"npc/xiaoer3":1,
	  ]));
       setup();
	replace_program(ROOM);
}	
