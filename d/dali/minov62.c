//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�˴���˵������ʱ�����������ߴ����ϻ�֮�����ϻ�Ի����
��������Ҳ����Ƚ������˲�����Ҳ�������ʴ˵���������һ����ͨ
�ϱ��Ĵ�·����ȥʮ����ϲ�ݳǣ�����Լ��ʮ��ɴ����ǡ�
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov63",
		"south" : __DIR__"minov61",
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
