// Room: /d/cangzhou/beijie2.c

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���ݳǱ��֣���������罥����С��һ�㡣����Ҳ��ʼ�����Ķ��ˡ���
·����һ������ʩ���ķ��ӣ������ǲ��ݸ��á�
LONG );
        set("exits", ([
                "north" : __DIR__"beijie1",
        	"south" : __DIR__"beijie3",
		"west" : __DIR__"fuya",
		"east" : __DIR__"gongdi",
	]));
	set("outdoors", "����");

	setup();
}
