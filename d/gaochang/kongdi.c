// Room: /d/gaochang/fzlou.c

inherit ROOM;




void create()
{
	set("short", "�յ�");
	set("long", @LONG
ͻȻ֮�䣬��ǰ��Ȼ���ʣ�����һ��Ƭ�յأ���ͷ
�������������ţ�Ƕ�ڴ�ɽ���С�
LONG
	);

	set("exits", ([
		"north" : __DIR__"shulin14",
		"east" : __DIR__"shijie1",
	]));

	setup();
	replace_program(ROOM);
}



