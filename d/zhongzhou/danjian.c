inherit ROOM;

void create()
{
        set("short", "ѻƬ��");
        set("long", @LONG
����ѻƬ���ڵ�һ��С���䣬�м��������ڴ��齫������
ȥ���ѻƬ�ݾ������ǿ��ġ�
LONG);
        set("exits", ([
                 "west" : __DIR__"yanguan",                 
        ]));

        set("coor/x", -230);
	set("coor/y", -30);
	set("coor/z", -10);
	setup();
        replace_program(ROOM);
}
