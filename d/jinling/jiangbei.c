
inherit ROOM;

void create()
{

	set("short","��������");
	set("long", @LONG
�����ǳ����ߣ�һ��ʯ����ͨ�˰��ߺͶɿڣ����ڲ���ĳ��������Ե���˵���
С�����Ķ�����Ƿ����Ľ�����򣬸�����ũ�򾭳��������ֵ��߲��˵�����������
���м�ֻС�ۣ�ֻҪ�㺰(yell)һ���������������Ǿͻ�Ѵ�ʻ����
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
//  "north" : "/u/gaibang/road2",
]));
	 set("outdoors", "jinling");

set("no_clean_up", 0);
	set("outdoors", "gaibang");

	setup();
//	replace_program(ROOM);
}

