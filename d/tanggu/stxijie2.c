inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һ����������ʯ�ֵ���������ͷ���졣������������ͨ��Ƕ���ֱ
ͨ��æ�����������ġ�������һ��С�ƹݣ��ǹ�·��Ъ�ŵĺõط�������ķ�
�Ӻ�����һ��ľ���ꡣ
LONG );
        set("exits", ([
                "north" : __DIR__"jiuguan",
		"east" : __DIR__"stxijie1",
		"west" : __DIR__"ximen",
		"south" : __DIR__"muqidian",
	]));
	set("outdoors", "����");
	setup();
}
