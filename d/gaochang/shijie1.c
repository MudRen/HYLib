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
		"west" : __DIR__"kongdi",
		"northup" : __DIR__"shijie2",
	]));

	set("outdoors", "gaochang");
	setup();
	replace_program(ROOM);
}



