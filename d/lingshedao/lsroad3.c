//Room:/d/lingshedao/lsroad3.c
inherit ROOM;
void create()
{
        set("short", "ɽ��С��");
        set("long", @LONG
����һ����ʯС��.·�����������д�,����Ĵ���ֱ��
����.����������ɽ����·��.����ȴģģ������ʲôҲ����
��.
LONG );
        set("exits", ([
                "westdown"    : __DIR__"lsroad1",
                "northup"  : __DIR__"shanyao",
        ]));
        set("no_clean_up",0);
        set("outdoors","lingshedao");
        setup();
        replace_program(ROOM);
}
