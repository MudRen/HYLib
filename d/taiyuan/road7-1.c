// /d/taiyuan/road7.c
// Room in ̫ԭ
// modify by yang

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
������һ�������С���ϡ������˺��١�С������ȫ��һ������Ұ
�ݡ�������Ұ�ڲݴ��￪�ţ�������������������еĺ�ɽ�ˣ�������
��Զ�ͽ���κ����ǡ�
LONG );
	set("exits", ([
		"north"  : __DIR__"road5",
 		"south"  : __DIR__"road7-2",
		
	]));
	
 	set("outdoors", "taiyuan");
 	set("valid_startroom", 1);
	setup();
	replace_program(ROOM);
}



