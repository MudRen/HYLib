//canchang
  

inherit ROOM;

void create()
{
	set("short", "С�Ե�");
	set("long", @LONG
����������Ҳ�����ӵİ׾ơ�һ���Ѿ����糶�ѵľ����ϻ���һ���ï޺�Ȧ������
���ơ��֡�������ͳ���һ��ҵ�ѱ�ڵİ׷������ײ��·��ż����ƾɵ�ľ���ͷ��ʣ�
ľ��������ɢɢ�÷��ż�˫ľ��ͼ������˿ڵ�С������������������⻹����.
LONG
	);
        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	

	set("exits", ([
		"west" : __DIR__"nan1",
		"east" : __DIR__"xiaochi2",
	]));
        set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));

	setup();
	replace_program(ROOM);
}

