// wdroad2.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ�������Լ�ɼ������ݳǵĳ�ǽ���˴�������
��ȥ�����Կ���һ������
LONG );
        set("outdoors", "wudang");
	set("exits", ([
		"north" : __DIR__"wdroad1",
		"southeast" : "/d/yixing/yixing",
                "southwest" : "/d/jingzhou/wdroad5",
	"south" : __DIR__"wdroad3",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

