// Room: /d/cangzhou/nanjie1.c

inherit ROOM;
void create()
{
        set("short", "�Ͻ�");
        set("long", @LONG
���ݳ��Ͻ֣�����һ����������ʯ��ֵ������ϱ���ͷ���졣����������
ʮ�����֡�������һ�һ��꣬������һ��Ϸ԰�ӡ�
LONG );
        set("exits", ([
                "north" : __DIR__"kezhan",
        	"south" : __DIR__"nanmen",
		"east" : __DIR__"huadian",
		"west" : __DIR__"xiyuanzi",
		"northeast" : __DIR__"dongjie1",
		"northwest" : __DIR__"xijie1",
	]));
	set("outdoors", "����");

	setup();
}