inherit ROOM;

void create()
{
        set("short", "ʦү��");
        set("long", @LONG
һ�߽�ʦү�����ӣ��ͼ�ʦү�����������ǵ�ɢ����һЩ
�Ǻ͹Ϲ�������Ĵ�ǽ������һ�Ŵ�ĸ�ʾ��ʦү���е�����
̫ʦ���ϡ�
LONG);
        set("exits", ([
                "south" : __DIR__"zoulang1",                 
        ]));

	set("coor/x", -250);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
}

