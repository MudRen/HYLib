//Cracked by Roath
// pine_forest3.c ����
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
	
	switch(random(10)){
	case 2:
		set("objects", ([ __DIR__"obj/songguo" : 2]));
		break;
	case 5:
		set("objects", ([ __DIR__"obj/snake" : 1]));
		break;
	case 7:
		set("objects", ([
			__DIR__"obj/pine" : 1,
			__DIR__"obj/snake" : 1]));
		break;
	case 6:
		set("objects", ([ __DIR__"obj/snake" : 2]));
		break;
	case 8:
		set("objects", ([ __DIR__"obj/pine" : 2]));
		break;
	}	          	
	
	set("exits", ([
		"south" : __DIR__"pine_forest"+(4+random(6)),
		"north" : __DIR__"pine_forest"+(2+random(8)),
		"west" : __DIR__"pine_forest"+(random(6)),
		"east" : __DIR__"pine_forest"+(random(3)),
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

