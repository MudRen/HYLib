// /d/zhuojun/chaguan.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "����ͤ");
	set("long", @LONG
�����ݷǳ��󣬲���е����ζ�����̴ľ���ɣ���������붼��
������Ĵ�������һ��趼���ȣ�ֻ��������������ѣ����ȫ�ǵ���
�����⵽�˺Ȳ����졣
LONG
	);
set("exits", ([
                "north"  :__DIR__"xidajie2",
	]));
	set("resource/water",1);
	set("objects",([
	__DIR__"npc/xiaoer2":1,
	]));
       setup();
	replace_program(ROOM);
}	
