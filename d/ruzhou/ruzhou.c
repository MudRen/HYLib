
inherit ROOM;

void create()
{
	set("short", "���ݳ�");
	set("long", @LONG
���ݳ��Ǳ����Ĵ�ǣ������Ǳ��ұ���֮�ء��������ڴ�פ����
�����̲��������������ˣ����������𸽽�ɽ�ϵĲݿܡ�����������
���Ͼ��ǵıؾ�֮�����ٱ��̲�Ҳʮ���ϸ񡣴��������������ţ���
�Ե�����֮�е���ɽ�ˡ�
LONG
	);

	set("exits", ([
		"south" : __DIR__"xiaozheng",
		"west" : __DIR__"wangxi-lu",
		"east" : __DIR__"hong-damen",
		//"northwest" : "/d/kaifeng/east1",
		"north" : "/d/cangzhou/sroad4",
		//"out" : "/d/shaolin/ruzhou",
	]));

        set("objects", ([
                "/d/city/npc/xunbu" : 1,
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 3,
        ]));

	set("outdoors", "ruzhou");
	setup();
	replace_program(ROOM);
}



