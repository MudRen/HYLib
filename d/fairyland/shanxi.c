// Room: /u/qingyun/jyzj/shanxi.c
// Written by qingyun
// Updated by jpei

inherit ROOM;

void create()
{
	set("short", "ɽϪ��");
	set("long", @LONG
������һ��СϪ������ɽ�����ѩ�������������£����ֱ�ѩ�ڻ���ˮ��
�����СϪ��Ϫˮ���¶�������֪������η�������������һ������֡�
LONG	);
	set("exits", ([
		"westup" : __DIR__"conglin1",
		"eastup" : __DIR__"hongmeizhuang",
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
