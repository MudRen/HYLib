// Room: /d/tanggu/kedian2.c

inherit ROOM;

void create()
{
	set("short", "�͵��¥");
	set("long", @LONG
�͵�Ķ�¥���м��䷿������ţ����������Ѿ�ס�����ˡ�С��һ������
������æӭ��������������˿��ݡ�
LONG );
	set("exits", ([
		"down" : __DIR__"kedian",
		"enter" : __DIR__"sleeproom",
	]));
	setup();
}
