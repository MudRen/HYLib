inherit ROOM;

void create()
{
        set("short", "��ױ��");
        set("long", @LONG
������Ա�Ļ�ױ�䣬������Ա�����ž��ӻ�ױ��Ҳûע��
�������ǽ��һ����źܶ��·������ϵĹ����Ϸ��˺ü�����
�ߣ��Ǹ���߿���ȥ�ܾ��ɣ���������������Լ����档
LONG);

        set("exits", ([
                "east" : __DIR__"xiyuan1",
                        
	]));
        set("objects", ([
                __DIR__"npc/xizi1" : 2,
                __DIR__"npc/xizi2" : 1,
        ]));

        set("coor/x", -260);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
