inherit ROOM;

void create()
{
        set("short", "��̫ү��");
        set("long", @LONG
һ�����ţ��Ϳ������������ǽ�ϵ�һ���ͻ���ɽ�����á�
����ĳ�̨�Ϸ����������������ʵĿ���һ�ź�ľ������
���ڳ�̨��ǰ�档���ſ�������һ�����ӣ����������ļҾ߶�
�Ǻ�ľ�ģ�����Ĺ��ս��������һƬ�����ĺ�⡣
LONG);
        set("exits", ([
                "south" : __DIR__"huayuan",
        ]));

        set("coor/x", -260);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

