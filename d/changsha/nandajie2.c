// /d/zhuojun/beidajie2.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "�ϴ��");
	set("long", @LONG
��������ʯ�̳ɵĵ�·�ϣ���·����������������ô��������
��ɳ������ж�����������������ˮ��������ʾ��һƬ��������������
��������Ʈ��һ�ɻ��㣬ԭ������һ�����꣬������һ�Ҽ۸���˵�
С�Եꡣ
LONG
	);
set("outdoors", "changsha");
set("exits", ([
		"north" :__DIR__"guangchang",
                "south"  :__DIR__"nandajie1",
                "west"  :__DIR__"huadian",
                 "east"  :__DIR__"xiaochidian",
	]));
set("objects",([
 __DIR__"npc/liumang":1,
 ]));
       setup();
	replace_program(ROOM);
}	
