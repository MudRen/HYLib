//Cracked by Roath
// pine_forest7.c ����
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
		set("objects", ([
			__DIR__"obj/pine" : 1,
			__DIR__"obj/snake" : 1]));

	switch(random(10)){
	case 8:
		set("objects", ([ __DIR__"obj/songguo" : 2]));
		break;
	case 7:
		set("objects", ([ __DIR__"obj/snake" : 1]));
		break;
	case 3:
		set("objects", ([
			__DIR__"obj/pine" : 2,
			__DIR__"obj/snake" : 1]));
		break;
	case 0:
		set("objects", ([ __DIR__"obj/snake" : 2]));
		break;
	case 4:
		set("objects", ([ __DIR__"obj/pine" : 2]));
		break;
	}	          	
	
	set("exits", ([
		"south" : __DIR__"pine_forest"+(7+random(3)),
		"north" : __DIR__"pine_forest"+(5+random(5)),
		"east" : __DIR__"pine_forest"+(random(10)),
		"west" : __DIR__"pine_forest"+(random(10)),
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

