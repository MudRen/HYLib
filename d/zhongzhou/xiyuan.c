inherit ROOM;

void create()
{
        set("short", "ϷԺ");
        set("long", @LONG
����ϷԺ�Ĵ���������̨�ϳ�Ϸ�����Ļ��ء����վ����
�����������д�����������ǰ����֪Ҫ����ʲô�¡�
LONG);
        set("exits", ([
                "east" : __DIR__"wendingbei2",
                "south" : __DIR__"liangongfang",
                "west" : __DIR__"xiyuan1",
                "north" : __DIR__"sushe",
        ]));

        set("objects",([
                "/d/beijing/npc/guanzhong" : 3,
        ]));

        set("coor/x", -240);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
}
