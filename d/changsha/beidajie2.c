// /d/zhuojun/beidajie3.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
�������߾���λ�������ĵ����Ĺ㳡�ˣ�����ȥ���Կ�����ɳ��
�����š������ǳ�ɳ���һ�Ҷĳ�������һ�����ֱͨ��ɳ�����š�
LONG
	);
set("outdoors", "changsha");
set("exits", ([
                "north" :__DIR__"beidajie1",
                "south"  :__DIR__"guangchang",
                "west"  :__DIR__"xidajie2",
                 "east"  :__DIR__"jinyintang",
	]));
	set("objects",([
	__DIR__"npc/qigai":1,
	]));
       setup();
	replace_program(ROOM);
}	
