//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��·��ɽ�������Ѽ������������ɽ��ͨ����ĵ��ݵش�����
��ɽ�ƽ�Ϊƽ����ɽ����ż�����̣�͸�����ֵķ�϶������ȥ����
Լ�ɼ�һ����ˮ��Щ�����̡�
LONG
        );

	set("exits", ([
		"westdown" : __DIR__"minov17",
		"eastdown" : __DIR__"minov21",
		]));

	set("outdoors","dali");
	set("cost", 4);
	setup();
}
