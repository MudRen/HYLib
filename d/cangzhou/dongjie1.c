// Room: /d/cangzhou/dongjie1.c

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������ǲ��ݳǶ��֣�����һ����������ʯ��ֵ���������ͷ���졣��
��ͨ���š��ϱ����ǲ��ݵ��ϱ����ɵ��ˡ�
LONG );
        set("exits", ([
                "east" : __DIR__"dongmen",
        	"northwest" : __DIR__"beijie3",
		"southwest" : __DIR__"nanjie1",
	]));
	set("outdoors", "����");

	setup();
}