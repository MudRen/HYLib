// Room: /d/gaochang/shijie9.c

inherit ROOM;




void create()
{
	set("short", "ʯ��");
	set("long", @LONG
��ǰ��Ȼ����һ��Ƭ���֡����ֳ��ü��ܣ�ʯ���������˺�
�����Ƶ����롣���ڽ��£���������������һֻС����֨��
����ǰ��������ʧ���ֺ��
LONG
	);

	set("exits", ([
		"southdown" : __DIR__"shijie1",
		"northup" : __DIR__"shijie3",
	]));

	set("outdoors", "gaochang");
	setup();
	replace_program(ROOM);
}



