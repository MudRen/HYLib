// /d/zhuojun/pihuohang.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "Ƥ����");
	set("long", @LONG
����һ�Ҿ�Ӫ����Ƥ�������У������и���������Ƥ���л�Ƥ����
Ƥ��ֻҪ����˵�����Ķ���Ƥë�����չ���
LONG
	);
set("exits", ([
                "south"  :__DIR__"dongdajie2",
	]));
       setup();
	replace_program(ROOM);
}	
