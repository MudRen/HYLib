//Cracked by Kafei
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "���ɴ���");
	set("long", @LONG
������ɽ�Ļ��£������˰�ʯȥ�����������޳�һ������״��
ƽ̨����ӷֱ��ڸ���ƽ̨�ϣ��������ӣ�������ʯ��Χǽ������
��·Ҳ��ʯͷ�̳ɡ�
LONG
        );

	set("exits", ([
		"north" : __DIR__"minov85",
		"south" : __DIR__"minov86",
		"west" : __DIR__"minov81",
		"east" : __DIR__"minov87",
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
