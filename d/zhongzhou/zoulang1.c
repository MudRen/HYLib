inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�������Ŵ��ú�������ȣ�����������һСʯ���ţ�����
��һ��С��԰�����������������������޼����ݡ��������ȵ�
��ͷ���ſ��ţ���֪�ǲ��Ǿ���ʦү����
LONG);
        set("exits", ([
                "south" : __DIR__"zoulang",
                "north" : __DIR__"shiye",
                 
        ]));

        set("coor/x", -250);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}

