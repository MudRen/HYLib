inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǿ����ң�����˳��ط��ż������ţ��������ż����㣬����������
�𡣼�λ�����ɵ�������ϥ��������������ޡ�
LONG
	);
	set("exits", ([
		"east"  : __DIR__"shilu1",
	]));
/*	
set("objects", ([
		"/d/village/obj/zhujian" : 2,
	]));
*/
	set("no_fight", 1);

	setup();
	replace_program(ROOM);
}
