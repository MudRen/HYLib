//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "����¥");
	set("long", @LONG
����һ����ͨ��ʽ��̨����¥������³�������ģ�������������
¥��ռ�ع��ö࣬Ҳ�ر�ߴ��������㣬�������Ჿ�ļ�����ݡ�
�˴��²�Ҳ�������󣬴�ɨ�øɸɾ�������������ֱͨ�ϲ�
LONG
        );

	set("exits", ([
		"south" : __DIR__"minov76",
		"up" : __DIR__"minov29",
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
