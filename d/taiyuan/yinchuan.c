// /d/taiyuan/road7.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������ǰ���Ĺ��Ķ��������������Ҫ�ǻ����˵ľ۾ӵأ�������
���������������������Ի�����к���΢Ц���������г�����������顣
���ߵĻ�����Ůͨ���������ϵ���ɴ����Ĵ��۾���С�ĵ�����������
������������ˡ�
LONG );
	set("exits", ([
		"west"  : __DIR__"road9b",
 		"southeast"  : __DIR__"road8c",
  	]));
	
 	set("outdoors", "taiyuan");
	setup();
	replace_program(ROOM);
}



