inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
һ��СС����Ϣ�ң�ûʲô���������ߵ�����ֻ�����º�
����Ϣһ�¡���ͷ������С����õ�Ũ�衣
LONG);
        set("exits", ([
                "east" : __DIR__"yinghaoup",
                
        ]));
        set("coor/x", -230);
	set("coor/y", 0);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
