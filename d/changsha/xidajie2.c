// /d/zhuojun/xidajie2.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "�����");
	set("long", @LONG
��������ʯ�̳ɵ���·����������������ô����������ֵ���
�Σ����洫�����ּۻ���֮��������������ϲ���ǣ�������һ�Ҳ�ݣ�
���������ĵĺõط���
LONG
	);
set("outdoors", "changsha");
set("exits", ([
		"north" :__DIR__"dangpu",
                "south"  :__DIR__"chaguan",
                "west"  :__DIR__"xidajie1",
                 "east"  :__DIR__"beidajie2",
	]));
       setup();
	replace_program(ROOM);
}	
