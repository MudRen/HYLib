inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������Ŵ��ú�������ȣ�����������һСʯ���ţ�����
��һ��С��԰�����������������������޼����ݡ��������ȵ�
��ͷ���ſ��ţ���֪�ǲ��Ǿ���ʦү��.
LONG);

        set("exits", ([
                "west" : __DIR__"huayuan",
                "north" : __DIR__"zoulang1",
                "east"  : __DIR__"yamen",

        ]));

        set("coor/x", -250);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
