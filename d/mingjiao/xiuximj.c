// xiuxis.c
// shilling 97.2

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
����һ���ڹ������ϵ�С�ݣ������м���ż��Ŵ󴲣��������ӣ�������
����Ϣ�ĵط������й�����ͣ�ʹ�˸���˯�⡣
LONG );
        set("exits", ([ 
		"south" : __DIR__"square", 
	]));
        set("no_fight",1);
        set("no_steal",1);
        set("sleep_room",1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
