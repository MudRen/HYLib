// xiaolu1.c �ּ�С��
// by Xiang

inherit ROOM;

void create()
{
        set("short", "�ּ�С��");
        set("long", @LONG
������һ��С���ϣ��������������ӣ�����ɭɭ���������أ�������Ҷ
��������������������Ķ�����
LONG );
        set("exits", ([
                "south" : __DIR__"xiaolu2",
                "north" : __DIR__"houyuan",
        ]));
        set("outdoors", "wudang");
        set_temp("wayao1",1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
