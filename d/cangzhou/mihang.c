// Room: /d/cangzhou/mihang.c

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�������У���С��������һ�أ����Ǹ����ס��ƹ������������һֻ��
���ϣ����æ���к��ſ��ˡ�
LONG );
        set("exits", ([
        	"east" : __DIR__"beijie1",
		"south" : __DIR__"changku",
	]));
	
	set("objects", ([
                __DIR__"npc/gongtou.c" : 1,
        ]));
	setup();
}
