inherit ROOM;

void create()
{
        set("short", "�η�");
        set("long", @LONG
����һ��������ʪ���η������ϼ�ֻ����Ī������������
�Ҷ����ԡ���ֻ�������ϵ�һ��С����͸һ�����������ֵ�
�����һ�����Ҫ���衣
LONG);
        set("exits", ([
                "west" : __DIR__"xunbu",
        ]));

        set("coor/x", -210);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

