inherit ROOM;

void create()
{
        set("short", "��ʥ����");
        set("long",@LONG
����һ�����Ĵ�������һ����Լ��ʮ��ߵķ��汦��ͨ���
��ҫ�ۡ������������ơ����������������̴ľ����������һ������Ի��
�������������ؿ�������Ī������Ī��һ�������顡
LONG );
        set("outdoors", "tianlongsi");
        set("exits", ([
                "south" : __DIR__"sjt",
                "north" : __DIR__"ta1",
                "west" : __DIR__"qxg",
                "east" : __DIR__"wxt",
	]));
	set("objects",([
                __DIR__"npc/benyin" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
