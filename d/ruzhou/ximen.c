// /d/ruzhou/ximen.c ��������
inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���������ݵ������š���������ͨ������ȥ�ıؾ�Ҫ����һ����
�󰸷�������ս���������������ڴ��迨�̲飬ƽʱ���ٱ�Ҳ���ù�
�����£�������һƬ̫ƽʢ������
LONG
	);

	set("exits", ([
 		"west"  : "/d/kaifeng/torz",

             "east" : __DIR__"wangxi-lu",
	]));

        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 3,
        ]));

	set("outdoors", "ruzhou");
	setup();
	replace_program(ROOM);
}



