inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һ����������ʯ��ֵ���������ͷ���졣���ߵľ������������
�ĳ������ˡ������в�������Ĺ��͡�������������ҩ���������εĴ����Ϸ�
д�š����ֻش����ĸ��̽���֣��������Ʈ��Ũ�ص�ҩζ���ϱ��Ǳ�������
��ϲ����ջ��
LONG );
        set("exits", ([
                "north" : __DIR__"yaofang",
		"south" : __DIR__"kedian",
		"east" : __DIR__"center",
		"west" : __DIR__"stxijie2",
	]));

	set("objects", ([
//                CLASS_D("gaibang/qigai") : 1,
        ]));

	set("outdoors", "����");
	setup();
}
