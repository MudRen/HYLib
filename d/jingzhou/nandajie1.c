// Room: nandajie1.c
// congw 1998/08/29 

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�ϴ�����ǳ���ķ����ضΣ�������һ�����ֵĹ㳡��������һ�Ҵ�����. ������
���ݵ���ݣ�������·�˶�붼������Ъ�š�
LONG
	);
        set("outdoors", "city");

	set("exits", ([
                "east" : __DIR__"datiepu",
		"south" : __DIR__"nandajie2",
                "west" : __DIR__"chaliao",
		"north" : __DIR__"guangchang",
	]));

	setup();
	replace_program(ROOM);
}

