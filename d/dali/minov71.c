//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "���ڳ�");
	set("long", @LONG
�����ѵ������Ͻ��ˣ����ڳ�����Ԫ�������ٽ�·��������ϲ�
�����ǧ�����������ϡ�٣��˵�����������Ĳ�Զ��ȴҲ����
������Ҫ�ؿ�֮һ�ˣ��Ǻ��Ϸ��ٹ�ͨ�̵Ŀڰ����ɴ˱�ȥ��ʮ����
����ϲ�ݳǣ��ϱ���Ԫ���в���̨�Ĵ�ׯ������ٸ��ڴ���Щפ����
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov65",
		]));

	set("objects", ([
		__DIR__"npc/dalishibing" : 2,
	]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
