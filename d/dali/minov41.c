//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "�͵ĵ�");
	set("long", @LONG
������Ǵ�������Ҫ��͵ĵ飬�����ĵ���Ҫ�θ���������Ĳ�
��ֲ��ڸ��������ڶ���ˮ�ȵ����У��͵ĵ����ܶ�ũ��Դ�Ϊ��
�ģ���·��ͨ�˴����Ӹ����Ĳ��䡣
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov42",
		"south" : __DIR__"minov57",
		"eastup" : __DIR__"minov50",
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
