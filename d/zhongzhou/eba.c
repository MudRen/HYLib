inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
�����������ܲ���˵��ʲô����ʵ���Ǽ�����Թ�
����һ���ڲ˳���һ��ط����ձ����ѣ����˴��ܡ�������
å��������ȥ��
LONG);

        set("exits", ([
                "north" : __DIR__"canchang",
                "enter" : __DIR__"liwu",                 
        ]));

        set("outdoors", "zhongzhou");
        set("coor/x", -220);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
