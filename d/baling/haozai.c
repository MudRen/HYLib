
inherit ROOM;

void create()
{
	set("short", "��լ");
	set("long", @LONG
���߽�һ����լ�����Ǽ���ʦ�ĵ�լԺ����Ϊ����ʦ��Ϊ��������
¥��ϧǧ��һ����������һ�����ڼҡ�
LONG
	);
        set("outdoors", "baling");
     
	set("exits", ([
		"north" : __DIR__"nandajie2",
		"south":__DIR__"tingyuan",
	]));

	setup();
}

