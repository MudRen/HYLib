// Room: songlin4.c
// By River 98/12
inherit ROOM;
void create()
{
        set("short", "������");
	set("long", @LONG
����ǰ��Ȼһ�ڣ������У�ֻ������ǰ�󣬵�����������ǵص������֡�
��ʮ�ɸߵĴ���������һ�飬��ʵ��֦Ҷ��һ�����ɡ��������գ���������
��˿��Ҳ�ޡ��߰Ѻ��������ڵ��ϣ�һ�Ų���ȥ������β����������ƺ���
ʧ�˷�����ûͷ��Ӭ�㵽���Ҵ���
LONG
	);
	set("exits", ([ 
	    "south" : __DIR__"songlin"+(1+random(6)),
            "north" : __FILE__,
            "east" : __DIR__"songlin"+(1+random(6)),
            "west" : __DIR__"songlin"+(1+random(6)),
        ]));
        set("outdoors", "����");
	setup();
        replace_program(ROOM);
}
