// Room: /d/cangzhou/beijie3.c

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���ݳǱ��֣���������缸���Ѿ���ȫͣ�¡����Ͼ͵��������ֵĲ���
���ջ�ˡ���������������ÿ�춼������ˣ��ֵ�����Ǹ���ӡ�
LONG );
        set("exits", ([
                "north" : __DIR__"beijie2",
        	"south" : __DIR__"kezhan",
		"west" : __DIR__"mingju",
		"east" : __DIR__"feiyuan",
		"southwest" : __DIR__"xijie1",
		"southeast" : __DIR__"dongjie1",
	]));
	set("objects", ([
        ]));
	set("outdoors", "����");
	setup();
}