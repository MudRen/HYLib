//Cracked by Roath
// pine_forest1.c ����
// by Marz@XKX 11/11/96

inherit ROOM;


void create()
{
	set("short", "����");
	set("long", @LONG
	������������������գ�������ֻ�о�������ǰ�󵽴�
������Ӱ��������һ�����������ã�������ӫӫ���׹⡣�㾪��֮
�䣬һ�Ų��ڸ����������ϣ�
LONG
	);
	
	if (random(2)) 
		set("objects", ([ __DIR__"obj/pine" : 3]));
	else 	                        	
		set("objects", ([ __DIR__"obj/songguo" : 1]));

	
	set("exits", ([
		"south" : __DIR__"pine_forest"+(2+random(4)),
	]));
	
	set("cost", 3);
	setup();
}


void init()
{
	object me = this_player();
	
	if ( !objectp(me->query_temp("armor/boots")) )
		me->receive_damage("qi", 10);  

}

