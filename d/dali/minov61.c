//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "ϲ�ݳ�");
	set("long", @LONG
ϲ���������ǣ��Ǵ����ϲ���ǣ����ƴ��Ѽ����٣��ؾ��˻�
���ڣ���ó�����٣��д��������������˽��ף��ɹ�������Ľ�����
˿֯Ʒ��������Ƥë�ȣ�������������ӡ�ȵĿ�����࣬ǰ����˿��
����˹������Զ��������
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov62",
		"south" : __DIR__"minov64",
		"east" : __DIR__"xizhou",
		"southwest" : __DIR__"minov66",
		]));

	set("objects", ([
		__DIR__"npc/indiman" : 1,
	]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
