// Room: /d/cangzhou/xijie1.c

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���ݳ����֣�����һ����������ʯ��ֵ���������ͷ���졣�����Ǳ���
Ψһ�ĵ��̡������ǲ�����վ��
LONG );
        set("exits", ([
                "north" : __DIR__"yizhan",
        	"south" : __DIR__"dangpu",
		"west" : __DIR__"ximen",
		"northeast" : __DIR__"beijie3",
		"southeast" : __DIR__"nanjie1",
	]));
	set("outdoors", "����");

	setup();
}