inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
��������ҵ����������ڷǳ��Ŀ����������аڷ�����
������������ǽ���Ϲ���һЩ�ֻ������������������ڴ�����
���룬���Ŷ������Դ���̸����Щʲô��
LONG);
	set("exits", ([
  		"west"  : __DIR__"miaojia_dayuan",
  		"east"  : __DIR__"miaojia_zoulang1",
  		"north" : __DIR__"miaojia_xiangfang1",
  		"south" : __DIR__"miaojia_xiangfang2",
	]));
        set("objects", ([
                CLASS_D("miao") + "/ying" : 1,
                CLASS_D("miao") + "/neng" : 1,
        ]));
	set("no_clean_up", 0);
	set("coor/x", -200);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
