// Room: anbian1.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "���׽���");
        set("long", @LONG
��һ������ȥ��֮��ǰ��ŭ����ӿ��ˮ���ļ�������һ���󽭡�����ɽʯ
���������Ρ�룬�������ƣ����ǵ������׽��ϡ�������ʮ���ɸߣ���Ҫ�ߵ�
������ȴҲ��ʵ���ס� 
LONG
        );
        set("exits", ([
            "west" : __DIR__"shanlu8",
            "east" : __DIR__"jiangan",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "����");

        setup();
        replace_program(ROOM);
}
