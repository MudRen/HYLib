
inherit ROOM;

void create()
{
	set("short", "���ݳ�");
	set("long", @LONG
���ݳ��Ǳ����Ĵ�ǣ������Ǳ��ұ���֮�ء��������ڴ�פ
���ر����̲��������������ˣ����������𸽽�ɽ�ϵĲݿܡ���
��һ�Ӷӹٱ�����ȥȥ��һ��ɭ������������������������֮
һ����ɽ�������Ҫ���ǣ�����enter�������ݳ��ڡ�
LONG
	);

	set("exits", ([
		"south" : __DIR__"yidao3",
		"west"  : "/d/songshan/taishique",
		"north" : "/d/city2/road10",
		"enter" : "/d/ruzhou/ruzhou",
	]));

        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 3,
        ]));

	set("outdoors", "ruzhou");
	setup();
	replace_program(ROOM);
}



