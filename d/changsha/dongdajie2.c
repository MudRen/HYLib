// /d/zhuojun/dongdajie3.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
��������ʯ�̳ɵ���·����������������ô�������߾��ǳ�ɳ
�ǵ����Ĺ㳡�ˣ�������һ��Ƥ���У�������һ�ҽ�¥��
LONG
	);
set("outdoors", "changsha");
set("exits", ([
		"north" :__DIR__"pihuohang",
                "south"  :__DIR__"jinlou",
                "east"  :__DIR__"dongdajie1",
                 "west"  :__DIR__"guangchang",
	]));
	set("objects",([
	__DIR__"npc/shusheng":1,
	]));
       setup();
	replace_program(ROOM);
}	
