//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "����С·");
	set("long", @LONG
һ��С·�����ֶ��������Ϸ��������һ��Ƭ̨���˾۾ӵĴ�
�򣬶�����ңң����ϲ�ݳǵĳ�ǽ����·��������ï�ܣ�ʱ��̨����
��������
LONG
);

	set("exits", ([
		"northeast" : __DIR__"minov61",
		"southwest" : __DIR__"minov67",
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
