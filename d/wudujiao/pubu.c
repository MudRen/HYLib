// by mayue

inherit ROOM;

void create()
{
        set("short", "�ٲ�");
	set("long", @LONG
������һ��Ͽ�ȣ�ÿ���꼾ɽ�鱬��ʱ���γ���һ��εΪ׳�۵�
�ٲ���ɽ·�е��������Զ����������ˮ����ת��һ��ɽ����
ֻ��һ�������ƵĴ��ٲ��Ӷ���˫��֮�䱼�ڶ��£���ɽ�żţ�
��ˮ����ɽ���м������룬�������Ǿ��ˡ�

LONG
	);
        set("outdoors", "wudujiao");

	set("exits", ([
//              "east" : __DIR__"sl8",
//              "northwest" : __DIR__"sl4",
//              "west" : __DIR__"sl6",
//              "northeast" : __DIR__"sl5",
                "south" : __DIR__"sl3",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

