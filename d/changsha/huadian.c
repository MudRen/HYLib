// /d/zhuojun/huadian.c
// Room in �ÿ�
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "����ͤ");
	set("long", @LONG
�����߽����꣬�·��߽��˻��ĺ��������˵Ļ���ʹ��һ�󣬻�
������ڷ��Ÿ�ʽ�����Ļ��ݣ���������ͨ�ġ�ɽ�軨�������¼�������
Ҳ��������������硰���ɹ�����,�����ơ���������ݡ�
LONG
	);
set("exits", ([
		"east" :__DIR__"nandajie2",
	]));
       setup();
	replace_program(ROOM);
}	
