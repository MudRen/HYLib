//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
��վ���������ı��������߲�Զ����ϲ�ݳǡ��˺����󣬵���ˮ
�峺�������У�����̨�Ĵ��������ں��ϲ��㡣��֮�ϺͶ���
��ɽ�϶���̨�Ĵ����е�·�ƺ�������ͨ���ϱߡ�
LONG
);

	set("exits", ([
		"north" : __DIR__"minov61",
		"east"  : __DIR__"minov76",
		"southeast" : __DIR__"minov65",
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
