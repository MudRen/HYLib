// Room: /d/sandboy/daotian1.c

inherit ROOM;

void create()
{
	set("short", "��Ȫ�Ƶ���Ʒ�");
	set("long", @LONG
����һ����Ȫ�Ƶ���Ʒ������ܶ������߰�������ԭ�ϣ�����
�������ø��ֲ�����ơ�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "jiangnan");
        set("exits", ([
                "west" : __DIR__"shaocailie",
        ]));
	set("objects", ([
		__DIR__"jiu/zhaojiu" : 10,
	])); 


	setup();
	replace_program(ROOM);
}
