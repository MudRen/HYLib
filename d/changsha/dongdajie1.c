// /d/suiye/dongdajie1.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
��������ʯ�̳ɵ���·����������������ô��������ǳ�ɳ��
�������ˣ�������ȥ�����Կ���λ�����Ĺ㳡����¥��������һ������
�꣬������������������һ���ӻ��ꡣ
LONG
	);
set("outdoors", "changsha");
set("exits", ([
		"north" :__DIR__"yueqidian",
                "south"  :__DIR__"zhahuopu",
                "west"  :__DIR__"dongdajie2",
                 "east"  :__DIR__"dongmen",
	]));
       setup();
	replace_program(ROOM);
}	
