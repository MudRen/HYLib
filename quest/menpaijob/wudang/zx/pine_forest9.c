//Cracked by Roath
// pine_forest9.c ����
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
	
	switch(random(11)){
	case 1:
		set("objects", ([
			__DIR__"obj/pine" : 2,
			__DIR__"obj/snake" : 1]));
		break;
	case 2:
		set("objects", ([ __DIR__"obj/snake" : 1]));
		break;
	case 9:
		set("objects", ([
			__DIR__"obj/pine" : 2,
			__DIR__"obj/snake" : 1]));
		break;
	case 12:
		set("objects", ([ __DIR__"obj/snake" : 2]));
		break;
	case 10:
		set("objects", ([ __DIR__"obj/pine" : 2]));
		break;
	}	          	
	
	set("exits", ([
		"south" : __DIR__"pine_forest"+(random(11)),
		"north" : __DIR__"pine_forest10",
		"east" : __DIR__"pine_forest"+(random(9)),
		"west" : __DIR__"pine_forest"+(random(9)),
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

