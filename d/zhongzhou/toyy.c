inherit ROOM;

void create()
{
        set("short", "��ʯ·");
        set("long", @LONG
���������ݽ�Զ��·�ϼ������������ˣ������ﲻ��Ҳ��
���������������ͨ�����ݸ������߲�Զ���Ǿ����ص������ǡ�
LONG);
        set("exits", ([
                "southwest" : "/d/xiangyang/eastgate2",
  		"north" : __DIR__"nroad",
	]));

	set("outdoors", "zhongzhou");
        set("no_clean_up", 0);
        set("coor/x", -230);
	set("coor/y", -80);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
