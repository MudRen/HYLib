inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ����Ϊ���µ�С�ݣ��ƺ���Ů�ӵľ���������������
��һ֧��¯������ɢ�������㡣��ǰ��������һ�������ģ���
��̴��ľ�Ĵ�������ĵ����Ž��г񱻡�
LONG);
	set("exits", ([
  		"south" : __DIR__"miaojia_zoulang1",
	]));
	set("no_clean_up", 0);
        set("objects", ([
                CLASS_D("miao") + "/lan" : 1,
        ]));
	set("coor/x", -190);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
