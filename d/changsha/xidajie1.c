// /d/zhuojun/xidajie1.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
��������ʯ�̳ɵ���·����������������ô��������ǳ�ɳ��
�����ţ�����ȥ������������ˮ�����ò����֡������Ǿ��峯��һ��
��վ��������һ�Ҿ�¥��
LONG
	);
set("outdoors", "changsha");
set("exits", ([
		"north" :__DIR__"yizhan",
                "south"  :__DIR__"tianwaitian",
                "west"  :__DIR__"ximen",
                 "east"  :__DIR__"xidajie2",
	]));
       setup();
	replace_program(ROOM);
}	
